/**
 * File: pong.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 *  - installs the signal handlers
 *  - waits
 *  - upon receiving a ping waits one to two seconds then sends a 'pong' in response
 *  - exits upon receiving a SIGNINT
 */

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include "pingpong.h"
#include <unistd.h>
/**
 * @brief responds to a ping with a pong, if 10 volleys have been completed, exits
 */
void ping_handler(int signo, siginfo_t *info, void *context) {
    __pid_t ping_process = info->si_pid;
    printf("Ping received from %d \n", ping_process);
    ping(ping_process);
}

/**
 * @brief exits on SIGINT
 */
void sigint_handler(int signo, siginfo_t *info, void *context) {
    puts("SIGINT received");
    puts("Exiting pong");
    exit(0);
}

int main(int argc, char *argv[]) {
    srand(time(NULL) / 2);

    // creates pong handler
    struct sigaction ping_action;
    ping_action.sa_sigaction = &ping_handler;
    ping_action.sa_flags = SA_SIGINFO;

    // sets handler for the pong
    sigaction(SIGUSR1, &ping_action, NULL);
    
    // creates sigint handler
    struct sigaction sigint_action;
    sigint_action.sa_sigaction = &sigint_handler;
    sigint_action.sa_flags = SA_SIGINFO;

    // sets handler for SIGINT
    sigaction(SIGINT, &sigint_action, NULL);

    // waits forever
    while (1) {
        sleep(1);
    }
}