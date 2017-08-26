#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX_SIZE	10

typedef struct listNode { 
	int Data[QUEUE_MAX_SIZE];
	int rear;
	int front;
} qNode; 

qNode *Node = NULL;
int num;

void queue_init(){
	Node = (qNode*)malloc(sizeof(qNode));
	memset(Node, 0, sizeof(qNode));
	Node->rear = 0;
	Node->front = 0;
	num = 0;
}
 
void insert_queue(int data) {
	// queue is full
	if (num == QUEUE_MAX_SIZE) {
		printf("queue is full..\n");
		return;
	}	
	
	printf("Node->rear = %d , ", Node->rear);
	
	Node->Data[Node->rear++] = data;	
	Node->rear = Node->rear % QUEUE_MAX_SIZE; 
	num++;	
	printf("num = %d\n", num);
}

int delete_queue() {
	int retVal = 0;
	if (Node->rear == Node->front && num == 0) {
		printf("queue is empty..\n");
		return;
	}
	
	printf("num = %d\n", num);
	printf("Node->front = %d\n", Node->front);
	
	retVal = Node->Data[Node->front++];	
	Node->front = Node->front % QUEUE_MAX_SIZE;
	
	num--;
	
	return retVal;	
}

void print_queue() {
	int i = 0;
	//printf("Node->front = %d\n", Node->front);
	//printf("Node->rear = %d\n", Node->rear);

	if (Node->front >= Node->rear && num != 0) { 
		for (i=Node->front; i < QUEUE_MAX_SIZE; i++) {
			printf("%d ", Node->Data[i]);
		}

		for (i=0; i < Node->rear; i++) {
			printf("%d ", Node->Data[i]);
		}		
	}
	else if (num != 0) {
		for (i=Node->front; i < Node->rear; i++ ) {
			printf("%d ", Node->Data[i]);
		}
	}
}

void deleteAllNode() {
	Node->front = 0;
	Node->rear = 0;
	num = 0;
	free(Node);
}

int main(void) {
	queue_init();
	
	insert_queue(5);	
	insert_queue(4);
	insert_queue(3);
	insert_queue(2);
	insert_queue(1);
	insert_queue(9);
	insert_queue(8);
	insert_queue(7);	
	insert_queue(6);	
	insert_queue(10);
	insert_queue(4);
	
	print_queue();
	printf("\n");
	
	delete_queue();
	delete_queue();
	delete_queue();
	delete_queue();
	
	print_queue();
	printf("\n");

	insert_queue(100);
	insert_queue(101);
	print_queue();
	printf("\n");

	deleteAllNode();
	print_queue();
	printf("\n");
	
	return 0;	
}
