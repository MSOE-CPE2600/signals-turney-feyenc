/**
 * File: recv_signal.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 *  - registers a signal handler for SIGUSR1
 *      - prints the value received
 *  - loops forever
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo, siginfo_t *info, void *context) {
    printf("signal received: %d\n", info->si_value.sival_int);
}

int main (int argc, char* argv[]) {
    // creates sigaction struct
    struct sigaction signal_action;
    signal_action.sa_sigaction = &signal_handler;
    signal_action.sa_flags = SA_SIGINFO;

    // sets handler for SIGUSR1
    sigaction(SIGUSR1, &signal_action, NULL);

    // loop forever
    while (1) {
        sleep(1);
    }
}