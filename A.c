/*Write a C program that illustrates suspending and resuming processes using signals.*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void suspend_handler(int sig) {
    printf("Process suspended. Waiting for SIGCONT to resume...\n");
    pause();
}

void resume_handler(int sig) {
    printf("Process resumed.\n");
}

int main() {
    signal(SIGTSTP, suspend_handler);
    signal(SIGCONT, resume_handler);

    while (1) {
        printf("Running... Press Ctrl+Z to suspend.\n");
        sleep(2);
    }

    return 0;
}

/*Running... Press Ctrl+Z to suspend.
Process suspended. Waiting for SIGCONT to resume...
Process resumed.
Running... Press Ctrl+Z to suspend.
*/