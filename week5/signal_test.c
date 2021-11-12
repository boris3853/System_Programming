#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int num = 0;

void reset(int sig){
	num = 0;
}

void quit(int sig){
	signal(SIGQUIT, SIG_DFL);
	puts("press ^\\ to quit");
}

int main(){
	signal(SIGINT, reset);
	signal(SIGQUIT, quit);
	
	while(1){
		printf("counting: %d\n", num++);
		sleep(1);
	}

	return 0;
}
