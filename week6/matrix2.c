#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>


int **matrix1;
int **matrix2;
int **result_matrix;

void set_arr(int);
void free_arr(int);
void *pthread_func(void *arg);


int main(int argc, char **argv){
	int SIZE = atoi(argv[1]);

	set_arr(SIZE);
	single_calc(SIZE);

	/*
	// 배열 출력 테스트
	for(int i=0;i<SIZE;++i){
		for(int j=0;j<SIZE;++j){
			printf("%d ", result_matrix[i][j]);
		}
		puts("");
	}*/

	free_arr(SIZE);
}

void *pthread_func(void *arg){

}
