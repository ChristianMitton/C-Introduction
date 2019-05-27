#include <stdio.h> 
#include <stdlib.h>

typedef struct Node Node;

int size = 10000;

struct Node {
	int data;
	struct Node *next;
	
};

struct hashTable {
	Node *list[10000];
};

struct hashTable *createTable();

struct hashTable *createTable() {
	
	struct hashTable *table = malloc(1* sizeof(struct hashTable) );

	//Initialize all elements in hash table
	for(int i = 0; i < 10000; i++) {
		table->list[i] = NULL;
	}
	
	return table;
}

void addToFront(struct Node **head, int target) {
          struct Node *temp = (struct Node *) malloc(1 * sizeof(struct Node)); //space created for one node
  
          if(*head == NULL) { //recently added * to head here
                  temp->data = target;
                  (*head) = temp; //*head = ptr to head
                  return;
          }
          temp->data = target;
          temp->next = (*head);
          (*head) = temp;
  
 }

int search(struct hashTable *, int);
int search(struct hashTable *table, int target) {
	
	int hashCode;
	if(target >= 0) {
		hashCode = target % size;
	} else {
		hashCode = (target*-1) % size;
	}
	//Node *ptr = table->list[hashCode];

	//traverse and search through the linked list
	for (Node *ptr = table->list[hashCode]; ptr != NULL; ptr = ptr->next) {
		if (ptr->data == target) {
			return 1;
		}
	} 
	
	return 0;
}



int main(int argc, char** argv){

	char letter;
	int number;

 	FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }
        //printf("\n");

	struct hashTable *table = createTable();

      	while(fscanf(fp,"%c %d\n", &letter, &number) == 2) {
		if(letter == 'i') {
			int hashCode;
			if(number >= 0) {
				hashCode = number % size;
			} else {
				hashCode = (number*-1) % size;
				//printf("hashCode: %d\n",hashCode);
				//return 0;
			}
			Node * currList;
			Node * newNode = malloc( sizeof(Node) );
			
		    if(search(table, number) == 0) {
			
			if(table->list[hashCode] == NULL) {
				addToFront(&table->list[hashCode], number);
				//printf("%d was inserted\n", number);
				printf("inserted\n");
			} else {
				currList = table->list[hashCode];
				newNode->data = number;
				newNode->next = currList;
				table->list[hashCode] = newNode;
				//printf("%d was inserted\n",table->list[hashCode]->data);
				printf("inserted\n");
			}

		    } else {
			printf("duplicate\n");
		    }
		
		} 

		if (letter == 's') {
			if(search(table, number) == 1) {
				printf("present\n");
			} else {
				printf("absent\n");
			}
			
		}
	

	}

	return 0;
}
