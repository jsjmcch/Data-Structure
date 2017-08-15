#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

struct node {
	unsigned long long number;
	struct node * next;
};

struct list {
	struct node * head;
	struct node * tail;
};

// 리스트 생성, 리스트 삭제
struct list * list_create();
void list_free( struct list * p_list );

// 리스트 조회
bool list_empty( struct list * p_list );
unsigned long long list_front( struct list * p_list );
unsigned long long list_back( struct list * p_list );

// 리스트 변경 : 노드 삭제, 노드 추가
void list_pop_front( struct list * p_list );
void list_push_back( struct list * p_list, unsigned long long n );

// 디버깅용
void list_print( struct list * p_list, char del );

#ifdef __cplusplus
}
#endif

#endif /* LIST_H_ */
