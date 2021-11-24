#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern int **matrix1;
extern int **matrix2;
extern int **result_matrix;

extern void set_arr(int);
extern void free_arr(int);
void single_calc(int);

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
	}
*/	

	free_arr(SIZE);	
}

void single_calc(int SZ){
	for(int i=0;i<SZ;++i){
		for(int j=0;j<SZ;++j){
			for(int k=0;k<SZ;++k)
				 result_matrix[i][j] += (matrix1[i][k] * matrix2[k][j]);
		}
	}
}
