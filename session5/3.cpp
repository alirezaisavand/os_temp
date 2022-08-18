#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(){
    return;
}

int main() {
    signal(SIGALRM, handler);
    alarm (5);
    printf ("Looping forever . . . \n");
    pause();
    printf("This line should never be executed\n");
    return 0;
}
