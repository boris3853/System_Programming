#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

int main(){
	char buf[MAX];
	char *st = "Input: ";

	write(1, st, strlen(st));
	int n = read(0, buf, MAX);
	write(1, buf, n);
	
	return 0;
}
