#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int pid = fork();
    if (pid == 0) {
            execl("/bin/ls", "ls", "-g", "-h");
    } else {
            wait(NULL);
    }
    return 0;
}
