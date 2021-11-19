#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg);

int main(){
	int res;
	pthread_t thread;
	void *thread_result;

	res = pthread_create(&thread, NULL, thread_function, NULL); // 쓰레드 생성
	if(res != 0){
		perror("Thread creation failed");
		exit(1);
	}

	sleep(3);
	
	puts("Canceling thread...");

	res = pthread_cancel(thread);	// 쓰레드 중지
	if(res != 0){
		perror("Thread cancelation failed");
		exit(1);
	}

	puts("Waiting for thread to finish...");
	
	res = pthread_join(thread, &thread_result); // 쓰레드 종료
	if(res != 0){
		perror("Thread join failed");
		exit(1);
	}

	exit(0);
}

void *thread_function(void *arg){
	int i, res;
	
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); // CANCEL_ENABLE 설정
	if(res != 0){
		perror("Thread pthread_setcancelstate failed");
		exit(1);
	}

	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL); // CANCEL_DEFERRED 설정 : 세마포어나 뮤텍스 지점 벗어나면 종료
	if(res != 0){
		perror("Thread pthread_setcanceltype failed");
		exit(1);
	}

	puts("thread_function is running");
	for(i=0;i<10;++i){
		printf("Thread is still running (%d)...\n", i);
		sleep(1);
	}
	pthread_exit("Exiting pthread");
}

