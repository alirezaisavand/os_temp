#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    return;
}

int main() {
    signal(SIGINT, handler);
    printf ("interrupt to continue . . . \n");
    pause();
    printf ("waiting for second time interruption . . . \n");
    pause();
    printf("program ended.\n");
    return 0;
}
