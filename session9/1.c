#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *read_file = fopen("/proc/interrupts", "r");
	if (read_file == NULL){
		printf("ERROR! Could not open this file");
		exit(-1);
	}
	
	int buffer_length = 200;
	char line_buffer[buffer_length];
	
	while (fgets(line_buffer, buffer_length, read_file)){
		printf("%s", line_buffer);
	}
	
	fclose(read_file);
	
	return 0;
}
