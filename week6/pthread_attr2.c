#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[] = "Hello World";
int thread_finished = 0;

int main(){
	int res;
	pthread_t thread;

	res = pthread_create(&thread, NULL, thread_function, (void *)message);
	if(res != 0){
		perror("Thread creation failed");
		exit(1);
	}


	res = pthread_join(thread, NULL);
	while(!thread_finished){
		printf("Waiting for thread to say it's finished..\n");
		sleep(1);
	}

	puts("Other thread finished, bye!");
	exit(0);
}

void *thread_function(void *arg){
	printf("thread_function is running. Argument was %s\n", (char *)arg);
	sleep(4);
	puts("Second thread setting finished flag, and exiting now");
	thread_finished = 1;
	pthread_exit(NULL);
}
