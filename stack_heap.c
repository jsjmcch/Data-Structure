/*
 * 자료구조: Stack
 * LIFO (Last-In First-Out) 구조를 갖고 있는 Stack에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * stack 의 정보를 저장하는 구조체
 * data: stack에 저장될 정보를 저장할 포인터
 * size: stack의 크기를 저장할 변수
 * top: stack의 top위치를 저장할 변수
 */
typedef struct _stack
{
	int *data;
	int size;
	int top;
}stack;

int init_stack(stack *s, int size);
void free_stack(stack *s);

int is_fullstack(stack *s);
int is_emptystack(stack *s);

int stack_push(stack *s, int data);
int stack_pop(stack *s, int *data);

int main()
{
	int i, pd=0;
    stack s;

    //stack의 크기는 5로 초기화 한다.
    if(init_stack(&s, 5)==0)
    {
    	puts("stack initialize failed\n");
    	return 0;
    }

    //stack에 data를 push 한다.
    //의도적으로 6개의 data를 push해서 full stack 에러를 살펴본다.
    for(i=0; i<6; i++)
    {
    	if(stack_push(&s, i) != 0)
        	printf("data %d, Pushed\n", i);
        else
        	printf("push failed\n");

    }

    printf("---------------- \n\n");

    //stack의 내용을 모두 pop한다.
    while(stack_pop(&s, &pd) != 0)
       printf("Popped data: %d\n", pd);

    free_stack(&s);
    return 0;
}

/*
 * stack을 초기화 하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @param size: stack의 크기
 * @return: stack이 정상적으로 초기화 된 경우 1 그렇지 않으면 0
 */
int init_stack(stack *s, int size)
{
    s->data = (int*)malloc(size*sizeof(int));
    if(s->data == NULL)
    	return 0;

    s->size = size;
    s->top = -1;
    return 1;
}

/*
 * stack에 data영역이 모두 찼는지 확인 하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @return: stack이 full일 경우 1, 그렇지 않으면 0
 */
int is_fullstack(stack *s)
{
	return (s->top < s->size-1) ? 0: 1;
}

/*
 * stack에 data 영역이 비어있는지 확인하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @return: stack이 empty일 경우 1, 그렇지 않으면 0
 */
int is_emptystack(stack *s)
{
	return (s->top == -1) ? 1: 0;
}

/*
 * stack에 data를 push 하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @param data: stack에 push 할 데이터
 * @return: stack에 저장했으면 1, 에러가 발생(full) 했으면 0
 */
int stack_push(stack *s, int data)
{
    if(is_fullstack(s))
    {
        printf("stack full\n");
        return 0;
    }

    s->top += 1;
    s->data[s->top] = data;
    return 1;
}

/*
 * stack에서 data를 pop 하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @param data: pop한 결과를 저장할 주소
 * @return: stack에서 정상적으로 pop 한경우 1, 에러가 발생했으면 0
 */
int stack_pop(stack *s, int *data)
{
	if(is_emptystack(s))
	{
		printf("stack empty\n");
		return 0;
	}
	*data = s->data[s->top];
	s->top -= 1;
	return 1;
}

/*
 * stack에 할당된 메모리를 free 하는 함수
 * @param s: stack의 정보를 저장한 구조체 변수
 * @return: 없음
 */
void free_stack(stack *s)
{
    free(s->data);
    s->size = 0;
}
