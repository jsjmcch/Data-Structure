#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sNode {
	char *Data;
	struct sNode *Next;
} Node;

typedef struct listStack {
	Node *Peak;
	int size;
} listStack;

void createStack (listStack **Stack) {
	(*Stack) = (listStack*) malloc(sizeof(listStack));
	(*Stack)->Peak = NULL;
	(*Stack)->size = 0;
}

Node* createNode (char *newChar) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	newNode->Data = (char*) malloc(sizeof(newChar)+1);
	
	strcpy(newNode->Data, newChar);
	newNode->Next = NULL; 
}

void deleteNode (Node *removeNode) {
	free (removeNode->Data);
	free (removeNode);
}

Node* Peak (listStack *Stack) {
	return Stack->Peak;
}

void Push (listStack *Stack, Node *newNode) {
	// Stack is empty
	if (Stack->size == 0) {
		Stack->Peak = newNode;
	}
	// Stack is not empty
	else {
		newNode->Next = Stack->Peak;
		Stack->Peak = newNode;
	}
	
	Stack->size++;
}

Node* Pop (listStack *Stack) {
	Node *Peaka = Stack->Peak;
	
	// Stack is empty
	if (Stack->size == 0) {
		Stack->Peak = NULL;
		printf("no data~~~");
	}
	// Stack is not empty
	else {
		Peaka = Stack->Peak;
		Stack->Peak = Stack->Peak->Next;
		Stack->size--;
	}
	
	return Peaka;
}

void deleteStack (listStack *Stack) {
	int count = Stack->size;
	
	while (count != 0) {
		Node *temp = Pop(Stack);
		deleteNode(temp);
		count--;
	}
	
	free(Stack);
}

int main(void) {
	int i;
	listStack *Stack;
	
	createStack (&Stack);
	
	Push (Stack, createNode("a"));
	Push (Stack, createNode("b"));
	Push (Stack, createNode("c"));
	Push (Stack, createNode("d"));
	
	printf("abcd pushed\n");
	printf("\n--Current Stack--[size : %d]\n\n", Stack->size);
	
	Node *horse = Stack->Peak;
	
	for (i = 0; i < (Stack->size); i++) {
		printf("%s\n", horse->Data);
		horse = horse->Next;
	}
	
	horse = Pop(Stack);
	horse = Pop(Stack);
	
	printf("\n--Current Stack--[size : %d]\n\n", Stack->size);
	horse = Stack->Peak;
	
	for (i = 0; i < (Stack->size); i++) {
		printf("%s\n", horse->Data);
		horse = horse->Next;
	}
	
	deleteStack(Stack);
	printf("\nStack has been completely freed.\n");
	
	return 0;
}
