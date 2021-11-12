#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);

	while(1){
		puts("hello");
		sleep(1);
	}
	return 0;
}
