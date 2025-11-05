/**
 * File: signal_alarm.c
 * Modified by: Charles Feyen
 * 
 * Brief summary of program:
 * sets a 5 second alarm
 * when the alarm goes off, prints "alarmed"
 * ends by printing "overslept"
 */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void alarm_handler(int signo, siginfo_t *info, void *context) {
    puts("alarmed");
}

int main(void) {
    // sets the signal handler
    struct sigaction alarm_action;
    alarm_action.sa_sigaction = &alarm_handler;
    sigaction(SIGALRM, &alarm_action, NULL);

    alarm(5);
    puts("alarm set");
    sleep(10); // sleep gets cut short
    puts("overslept");
}