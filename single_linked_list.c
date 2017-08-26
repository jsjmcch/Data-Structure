/*
 * 자료구조: linked list
 * C언어에서 많이 사용되는 linked list에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//자료를 저장 할 수 있는 tour 구조체를 정의한다.
//구조체에는 다음 데이터 노드(Node)를 가리킬 수 있도록
//구조체 포인터 멤버변수가 선언 되어 있어야 한다.
typedef struct _tour {
  char *name;
  int cost;
  float distance;
  struct _tour *next;
}tour;

tour* create_node(char *name, int cost, float distance);
int insert_node(tour **head, tour* new);
void free_all(tour *h);
void print_list(tour *h);

int main(void) {
	//Linked List의 시작점을 가리키게될 root 노드
	tour* head = NULL;
	tour* new = NULL;

	//노드를 5개 생성한다.
	new = create_node("서울", 1000000, 7.0f);
	if(new != NULL)
		insert_node(&head, new);

	new = create_node("대전", 800000, 150.4f);
	if(new != NULL)
		insert_node(&head, new);

	new = create_node("충주", 500000, 28.7f);
	if(new != NULL)
		insert_node(&head, new);

	new = create_node("대구", 900000, 32.5f);
	if(new != NULL)
		insert_node(&head, new);

	new = create_node("부산", 1200000, 64.8f);
	if(new != NULL)
		insert_node(&head, new);

	//노드를 모두 순회 하면서 내용을 출력 한다.
	print_list(head);

	//프로그램을 종료 하기 전에 노드를 모두 순회하면서 메모리를 해제 한다.
	free_all(head);

	return EXIT_SUCCESS;
}

/*
 * 노드를 생성하고, 가장 마지막 노드로 연결한다.
 * @param name: 새로 생성할 node에 저장할 도시 이름 문자열
 * @param cost: 새로 생성할 node에 저장할 소요비용
 * @param distance: 새로 생성할 node에 저장할 이동거리 데이터
 * @return: 새로운 노드의 포인터
 */
tour* create_node(char *name, int cost, float distance)
{
	tour *t = (tour*)malloc(sizeof(tour));

	if(t == NULL)
		return NULL;

	t->name = strdup(name);
	t->cost = cost;
	t->distance = distance;
	t->next = NULL;

	return t;
}

/*
 * 새 노드를 마지막 노드로 연결한다.
 * @param head: 노드의 시작점(root)를 가리키는 포인터의 포인터.(이중포인터)
 *              새로 생성한 노드를 전체 리스트의 마지막에 붙인다.
 * @param new: 새 노드의 포인터
 * @return: 0
 */
int insert_node(tour **head, tour* new)
{
	if((*head) == NULL)
		*head = new;
	else
	{
		tour *cur = (*head);
		while(cur->next != NULL)
			cur = cur->next;

		cur->next = new;
	}
	return 0;
}

/*
 * 노드 전체를 순회하면서 메모리를 해제하는 함수
 * @param h: 노드의 시작점를 가리키는 포인터
 * @param fp: 순회하면서 사용할 로직을 담은 함수의 포인터
 * @return: 없음
 */
void free_all(tour *h)
{
	tour* del;
	while(h != NULL)
	{
		del = h;
		h = h->next;
		free(del->name);
		free(del);
	}
}

/*
 * 노드 전체를 순회하면서 도시 명을 출력하는 함수
 * @param h: 노드의 시작점를 가리키는 포인터
 * @param fp: 순회하면서 사용할 로직을 담은 함수의 포인터
 * @return: 없음
 */
void print_list(tour *h)
{
  while(h != NULL)
  {
	puts("------------------");
    printf("도시명: %s\n", h->name);
	printf("소요 비용: %d\n", h->cost);
	printf("이동 거리: %0.1f\n", h->distance);
    h = h->next;
  }
}
