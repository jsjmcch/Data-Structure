#include "list.h"

#include <stdlib.h>
#include <stdio.h>

struct list * list_create() {
	struct list * p_list;

	p_list = (struct list * )malloc( sizeof( struct list ) );
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: memory allocation failed.\n", __FUNCTION__ );
	} else {
		p_list->head = NULL;
		p_list->tail = NULL;
	}

	return p_list;
}

void list_free( struct list * p_list ) {
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
	} else {
		while ( !list_empty( p_list ) ) {
			list_pop_front( p_list );
		}

		free( p_list );
	}
}

bool list_empty( struct list * p_list ) {
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
		return true;
	} else {
		return ( NULL == p_list->head );
	}
}

unsigned long long list_front( struct list * p_list ) {
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
		return 0;
	} else {
		if ( list_empty( p_list ) ) {
			fprintf( stderr, "%s: p_list is empty\n", __FUNCTION__ );
			return 0;
		} else {
			return p_list->head->number;
		};
	}
}

unsigned long long list_back( struct list * p_list ) {
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
		return 0;
	} else {
		if ( list_empty( p_list ) ) {
			fprintf( stderr, "%s: p_list is empty\n", __FUNCTION__ );
			return 0;
		} else {
			return p_list->tail->number;
		};
	}
}

void list_pop_front( struct list * p_list ) {
	// 1. validation check
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
		return;
	}

	if ( NULL == p_list->head ) {
		fprintf( stderr, "%s: head is NULL\n", __FUNCTION__ );
		return;
	}

	// 2. delete head node
	struct node * old_head = p_list->head;
	p_list->head = p_list->head->next;
	free( old_head );
}

void list_push_back( struct list * p_list, unsigned long long n ) {
	// 1. validation check
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
		return;
	}

	// 2. create node
	struct node * p_node = (struct node *)malloc( sizeof( struct node * ) );
	if ( NULL == p_node ) {
		fprintf( stderr, "%s: memory allocation failed.\n", __FUNCTION__ );
		return;
	}

	// 3. set values
	p_node->number = n;
	p_node->next = NULL;

	if ( list_empty( p_list ) ) {
		p_list->head = p_node;
		p_list->tail = p_node;
	} else {
		p_list->tail->next = p_node;
		p_list->tail = p_node;
	}
}

void list_print( struct list * p_list, char del ) {
	if ( NULL == p_list ) {
		fprintf( stderr, "%s: p_list is NULL\n", __FUNCTION__ );
	} else if ( list_empty( p_list ) ) {
		fprintf( stderr, "%s: p_list is empty\n", __FUNCTION__ );
	} else {
		if ( p_list->head == NULL ) {
			fprintf( stderr, "%s: p_list->head is null\n", __FUNCTION__ );
		} else {
			printf( "%llu", p_list->head->number );

			for ( struct node * p_index = p_list->head->next;
				  p_index != NULL;
				  p_index = p_index->next ) {
				printf( "%c%llu", del, p_index->number );
			}

			printf("\n");
		}
	}
}

