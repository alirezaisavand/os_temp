#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_pid() {
	printf("thread's pid: %d\n", getpid());
}

int main(){
	pthread_t the_thread;
	pthread_create(&the_thread, NULL, thread_pid(), NULL);
	printf("the main pid is:%d\n", getpid());
	pthread_join(the_thread, NULL);
	pthread_exit(0);
	return 0;
}	
