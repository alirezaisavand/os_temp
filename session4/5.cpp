#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    int pid = fork();
    if (pid == 0) {
        for (int i=1; i<=100; i++)
            printf("%d\n", i);
        exit(0);
    } else {
        wait(NULL);
        printf("child execution is finished.\n");
    }
    return 0;
}
