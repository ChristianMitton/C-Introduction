#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left, *right;
};

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

/*void inorder(Node *root) { //DELETEEEEEEEEEEEEEEE 
	if (root == NULL) {
		return;
	} 
	inorder(root->left); 
	printf("%d\n", root->data); 

	inorder(root->right); 
} */

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

int main(int argc, char **argv) {
	
	FILE *fp = fopen(argv[1], "r"); /*open file*/ if(fp == NULL) { printf("error\n"); return 0; }

	char letter;
	int number;
	
	Node *root = NULL;

	while(fscanf(fp,"%c %d\n", &letter, &number) == 2) {
		if(letter == 'i') {
			root = insert(root, number, 1);
		}
		if(letter == 's') {
			root = search(root, number, 1);
		}
	}

	/*
	Node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	
	inorder(root);
	root = search(root, 40, 1);
	*/
	return 0;
}
