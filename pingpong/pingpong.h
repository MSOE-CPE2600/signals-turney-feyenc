
#include <signal.h>

/**
 * @brief Waits for 1 to 2 seconds, then sends a SIGUSR1
 * @param pid the pid to send the signal to
 */
void ping(__pid_t pid);