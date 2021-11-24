#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#define MAX 1000

extern int **matrix1;
extern int **matrix2;
extern int **result_matrix;

extern void set_arr(int);
extern void free_arr(int);
void *pthread_func(void *arg);

int SIZE, THR_NUM;
int step=0;

int main(int argc, char **argv){
	SIZE = atoi(argv[1]);
	THR_NUM = atoi(argv[2]);

	pthread_t thread[SIZE];
	set_arr(SIZE);

	for(int i=0;i<THR_NUM;++i)	
		pthread_create(&thread[i], NULL, pthread_func, NULL);

	for(int i=0;i<THR_NUM;++i)
		pthread_join(thread[i], NULL);
	

	/*
	// 배열 출력 테스트
	for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j){
			printf("%d ", result_matrix[i][j]);
		}
		puts("");
	}
	*/


	free_arr(SIZE);
}

void *pthread_func(void *arg){
	 for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j){
			for(int k=0;k<SIZE;k+=THR_NUM){
				result_matrix[i][j] += (matrix1[i][step+k] * matrix2[step+k][j]);
			}
		}
	}
	step++;
	pthread_exit(NULL);
}
