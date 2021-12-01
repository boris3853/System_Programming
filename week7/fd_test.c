#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *st = "1: This is stdout\n";
char *st2 = "2: This is stdout2\n";

int main(){
	write(1, st2, 5);
	write(1, st, strlen(st));
	write(2, "This is stderr\n", 46);

	return 0;
}
