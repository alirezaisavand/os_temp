#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int os_lab = 0;

void* change_var() {
	os_lab = 2;
	printf("os_lab inside the thread: %d\n", os_lab);
}

int main(){
	os_lab = 1;
	pthread_t the_thread;
	printf("os_lab before thread: %d\n", os_lab);
	pthread_create(&the_thread, NULL, change_var, NULL);
	pthread_join(the_thread, NULL);
	printf("os_lab after thread: %d\n", os_lab);
	os_lab = 3;
	printf("os_lab in the main(): %d\n", os_lab);
	pthread_exit(0);
	return 0;
}	
