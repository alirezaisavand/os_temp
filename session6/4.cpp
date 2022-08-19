#include <stdio.h>
#include <stdlib.h>

int f(int ind){
	if (ind == 0) return 0;
	int i = 0;
	printf("%p", &i);
	printf("\n");
	return f(ind - 1);
}

int main(){
	f(20);
	return 0;
}
