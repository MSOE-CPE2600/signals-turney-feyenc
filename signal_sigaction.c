/**
 * File: signal_sigaction.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 *  - registers a signal handler for SIGUSR1
 *      - prints the pid of the sender
 *      - may be sent using `kill -SIGUSR1 <pid>`
 *  - loops forever
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signo, siginfo_t *info, void *context) {
    printf("signal received from: %d\n", info->si_pid);
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