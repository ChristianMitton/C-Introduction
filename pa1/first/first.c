#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *, int);
void printArray(int *, int);

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++) {
       printf("%d\t", arr[i]);
   }
   printf("\n");
}


int main(int argc, char** argv){
	if (argc != 2) {
	  printf("Not enough arguments\n");
	  return 0;
	}

	int element;
	int elementFor2ndLoop;
	FILE *fp;
	fp = fopen(argv[1], "r"); //open the second argument user puts, which is (textfile).txt
	if(fp == NULL){ //if the text file is NULL, exit program
		printf("Null file\n"); 
		return 0;
	}
	
	FILE *fp2;
	fp2 = fopen(argv[1], "r");

	int sizeOfArray;
	int * sizePtr = &sizeOfArray;	
	int counter = 0;
	
	while(fscanf(fp, "%d", &element) == 1) {
		if(counter == 0){
			//printf("\nNumber of elements: %d\n",element);
			*sizePtr = element;
		} /*else {			
			printf("element (%d.) %d\n",counter,element);
		}*/	
		counter++;	
	}
	//printf("Size of Array: %d\n",sizeOfArray);
	
	//CREATING ARRAY:
	int result[sizeOfArray];
	
	//*counterPtr = 0;
	counter = 0;
	//int resultCounter = 0;
	while(fscanf(fp2, "%d", &elementFor2ndLoop) == 1) {
		if(counter == 0) {
			counter++;
			continue;
		}
		result[counter-1] = elementFor2ndLoop; //ith element in array = jth element in file
		//printf("result[%d] %d\n",counter-1,result[counter-1]);
		counter++;
	}
	fclose(fp);
	//RESULT NOW CONTAINS DATA
	//printf("Original\n");
	//printArray(result, sizeOfArray);	
	insertionSort(result, sizeOfArray);
	//printArray(result, sizeOfArray);
	
	//RESULT IS NOW SORTED	
	int finalResult[sizeOfArray];
	
	int resultIndex;
	int finalResultIndex = 0;

	for(resultIndex = 0; resultIndex < sizeOfArray; resultIndex++) {
		if(result[resultIndex] % 2 == 0) {
			finalResult[finalResultIndex] = result[resultIndex];
			finalResultIndex++;
		}
	}

	for(resultIndex = 0; resultIndex < sizeOfArray; resultIndex++) {
		if(result[resultIndex] % 2 != 0) {
			finalResult[finalResultIndex] = result[resultIndex];
			finalResultIndex++;
		}
	}
	
	
	//printf("Sorted:\n");
	//printArray(result, sizeOfArray);
	//printf("Final Result:\n");
	printArray(finalResult, sizeOfArray);

	//printf("Closing program.\n");	
	return 0;
}
