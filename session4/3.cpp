include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    int ret = fork();
    if (ret == 0) {
        printf("I am the child.\n");
        return 23;
    } else {
        printf("I am the parent.\n");
        int rc = 0;
        wait(&rc);
        printf("return code is %d\n", WEXITSTATUS(rc));
    }
    return 0;
}
