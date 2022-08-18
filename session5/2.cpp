#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int fd[2];
    if (pipe(fd) < 0) {
        printf("couldn't pipe\n");
        return 1;
    }
    int pid = fork();
    if (pid < 0) {
        printf("couldn't fork\n");
        return 1;
    }
    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        execl("/usr/bin/wc", "wc", (char*) NULL);
    } else {
        close(fd[0]);
        dup2(fd[1], 1);
        execl("/bin/ls", "ls");
    }
    return 0;
}
