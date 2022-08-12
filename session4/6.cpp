#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int pid = fork();
    if (pid == 0) {
        printf("child's parent PID:%d\n", getppid());
        sleep(2);
        printf("child's parent PID:%d\n", getppid());
        exit(0);
    } else {
        printf("parent PID:%d\n", getpid());
        sleep(1);
        printf("parent with PID %d finished.\n", getpid());
    }
    return 0;
}
