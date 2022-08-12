#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    int tmp = 0;
    if (ret == 0) {
        printf("tmp value 1 in child process: %d\n", tmp);
        tmp += 10;
        printf("tmp value 2 in child process: %d\n", tmp);
        return 23;
    } else {
        int rc = 0;
        wait(&rc);
        printf("tmp value 1 in parent process: %d\n", tmp);
        tmp += 10;
        printf("tmp value 2 in parent process: %d\n", tmp);
        printf("return code is %d\n", WEXITSTATUS(rc));
    }
    return 0;
}
