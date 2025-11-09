

#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>

void ping(__pid_t pid) {
    // waits for 1-2 seconds
    struct timespec duration;
    duration.tv_sec = 1;
    duration.tv_nsec = rand() % 1000000000;
    nanosleep(&duration, NULL);

    printf("\007Hitting ball to %d\n", pid);

    // sends a ping signal
    kill(pid, SIGUSR1);
}