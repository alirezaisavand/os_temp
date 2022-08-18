#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    char * msg="Hello World!";
    int msg_len = strlen(msg)+1;
    int fd[2];
    if (pipe(fd) < 0) {
        printf("couldn't pipe\n");
        return 1;
    }
    int pid = fork();
    if (pid < 0) {
        printf("couldn't fork\n");
        return 1;
    } else if (pid == 0) {
        close(fd[1]);
        char buf[msg_len];
        read(fd[0], buf, msg_len);
        printf("%s\n", buf);
        exit(0);
    } else {
        close(fd[0]);
        write(fd[1], msg, msg_len);
        wait(NULL);
    }
    return 0;
}
