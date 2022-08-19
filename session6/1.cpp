#include<stdio.h>
#include<stdlib.h>

struct MyStruct {
	int a;
	int b;
	char name[20];
};

int main(){
	struct MyStruct *mystruct = (MyStruct *)malloc(sizeof(struct MyStruct));
	
	mystruct-> a = 1;
	mystruct-> b = 2;
	int i;
	for(i = 0; i < 19; i ++){
		mystruct->name[i] = 'I';
	} 
	
	mystruct->name[19] = '\0';
	printf("%d\t%d\t%s\n", mystruct->a, mystruct->b, mystruct->name);
	
	free(mystruct);
	return 0;
}
