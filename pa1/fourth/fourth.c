//#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

int main(int argc, char** argv) {

	FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }


	int row, column;
	//printf("enter size1 and size2 \n");
	//scanf("%d %d", &row, &column);
  
	fscanf(fp,"%d %d",&row, &column);
	/*---------------------------------------
	//creating array of pointers for matrix 1
	-----------------------------------------*/
	int ** matrix1;
	matrix1 = (int**) malloc(row * sizeof(int *)); //space for all rows has been created
	
	//creating space for elements pointer is pointing to
	for(int i = 0; i < row; i++){
		matrix1[i] = (int *) malloc(column * sizeof(int));
	}
	
	//setting values for matrix;
	int element;
	for(int i = 0; i < row; i++){
		for(int j = 0; j< column; j++){
			fscanf(fp,"%d", &element);
			matrix1[i][j] = element;
			//matrix1[i][j]= 0;
		}
	}

	/*----------------------------------------
	  creating array of pointers for matrix 2
	  ----------------------------------------*/
	int row2, column2;
	fscanf(fp, "%d %d",&row2, &column2);
	
	int ** matrix2;
	matrix2 = (int**) malloc(row2 * sizeof(int *));

	for(int i = 0; i < row2; i++) {
		matrix2[i] = (int *) malloc(column2 * sizeof(int));
	}

	//int element;
	for(int i = 0; i < row2; i++){
		for(int j = 0; j < column2; j++){
			fscanf(fp, "%d", &element);
			matrix2[i][j] = element;
		}
	}

	//printing values in matrix1
	/*printf("\nMatrix1:\n");
	printf("%d_x_%d:\n", row, column);
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			printf("%d ",matrix1[i][j]);
		}
		printf("\n");
	}
	*/
	
	//printing values in matrix2
	/*printf("\nMatrix2:\n");
	printf("%d_x_%d:\n", row2, column2);
	for(int i = 0; i < row2; i++) {
		for(int j = 0; j < column2; j++) {
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	if(column != row2) {
		printf("bad-matrices\n");
		return 0;
	}
	//printf("This is a good matrix, program will continue to run\n\n");

	//MULTIPLICATION
	/*----------------------------------------------------------------------
	  creating an array of pointers for  result matrix with size row column2
	  ----------------------------------------------------------------------*/
	
	//creating array of pointers for result
	int ** result;
	result = (int**) malloc(row * sizeof(int *));

	//creating space for array each pointer is pointing to
	for(int i = 0; i < row; i++) {
		result[i] = (int *) malloc(column2 * sizeof(int));
	}

	//Multiplication: setting values in result
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column2; j++) {
			for(int k = 0; k < column; k++){
				result[i][j] += matrix1[i][k] * matrix2[k][j];
				//printf("result[%d][%d] now contains %d\n",i,j,result[i][j]);
			}
		}
	}		

	//printing values in result
	//printf("Result: \n");
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column2; j++) {
			printf("%d", result[i][j]);
			if(column2 - j != 1) {
				printf("\t");
			}
		}
		printf("\n");
	}
	//printf("\n");


	//FREEING
	for(int i = 0; i< row; i++){
		free(matrix1[i]);
	}

	for(int i = 0; i< row2; i++) {
		free(matrix2[i]);
	}
      
	free(matrix1);
	free(matrix2);

	return 0;
}
