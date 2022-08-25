#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct thdata{
	int th_num;
	char msg[50];
} stdata;

void *func(void *info){
	stdata the_struct = *((stdata *)info);
	printf("Thread ID: %d, Message: %s\n", the_struct.th_num, the_struct.msg);
}

int main(){
	stdata struct1;
	stdata struct2;
	
	pthread_t thread1;
	pthread_t thread2;
	
	
	struct1 = (stdata) {.th_num = 1, .msg = "Alireza Isavand - 97110788"};
	struct2 = (stdata) {.th_num = 2, .msg = "Mehregan Mohseni - 97107245"};
	
	pthread_create(&thread1, NULL, func, &struct1);
	pthread_create(&thread2, NULL, func, &struct2);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	pthread_exit(0);
	return 0;
}
