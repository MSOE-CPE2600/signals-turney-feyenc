/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Charles Feyen
 * 
 * Brief summary of modifications:
 *  - segfaults by dereferencing a null pointer
 *  - handles the signal
 *  - segfaults
 */


#include <stdio.h>
#include <signal.h>

void segfault_handler(int signo, siginfo_t *info, void *context) {
    puts("\"It's segfaultin' time\" - your computer");
}

int main (int argc, char* argv[]) {
    struct sigaction segfault_action;
    segfault_action.sa_sigaction = &segfault_handler;
    sigaction(SIGSEGV, &segfault_action, NULL);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);
    // segfaults, gets handles,
    // segfaults anyway because the program resumes mid segfault

    // Return to exit the program
    return 0;
}