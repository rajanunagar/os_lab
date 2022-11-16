#include <unistd.h>
#include <stdio.h>
int main(){

	int total_bytes = write(1,"hello",5);
	printf("total bytes :- ");
	printf(total_bytes);
	return 0;
}
