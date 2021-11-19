#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define LOOP_COUNTER 100

void *thread_function1(void *arg);
void *thread_function2(void *arg);

int counter; // shared variable
sem_t bin_sem, bin_sem1, bin_sem2;

int main(){
	int res1, res2;
	pthread_t thread1, thread2;
	void *thread_result;

	res1 = sem_init(&bin_sem, 0, 1);
	// 세마포어 bin_sem 생성 후 1로 할당
	if(res1 != 0){
		perror("Semaphore initialization failed");
		exit(1);
	}
	
	res1 = sem_init(&bin_sem1, 0, 1);
	res2 = sem_init(&bin_sem2, 0, 0);
	// 세마포어 bin_sem1 생성 후 1로 할당
	// 세마포어 bin_sem2 생성 후 0으로 할당
	
	if(res1 != 0 | res2 != 0){
		perror("Semaphore initialization failed");
		exit(1);
	}

	res1 = pthread_create(&thread1, NULL, thread_function1, NULL);
	res2 = pthread_create(&thread2, NULL, thread_function2, NULL);
	// 쓰레드 각각 생성
	
	if(res1 != 0 || res2 != 0){
		perror("Thread Creation failed");
		exit(1);
	}
	
	res1 = pthread_join(thread1, &thread_result);
	res2 = pthread_join(thread2, &thread_result);
	// 쓰레드 종료

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
		sem_wait(&bin_sem1); // bin_sem1 : 0이면 아래코드 실행
		sem_wait(&bin_sem); // bin_sem : 0이면 아래코드 실행
		counter++;
		sem_post(&bin_sem); // bin_sem : 0으로 할당
		printf("Thread1_counter: %d\n", counter);
		sem_post(&bin_sem2); // bin_sem2 : 0으로 할당 -> 쓰레드2 작동
	}
	pthread_exit("Thread1 EXIT");
}

void *thread_function2(void *arg){
	int i=0;
	for(i=0;i<LOOP_COUNTER;++i){
		sem_wait(&bin_sem2); // bin_sem2 : 0이면 아래코드 실행
		sem_wait(&bin_sem); // bin_sem : 0이면 아래코드 실행
		counter--;
		sem_post(&bin_sem); // bin_sem : 0으로 할당
		printf("Thread2_counter: %d\n", counter);
		sem_post(&bin_sem1); // bin_sem1 : 0으로 할당 -> 쓰레드1 작동
	}
	pthread_exit("Thread2 EXIT");
}
