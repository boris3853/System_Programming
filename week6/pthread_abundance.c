#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 6

void *thread_function(void *arg);

int main(){
	int res;
	pthread_t thread[NUM_THREADS];
	void *thread_result;
	int t_num;

	for(t_num = 0; t_num < NUM_THREADS; ++t_num){
		//res = pthread_create(&thread[t_num], NULL, thread_function, (void *)&t_num);
		res = pthread_create(&thread[t_num], NULL, thread_function, (void *)t_num);
		if(res != 0){
			perror("Thread creation failed");
			exit(1);
		}
		//sleep(1);
	}

	puts("Waiting for threads to finish...");

	for(t_num = NUM_THREADS - 1; t_num >= 0; --t_num){
		res = pthread_join(thread[t_num], &thread_result);
		if(res == 0) puts("picked up a thread");
		else perror("pthread_join failed");
	}
	puts("All done");
	exit(0);
}

void *thread_function(void *arg){
	//int num = *(int *)arg;
	int num = (int)arg;
	int rand_num;

	printf("thread_function is running. Argument was %d\n", num);
	rand_num = 1 + (int)(9.0*rand()/(RAND_MAX+1.0));
	sleep(rand_num);
	printf("Bye from %d\n", num);
	pthread_exit(NULL);
}
