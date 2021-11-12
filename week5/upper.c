#include <stdio.h>
#include <stdlib.h>

int main(){
	int ch;
	while((ch = getchar()) != EOF){
		if(ch >= 'a' && ch <= 'z')
			putchar(ch - 'a' + 'A');
		else putchar(ch);
	}
	return 0;
}
