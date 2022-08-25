#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* sum(void *n) {
	int int_n = *(int *) n;
	int sum = (int_n * (int_n + 1) / 2) - 1;
	printf("Sum of 2 to %d : %d\n", int_n, sum);
}

int main(){
	printf("Enter your number: ");
	int num;
	scanf("%d", &num);
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_t thread;
	
	pthread_create(&thread, &attr, sum, &num);
	pthread_join(thread, NULL);
	pthread_exit(0);
	return 0;
}	
