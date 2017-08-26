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

=====================================================================
#include <stdio.h>
#define MAXSIZE 5

struct stack {
	int stk[MAXSIZE];
	int top;
};

typedef struct stack STACK;
STACK s;

void push(void);
int pop(void);
void display(void);

int main() {
	int choice;
	int option = 1;
	s.top = -1;
	
	printf(" STACK OPERATION.\n");
	
	while (option) {
		printf("Enter your choice\n");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
		}
		
		fflush (stdin);
		printf("Do you want to continue?");
		scanf("%d", &option);
	}
	return 0;
}

void push() {
	int num;
	if (s.top == (MAXSIZE - 1)) {
		printf("Stack is FULL.\n");
		return;
	}
	else {
		printf("Enter the element to be pushed\n");
		scanf("%d", &num);
		s.top = s.top + 1;
		s.stk[s.top] = num;
	}
	return;
}

int pop() {
	int num;
	if (s.top == -1) {
		printf("Stack is Empty\n");
		return (s.top);
	}
	else {
		num = s.stk[s.top];
		printf("poped element is %d\n", s.stk[s.top]);
		s.top = s.top - 1;
	}
	return num;
}

void display() {
	int i;
	if (s.top == -1) {
		printf("Stack is empty\n");
		return;
	}
	else {
		printf("\n The status of the stack is \n");
		for (i = s.top; i >= 0; i--) {
			printf("%d\n", s.stk[i]);
		}
	}
	printf("\n");
}

==============================================================
// author : CreativeCub

#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
int stackSize, top = -1;

/* push element to the top of stack */
void push(int data)
{
    if (top >= stackSize - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    
    stack[++top] = data;
    printf("Data added to stack : %d\n", stack[top]);
}

/* check whether stack is empty or not */
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

/* pop/remove top element from stack */
void pop()
{
    if (isEmpty())
    {
        printf("Stack underflow\n");
        return;
    }
    printf("Data poped from stack : %d\n", stack[top]);
    stack[top--] = 0;
}

/* display elements in stack */
void display()
{
    int i = 0;
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    
    for (i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}

int main ()
{
    int size, data, ch;
    printf("Enter the size of the stack:");
    scanf("%d", &size);
    stackSize = size;
    stack = (int *)malloc(sizeof (int) *size);
    
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. isEmpty\n");
    printf("4. Display Elements\n");
    printf("5. Element count\n");
    printf("6. Exit\n");
    
    while (1)
    {
        printf("Enter your option:");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("Enter Element:");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is not Empty\n");
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    printf("Stack is empty\n");
                else
                    printf("Total Elements :%d\n", top+1);
                break;
            case 6:
                exit(0);
            default:
                printf("You have entered wrong option\n");
                break;
        }
        
    }
    return 0;
}

====================================================================
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 50
int size;

// Defining the stack structure
struct stack {
   int arr[MAX];
   int top;
};

// Initializing the stack(i.e., top=-1)
void init_stk(struct stack *st) {
   st->top = -1;
}

// Entering the elements into stack
void push(struct stack *st, int num) {
   if (st->top == size - 1) {
      printf("\nStack overflow(i.e., stack full).");
      return;
   }
   st->top++;
   st->arr[st->top] = num;
}

//Deleting an element from the stack.
int pop(struct stack *st) {
   int num;
   if (st->top == -1) {
      printf("\nStack underflow(i.e., stack empty).");
      return NULL;
   }
   num = st->arr[st->top];
   st->top--;
   return num;
}

void display(struct stack *st) {
   int i;
   for (i = st->top; i >= 0; i--)
      printf("\n%d", st->arr[i]);
}

int main() {
   int element, opt, val;
   struct stack ptr;
   init_stk(&ptr);
   
   printf("\nEnter Stack Size :");
   scanf("%d", &size);
   
   while (1) {
      printf("\n\nSTACK PRIMITIVE OPERATIONS");
      printf("\n1.PUSH");
      printf("\n2.POP");
      printf("\n3.DISPLAY");
      printf("\n4.QUIT");
      printf("\n");
      printf("\nEnter your option : ");
      scanf("%d", &opt);
      
      switch (opt) {
      case 1:
         printf("\nEnter the element into stack:");
         scanf("%d", &val);
         push(&ptr, val);
         break;
      case 2:
         element = pop(&ptr);
         printf("\nThe element popped from stack is : %d", element);
         break;
      case 3:
         printf("\nThe current stack elements are:");
         display(&ptr);
         break;
      case 4:
         exit(0);
      default:
         printf("\nEnter correct option!Try again.");
      }
   }
   return (0);
}	
