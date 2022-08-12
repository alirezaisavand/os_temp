#include <stdio.h>
#include <unistd.h>

int main(){
   printf("current process id: %d\n", getpid());
   return 0;
}
