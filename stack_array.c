#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 5

typedef struct arrayStack {
	int iArray[MAXSIZE];
	int top;
} arrayStack;

int push(arrayStack *aStack, int val);
int pop(arrayStack *aStack, int *val);
void deleteStack(arrayStack *aStack);

int push (arrayStack *aStack, int val) {
	int retVal = 0;
	
	// Stack is full
	if (aStack->top == MAXSIZE - 1) {
		printf("Stack is FULL\n");
		retVal = -1;
	}
	// Stack is not full
	else {
		//printf("aStack->top = %d\n", aStack->top);
		aStack->top++;
		aStack->iArray[aStack->top] = val;		
	}
	
	return retVal;
}

int pop(arrayStack *aStack, int *val) {
	int retVal = 0;
	
	//printf("aStack2->top = %d\n", aStack->top);

	// Stack is empty
	if (aStack->top == -1) {
		printf("Stack is Empty\n");
		retVal = -1;
	}
	// Stack is not empty
	else {
		*val = aStack->iArray[aStack->top];
		aStack->top--;
		//printf("aStack2->top = %d\n", aStack->top);
	}
	
	return retVal;
}

void display(arrayStack *aStack) {
	int size = aStack->top;
	//printf("Stack size = %d\n", size);
	
	while (size >= 0) {
		printf("%d\n", aStack->iArray[size]);
		size--;
	}
}

int main(void) {
	
	arrayStack aStack;
	int val, i = 0;

	// initialization
	for (i = 0; i < MAXSIZE; i++)
		aStack.iArray[i] = 0;
		
	aStack.top = -1;
	
	// push 
	push(&aStack, 1);
	push(&aStack, 2);
	push(&aStack, 3);
	push(&aStack, 4);
	push(&aStack, 5);
	push(&aStack, 6);
	
	display(&aStack);
	
	// pop
	pop(&aStack, &val);
	printf("val1 = %d\n", val);
	pop(&aStack, &val);
	printf("val2 = %d\n", val);
	
	// push
	push(&aStack, 7);
	push(&aStack, 8);
		
	display(&aStack);	
	
	return 0;
}
