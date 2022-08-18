#include <stdio.h>
#include <unistd.h>

int main(){
   printf("parent process id: %d\n", getppid());
   return 0;
}
