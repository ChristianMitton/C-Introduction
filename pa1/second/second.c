#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void insertionSort(int *, int);

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

void addToFront(struct node **, int);

void removeNode(struct node **, int);

void addToFront(struct node **head, int target) {
	struct node *temp = (struct node *) malloc(1 * sizeof(struct node)); //space created for one node
	
	if(*head == NULL) { //recently added * to head here
		temp->data = target;
		(*head) = temp; //*head = ptr to head
		return;
	}
	
	//NO DUPLICATES:
	struct node *ptr = *head;
	while(ptr != NULL) {
		if(ptr->data == target) {
			return;
		}
		ptr = ptr->next;
	}
	//END NO DUPLICATES

	temp->data = target;
	temp->next = (*head);
	(*head) = temp;	
}

void removeNode(struct node **head, int target) {
	if(*head == NULL) {
		return;
	}
	struct node *ptr = *head;
	struct node *prev = NULL;	
	

	while(ptr != NULL) {
		if(ptr->data == target && prev == NULL){
			struct node *temp = ptr;
			ptr = ptr->next;
			*head = ptr;
			free(temp);
			continue;
				
		}
		
		if(ptr->data == target) {
			prev->next = ptr->next;
			struct node *temp = ptr;
			ptr = ptr->next;
			free(temp);
			if(ptr == NULL) {
				return;
			}
			continue;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	
}

int main(int argc, char** argv) {
	if (argc != 2) { printf("error\n"); return 0; }
	
	struct node *head = NULL;

	char letter; int number;	

	FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }
	while(fscanf(fp,"%c %d\n", &letter, &number) == 2) {
		//printf("%c %d\n",letter, number);
		if(letter == 'i') {
			addToFront(&head, number);
		}
		if(letter == 'd') {
			removeNode(&head, number);
		}
	}

	struct node *ptr = head;
	
	int counter = 0;
	while(ptr != NULL) {
		counter++;
		ptr = ptr->next;
	}

	//SORTING
	int array[counter];
	int count = 0;
	for(struct node *listPtr = head; listPtr != NULL; listPtr = listPtr->next) {
		array[count] = listPtr->data;
		count++;
	}
	
	//count = 0;
	//printf("\n");
	//printf("Array before sort:\n");
	//while(count < counter) {
	//	printf("%d, ",array[count]);
	//	count++;
	//}
	
	insertionSort(array, counter);
	//printf("\nArray after sort:\n");
	//count = 0;
	//while(count < counter) {
	//	printf("%d, ",array[count]);
	//	count++;
	//}
	//printf("\n");
	//END OF SORTING
	
	//TURN ARRAY INTO LL
	struct node *resultHead = NULL;
	
	for(int i = counter-1; i > -1; i--) {
		addToFront(&resultHead, array[i]);
		//printf("%d was added to front of final LL\n",array[i]);
	}	
	
	//END OF TURN ARRAY INTO LL 
	
	//PRINT NEW LL (BE SURE TO CHANGE )
	printf("%d\n",counter);
	ptr = resultHead;
	while(ptr != NULL) {
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	fclose(fp);	
	return 0;	
}
