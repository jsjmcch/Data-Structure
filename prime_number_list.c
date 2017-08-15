#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "list.h"

#define MAX_SIZE (1000*1000)

bool add_if_prime( struct list *p_list, unsigned long long n ) {
	struct node *p_index;
	unsigned long long square;
	for( p_index = p_list->head; p_index != NULL; p_index = p_index->next ) {
		square = p_index->number * p_index->number;
		if ( square <= n ) {
			if (( n % p_index->number ) == 0 ) {
				break;
			} 
		} else {
			break;
		}
	}
	
	if ( square <= n ) 
		return false;
	else {
		list_push_back( p_list, n );
		return true;
	}
}

void printUsage(int argc, char *argv[]) {
	printf("Usage : %s [options] N\n", argv[0]);
	printf("N번째 소수를 출력한다.\n\n");
	printf(" -v    버전정보를 출력한다.\n");
	printf(" -h    사용법을 출력한다.\n\n");
	printf("N의 허용범위는 1 <= N <= %d 이다.\n", MAX_SIZE);
}

void printVersion() {
	printf("prime3 v1.0\n");
}

int main( int argc, char *argv[] ) {
	unsigned int max_index;
	int opt;

	// 1. parameter 처리
	while (( opt = getopt(argc, argv, "hv")) != -1 ) {
		switch( opt ) {
			case 'h':
				printUsage( argc, argv );
				exit(EXIT_SUCCESS);
			case 'v':
				printVersion();
				exit(EXIT_SUCCESS);
			default:
				printUsage( argc, argv );
				exit(EXIT_FAILURE);
		}
	}

	if ( optind < argc ) {
		max_index = atoi(argv[optind]);
	} else {
		printUsage( argc, argv );
		exit( EXIT_FAILURE );
	}

	if ( max_index > MAX_SIZE || max_index < 1 ) {
		printUsage( argc, argv );
		exit( EXIT_FAILURE );
	}
	//printf("==========CHK===========\n");
	//printf("optind = %d\n", optind);
	//printf("max_index = %d\n", max_index);
	//printf("argc = %d\n", argc);

	// 2. 소수 구하기
	struct list *prime_list = list_create();
	if ( max_index >=1 ) list_push_back( prime_list, 2);
	unsigned long long number = 3;
	for ( int i=1; i < max_index; i++ ) {
		while( !add_if_prime( prime_list, number )) {
			number = number + 2;
		}
		number = number + 2;
	}	

	list_print( prime_list, ',' );
	printf("%llu\n", list_back(prime_list));

	list_free( prime_list );

	return 0;
}

