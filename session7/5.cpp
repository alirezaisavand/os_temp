#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *hello_world(void *id){
	int thread_id = *((int *)id);
	printf("hello world! in thread %d\n", thread_id);
	pthread_exit(0);
}

int main(){
	pthread_t threads[5];
	for(int i = 0; i < 5; i ++){
		pthread_create(&threads[i], NULL, hello_world, &i);
		pthread_join(threads[i], NULL);
	}
	return 0;
}
