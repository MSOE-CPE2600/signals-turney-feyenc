/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Charles Feyen
 * 
 * Brief summary of modifications:
 *  - added comment to describe how to send SIGINT
 *  - removed exit on line 26, now must be killed with kill -SIGKILL <pid>
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    // can be triggered by Ctrl-C or kill -SIGINT <pid> (where <pid> is the process id)
    printf("Received a signal\n");
    // exit(1);
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}