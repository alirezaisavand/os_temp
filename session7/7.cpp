#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int global_param = 0;

void* kid(void* param) {
	int local_param;
	printf("Thread %d, pid %d, addresses: &global: %X, &local: &X \n", 
	         pthread_self(), getpid(), &global_param , &local_param);
	global_param++;
	printf("In Thread %d, incremented global parameter=%d\n", 
	          pthread_self(), global_param);
	pthread_exit(0);
}

int main(){
	global_param = 0;
	
	pthread_t thread1;
	pthread_t thread2;
	
	pthread_create(&thread1, NULL, kid, NULL);
	pthread_create(&thread2, NULL, kid, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("global param: %d\n", global_param);
	
	return 0;
}
