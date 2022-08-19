#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int *a, *b;
	//part1: before malloc
	a = sbrk(0);
	printf("before malloc: %p\n", a);
	q = malloc(100);
	//part2: after malloc
	a = sbrk(0);
	printf("after malloc: %p\n", a);
	return 0;
}
