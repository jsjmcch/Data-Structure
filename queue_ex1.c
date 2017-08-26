/*
 * 자료구조: queue
 * FIFO (Fist-In First-Out) 구조를 갖고 있는 Queue에 대해 알아본다.
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * queue 의 정보를 저장하는 구조체
 * data: queue에 저장될 정보를 저장할 포인터
 * size: queue의 크기를 저장할 변수
 * front: enqueue를 하는 위치를 저장하는 변수
 * rear: dequeue를 하는 위치를 저장하는 변수
 */
typedef struct _queue
{
	int *data;
	int size;
	int front;
	int rear;
}queue;

int init_queue(queue *q, int size);
void free_queue(queue *q);

int is_fullqueue(queue *q);
int is_emptyqueue(queue *q);

int enqueue(queue *q, int data);
int dequeue(queue *q, int *data);

int main()
{
    int i;
    queue q;

    init_queue(&q, 10);

    //10개의 item을 queue에 넣는다.
    printf("try enqueue 10 items.\n");
    for(i=0; i<10; i++)
    {
        if(enqueue(&q, i))
        	printf("Data %d, Enqueued\n", i);
        else
        {
        	printf("enqueue failed\n");
        	break;
        }
    }

    //10개의 item을 queue에서 꺼낸다.
    printf("\ntry dequeue 10 items.\n");
    for(i=0; i<10; i++)
    {
    	int data;
    	if(dequeue(&q, &data))
    		printf("got %d, from queue\n", data);
    	else
    	{
    		printf("dequeue failed");
    		break;
    	}
    }

    //5개의 item을 queue에 넣는다.
    //TODO: 왜 이 eneuque가 실패하는지 생각해보자.
    printf("\ntry enqueue 5 items.\n");
    for(i=10; i<15; i++)
    {
        if(enqueue(&q, i))
        	printf("Data %d, Enqueued\n", i);
        else
        {
        	printf("enqueue failed\n");
        	break;
        }
    }

    //5개의 item을 queue에서 꺼낸다.
    printf("\ntry dequeue 5 items.\n");
    for(i=0; i<5; i++)
    {
    	int data;
    	if(dequeue(&q, &data))
    		printf("got %d, from queue\n", data);
    	else
    	{
    		printf("dequeue failed");
    		break;
    	}
    }

    //queue에 할당된 메모리를 해제한다.
    free_queue(&q);
    return 0;
}

/*
 * queue를 초기화 하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @param size: queue의 크기
 * @return: queue가 정상적으로 초기화 된 경우 1 그렇지 않으면 0
 */
int init_queue(queue *q, int size)
{
    q->data = (int*)malloc(size * sizeof(int));
    if(q->data == NULL)
    {
    	printf("malloc failed\n");
    	return -1;
    }

    q->size = size;
    q->front = q->rear = 0;
    return 1;
}

/*
 * queue에 할당된 메모리를 free 하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @return: 없음
 */
void free_queue(queue *q)
{
    free(q->data);
    q->size = 0;
}

/*
 * queue에 data영역이 모두 찼는지 확인 하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @return: queue가 full일 경우 1, 그렇지 않으면 0
 */
int is_fullqueue(queue *q)
{
	return ((q->size)<=(q->rear)) ? 1: 0;
}

/*
 * queue에 data 영역이 비어있는지 확인하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @return: queue가 empty일 경우 1, 그렇지 않으면 0
 */
int is_emptyqueue(queue *q)
{
	return (q->front==q->rear) ? 1: 0;
}

/*
 * queue에 data를 enqueue 하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @param data: 저장할 data
 * @return: queue에서 정상적으로 enqueue  한경우 1, 에러가 발생했으면 0
 */
int enqueue(queue *q, int data)
{
    if(is_fullqueue(q))
    {
    	printf("queue was full!\n");
        return 0;
    }

    q->data[q->rear] = data;
    q->rear += 1;

    return 1;
}

/*
 * queue에 data를 dequeue 하는 함수
 * @param q: queue의 정보를 저장한 구조체 변수
 * @param data: dequeue한 데이터를 저장할 주소
 * @return: queue에서 정상적으로 dequeue  한경우 1, 에러가 발생했으면 0
 */
int dequeue(queue *q, int *data)
{
	if(is_emptyqueue(q))
	{
		printf("empty queue\n");
		return 0;
	}

	*data = q->data[q->front];
	q->front += 1;

	return 1;
}
