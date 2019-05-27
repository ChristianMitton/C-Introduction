#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef int bool;
#define true 1
#define false 0

struct Node {
	int data;
	Node *left, *right;
};

bool success = false;

Node *createNode(int number) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = number;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node *insert(Node* root, int number, int height){
	if(root == NULL) {
		printf("inserted %d\n",height);
		return createNode(number);
	}

	if(number < root->data) {
		root->left = insert(root->left, number, height+1);
	} else if(number > root->data) {
		root->right = insert(root->right, number, height+1);
	} else if(number == root->data) {
		printf("duplicate\n");
		return root;
	}
	return root;
	
}

Node* search(Node* root, int target, int height) { 
	if(root == NULL) { 
		printf("absent\n");
		return root; 
	}

	if(root->data == target) {
		printf("present %d\n",height);
		return root;
	} else if (root->data < target) {
		search(root->right,target, height+1); 
	} else if (root->data > target) {
		search(root->left, target, height+1);
	}
	
	return root;	
} 

Node* delete(Node* root, int target) { 
	if (root == NULL) {
		success = false;
		return root;
	} 
	
	if (target < root->data) { 
		root->left = delete(root->left, target); 
	
	} else if (target > root->data) { 		
		root->right = delete(root->right, target); 
	
	} else if(target == root->data) {
		/*------------------------------
		Target has ONE child or NO child 
		--------------------------------*/
		if (root->left == NULL) { 
            		Node *targetRightChild = root->right; 
            		free(root); //delete parent
			success = true;
            		return targetRightChild; //if right is NULL, NULL will be returned

        	} else if (root->right == NULL) { 
			Node *targetLeftChild = root->left; 
			free(root); //delete parent
			success = true;
			return targetLeftChild; //if left is NULL, NULL will be returned here
		} 
  		/*---------------------
 		Target has TWO children 
  		-----------------------*/
		//get smallest number in right subtree
		
		Node *ptr = root->right;
		while(ptr->left != NULL) {
			ptr = ptr->left;
		}
		//ptr now points to smallest Number in right subtree (inorder successor)
			
		Node* successor = ptr; 
		//change root data to successor
		root->data = successor->data; 
		//delete successor
		root->right = delete(root->right, successor->data);
		success = true; 
	}
	
	return root; 
} 

int main(int argc, char** argv) {
	
	FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }

	char letter;
	int number;
	
	Node *root = NULL;

	while(fscanf(fp,"%c %d\n", &letter, &number) == 2) {
		//printf("letter: %c\tnumber: %d\n",letter,number);
		if(letter == 'i') {
		//insert
			root = insert(root, number, 1);		
		}
		if(letter == 's') {
		//search
			root = search(root, number, 1);
		}
		if(letter == 'd') {
		//delete
			root = delete(root, number);
			if(success == true) {
				printf("success\n");
			} else {
				printf("fail\n");
			}
		}
	}
	
	return 0;
}
