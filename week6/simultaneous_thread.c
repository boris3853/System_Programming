#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define LOOP_COUNTER 10000

void *thread_function1(void *arg);
void *thread_function2(void *arg);

int counter; // shared variable

int main(){
	int res1, res2;
	pthread_t thread1, thread2;
	void *thread_result;

	res1 = pthread_create(&thread1, NULL, thread_function1, NULL);
	res2 = pthread_create(&thread2, NULL, thread_function2, NULL);
	// thread1 -> thread_function1(counter++)
	// thread2 -> thread_function2(counter--) 실행
	
	if(res1 != 0 || res2 != 0){
		perror("Thread Creation failed");
		exit(1);
	}
	
	res1 = pthread_join(thread1, &thread_result);
	res2 = pthread_join(thread2, &thread_result);
	// thread1, thread2 종료

	if(res1 != 0 || res2 != 0){
		perror("Thread Join failed");
		exit(1);
	}

	printf("final Counter: %d\n", counter);
	
	exit(0);
}

void *thread_function1(void *arg){
	int i = 0;
	for(i=0;i<LOOP_COUNTER;++i){
		counter++;
		printf("Thread1_counter: %d\n", counter);
	}
	pthread_exit("Thread1 EXIT");
}

void *thread_function2(void *arg){
	int i=0;
	for(i=0;i<LOOP_COUNTER;++i){
		counter--;
		printf("Thread2_counter: %d\n", counter);
	}
	pthread_exit("Thread2 EXIT");
}