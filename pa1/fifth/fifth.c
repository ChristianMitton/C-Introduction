#include <stdio.h>
#include <stdlib.h>

int checkForDuplicates(int target, int targetRow, int targetCol, int size, int** matrix) {
	//printf("checking for dups of %d\n", target);
	for(int i = 0; i< size; i++){
		for(int j = 0; j< size; j++){
			if(matrix[i][j] == target) {
				if(i != targetRow || j != targetCol) {
	    				return -1;
				}
	   		}
		}
         }

	return 0;
}

int main(int argc, char ** argv) {
  
        FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }

	
	int size;
	//printf("enter size1 and size2 \n");
	//scanf("%d %d", &row, &column);
  
	fscanf(fp,"%d",&size);
	//printf("rowxcol: %d\n", rowxcol);
	
	/*---------------------------------------
	//creating array of pointers for matrix 1
	-----------------------------------------*/
	int ** matrix1;
	matrix1 = (int**) malloc(size * sizeof(int *)); //space for all rows has been created
	
	//creating space for elements pointer is pointing to
	for(int i = 0; i < size; i++){
		matrix1[i] = (int *) malloc(size * sizeof(int));
	}
	
	//setting values for matrix;
	int element;
	for(int i = 0; i < size; i++){
		for(int j = 0; j< size; j++){
			fscanf(fp,"%d", &element);
			matrix1[i][j] = element;
			//matrix1[i][j]= 0;
		}
	}

	//printing values in matrix1
	/*printf("\nMatrix1:\n");
	printf("%d_x_%d:\n", size, size);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%d ",matrix1[i][j]);
		}
		printf("\n");
	}*/
	
	/*-----------------------------------------------------------------
  	checking if numbers are occuring only once, if not it's not magical
	-------------------------------------------------------------------*/
	int hasDup = 0;
	for(int i = 0; i <size; i++) {
		for(int j = 0; j < size; j++) {
			//printf("target: %d---------------\n",matrix1[i][j]);
			if(checkForDuplicates(matrix1[i][j], i, j, size,  matrix1) == -1) {
				printf("not-magic\n");
				hasDup = 1;
				return 0;
				break;
			}
		}
		if(hasDup == 1) {
			break;
		}	
	}
	/*-----------------------------------------------------------------
  	END --- checking if numbers are occuring only once, if not it's not magical
	-------------------------------------------------------------------*/
	//printf("%d",checkForDuplicates(20,size, matrix1));
	
	//Getting value of diagonal
	int diagonalSum = 0;
	for(int i = 0; i < size; i++) {
		diagonalSum += matrix1[i][i];
	}
	//printf("Diagonal Sum: %d\n",diagonalSum);
	
	for(int i = 0; i < size; i++) {
		int rowSum = 0;
		for(int j = 0; j < size; j++) {
			rowSum += matrix1[i][j];
		}
		//printf("Row Sum: %d\n", rowSum);
		if(rowSum != diagonalSum) {
			printf("not-magic\n");
			return 0;
		}
	}
	printf("magic\n");

	//FREEING
	for(int i = 0; i< size; i++){
		free(matrix1[i]);
	}

	free(matrix1);

	return 0;
}
