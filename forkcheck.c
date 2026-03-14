#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        // Child process
        printf("I am child, my PID is %d\n", getpid());
        printf("My parent PID is: %d\n", getppid());
        sleep(2); // Keep child alive for verification
    } else if (pid > 0) {
        // Parent process
        printf("I am parent, my PID is %d\n", getpid());
        wait(NULL); // Wait for child to finish
    } else {
        // Error case
        perror("fork failed");
        exit(1);
    }
    return 0;
}
