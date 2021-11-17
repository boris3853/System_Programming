#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct data{
	int num;
	char msg[10];
}st;


void *thread_func(void *arg);
char *msg = "hello world";
int final_result;

int main(){
	st st_data[10];
	int res;
	pthread_t thread[10];
	void *thread_result[10];

	for(int i=0;i<10;++i){
		st_data[i].num = i;
		strcpy(st_data[i].msg, msg);
		res = pthread_create(&thread[i], NULL, thread_func, (void *)&st_data[i]);
		if(res != 0){
			perror("Thread creation failed");
			exit(1);
		}
	}
	puts("Waiting for thread to finish..");
	for(int i=0;i<10;++i){
		res = pthread_join(thread[i], &thread_result[i]);
		if(res != 0){
			perror("Thread join failed");
			exit(1);
		}
	}
	printf("final_result = %d\n", final_result);
}

void *thread_func(void *arg){
	st *tmp = (st *)arg;
	printf("thread_function is running. int: %d, string: %s\n", tmp->num, tmp->msg);
	final_result = tmp->num;
	pthread_exit("Thank you for the CPU time");
}
