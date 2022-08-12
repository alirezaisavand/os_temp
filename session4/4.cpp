#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    fork();
    printf("after first fork.\n");
    fork();
    printf("after second fork.\n");
    fork();
    printf("after third fork.\n");
    return 0;
}
