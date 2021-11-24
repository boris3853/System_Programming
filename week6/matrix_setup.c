#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int **matrix1;
int **matrix2;
int **result_matrix;

void set_arr(int num){
	srand(time(NULL));

	// 동적 배열 할당
	matrix1 = (int **)malloc(sizeof(int *)*num);
	matrix2 = (int **)malloc(sizeof(int *)*num);
	result_matrix = (int **)malloc(sizeof(int *)*num);
	for(int i=0;i<num;++i){
		matrix1[i] = (int *)malloc(sizeof(int)*num);
		matrix2[i] = (int *)malloc(sizeof(int)*num);
		result_matrix[i] = (int *)malloc(sizeof(int)*num);
	}

	// 배열에 각 요소값 할당: Matrix1, Matrix2
	for(int i=0;i<num;++i){
		for(int j=0;j<num;++j){
			matrix1[i][j] = rand() % 10;
			matrix2[i][j] = rand() % 10;
			result_matrix[i][j] = 0;
		}
	}
}

void free_arr(int num){

	// 동적 배열 해제
	for(int i=0;i<num;++i){
		free(matrix1[i]);
		free(matrix2[i]);
		free(result_matrix[i]);
	}
	free(matrix1);
	free(matrix2);
	free(result_matrix);
}
