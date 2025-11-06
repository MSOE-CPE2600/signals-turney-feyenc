/**
 * File: send_signal.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 *  - sends a SIGUSR1 signal to all of the pids listed in the command line
 */

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // seeds the random number generator
        srand(time(NULL));

        for (int i = 1; i < argc; i++) {
            // gets the pid
            __pid_t pid = atoi(argv[i]);
            
            // logs and skips the pid if it is invalid
            if (!pid) {
                printf("invalid pid: %s\n", argv[i]);
                continue;
            }

            // gets a random number
            int val = rand();

            // creates the sinal value
            union sigval signal_value;
            signal_value.sival_int = val;

            // logs and sends the signal
            printf("sending: %d to %d\n", val, pid);
            sigqueue(pid, SIGUSR1, signal_value);
        }
    } else {
        puts("add pid arguments");
    }
}