/**
 * File: ping.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 *  - installs the signal handlers
 *  - sends a ping
 *  - upon receiving a 'pong' waits one to two seconds then sends a ping in response
 *  - upon receiving a SIGNINT, echos the SIGINT to the 'pong' process then exits
 */

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include "pingpong.h"
#include <unistd.h>

__pid_t pong_process;
int volleys = 0;

/**
 * @brief responds to a pong with a ping, if 10 volleys have been completed, exits
 */
void pong_handler(int signo, siginfo_t *info, void *context) {
    pong_process = info->si_pid;
    printf("Pong received from %d \n", pong_process);

    // exits after 10 volleys
    if (++volleys >= 10) {
        puts("10 volleys complete, exiting");
        kill(pong_process, SIGINT);
        sleep(1);
        puts("Exiting ping");
        exit(0);
    }

    ping(pong_process);
}

/**
 * @brief echoes a SIGINT to the pong processes
 */
void sigint_handler(int signo, siginfo_t *info, void *context) {
    puts("SIGINT received");

    puts("Echoing SIGINT to pong");
    kill(pong_process, SIGINT);

    // waits for the next ping/pong to finish
    // (makes the terminal look nicer)
    sleep(2);

    puts("Exiting ping");
    exit(0);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    // ensures a valid pong process
    if (argc < 2) {
        puts("No pong pid provided");
        return 1;
    }

    pong_process = atoi(argv[1]);

    if (!pong_process) {
        puts("Invalid pong pid");
        return 1;
    }

    // creates pong handler
    struct sigaction pong_action;
    pong_action.sa_sigaction = &pong_handler;
    pong_action.sa_flags = SA_SIGINFO;

    // sets handler for the pong
    sigaction(SIGUSR1, &pong_action, NULL);
    
    // creates sigint handler
    struct sigaction sigint_action;
    sigint_action.sa_sigaction = &sigint_handler;
    sigint_action.sa_flags = SA_SIGINFO;

    // sets handler for SIGINT
    sigaction(SIGINT, &sigint_action, NULL);

    // pings the pong process
    puts("Serving");
    ping(pong_process);

    // waits forever
    while (1) {
        sleep(1);
    }
}