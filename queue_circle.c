#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE	100
#define MSG_SIZE 1024

typedef struct listNode { 
	char *Data[QUEUE_MAX_SIZE];
	int size;
	int rear;
	int front;
} qNode; 

qNode *Node = NULL;

void queue_init(){
	int cnt;
	Node = (qNode*)malloc(sizeof(qNode));
	if( Node == NULL ) { printf("malloc error1\n"); return; }
	for(cnt=0; cnt<QUEUE_MAX_SIZE; cnt++) {
		Node->Data[cnt] = (char *) malloc(sizeof(char) * MSG_SIZE); 
		if( Node->Data[cnt] == NULL ) { printf("malloc error2\n"); exit(2); }
		memset( Node->Data[cnt], 0x0, MSG_SIZE );
	}
	Node->rear = 0;
	Node->front = 0;
	Node->size = 0;
}

void insert_queue(char *iData) {
	// queue is full
	printf("+++++++++++++++++++++enqueue_sta++++++++++++++++++++\n");
	if (Node->size == QUEUE_MAX_SIZE) {
		printf("queue is full..\n");
		return;
	}	

	printf("Node->rear = %d\n", Node->rear);
	
	memset( Node->Data[Node->rear], 0x0, MSG_SIZE );	//  珥덇린??
	memcpy( Node->Data[Node->rear], iData, strlen(iData) ); 
	Node->rear = (Node->rear + 1) % QUEUE_MAX_SIZE; 
	Node->size++;	
	printf("Node->size = %d\n", Node->size);
}

int delete_queue(char *oData) {
	printf("+++++++++++++++++++++dequeue_sta++++++++++++++++++++\n");
	if (Node->rear == Node->front && Node->size == 0) {
		printf("queue is empty..\n");
		return -1;
	}
	
	printf("Node->front = %d\n", Node->front);
	
	memcpy( oData, Node->Data[Node->front], strlen(Node->Data[Node->front]) );
	Node->front = (Node->front + 1) % QUEUE_MAX_SIZE;
	
	Node->size--;
	printf("Node->size = %d\n", Node->size);
	printf("+++++++++++++++++++++dequeue_end++++++++++++++++++++\n");
	
	return 0;
}

void print_queue() {
	int i = 0;

	if (Node->front >= Node->rear && Node->size != 0) { 
		for (i=Node->front; i < QUEUE_MAX_SIZE; i++) {
			printf("%s \n", Node->Data[i]);
		}

		for (i=0; i < Node->rear; i++) {
			printf("%s \n", Node->Data[i]);
		}		
	}
	else if (Node->size != 0) {
		for (i=Node->front; i < Node->rear; i++ ) {
			printf("%s \n", Node->Data[i]);
		}
	}
}

void deleteAllNode() {
	int cnt;
	for(cnt=0; cnt<QUEUE_MAX_SIZE; cnt++) {
		if ( Node->Data[cnt] != NULL )
			free(Node->Data[cnt]);
	}
	Node->front = 0;
	Node->rear = 0;
	Node->size = 0;
	free(Node);
}
