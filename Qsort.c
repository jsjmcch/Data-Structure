/*
 * 실습: qsort 함수
 *
 * qsort() 함수는 C표준 라이브러리에서 제공하는 함수이다. 이 함수는 다양한 자료형에
 * 사용할 수 있도록 void형 포인터와 function 포인터를 인자로 받는다. 이 함수를
 * 활용해서 구조체를 정렬하는 프로그램을 완성 하시오.
 *
 *qsort() 함수의 원형
 *  void qsort(void *base, size_t nmemb, size_t size,
           int (*compar)(const void *, const void *));
 *
 */

#include <stdio.h>
#include <stdlib.h>

// 제품의 정보를 담는 구조체를 정의한다.
typedef struct  {
    char name[16];
    int price;
    int quantity;
} product;

void print_struct_array( product *array, int len);
int struct_cmp_by_price(const void *a, const void *b);
int struct_cmp_by_quantity(const void *a, const void *b);

int main(void) {

	//구조체 배열을 선언하고, 값을 초기화 한다.
	product p[] = {
			{"텀블러", 29900, 100},
			{"OLED TV", 2200000, 2},
			{"노트북", 1300000, 39},
			{"스마트폰", 590000, 80},
			{"휴지", 14000, 43},
			{"과자", 2990, 299}
	};

	//구조체의 길이를 계산한다.
	int structs_len = sizeof(p) / sizeof(product);

	//sort 하기 전 구조체 배열의 내용을 출력한다.
	puts("SORT 전");
	print_struct_array(p, structs_len);

	//TODO: qsort 함수에 구조체 배열의 주소와 크기 그리고 비교에
	//사용할 함수의 주소를 인자로 넘겨서 정렬한다.

	//가격을 기준으로 정렬한 후 구조체 배열의 내용을 출력한다.
	puts("가격 SORT 결과");
	print_struct_array(p, structs_len);

	//TODO: 수량을 기준으로 한번 더 정렬한다.

	//수량을 기준으로 정렬한 후 구조체 배열의 내용을 출력한다.
	puts("수량 SORT 결과");
	print_struct_array(p, structs_len);
}

/*
 * 구조체 배열의 주소와 길이를 받아서 구조체 정보를 출력하는 함수
 */
void print_struct_array(product *array, int len)
{
    int i;

    for(i=0; i<len; i++)
        printf("[%d] 제품명: %s \t 가격: %8d \t 수량: %d  \n",
        		(int)i, array[i].name, array[i].price, array[i].quantity);

    putchar('\n');
}


/*
 * 가격을 기준으로 정렬할때 사용하는 비교 함수
 * 파라미터a,b는 비교할 대상의 주소이다.
 * type casting을 해서 사용하면 된다.
 *
 * 결과로 a가 b보다 크면 양수,
 * 같으면 0 다르면
 * 음수를 return 한다.
 */
int struct_cmp_by_price(const void *a, const void *b)
{
   //TODO: 함수를 완성한다.
}

/*
 * 수량을 기준으로 정렬할때 사용하는 비교 함수
 * 파라미터a,b는 비교할 대상의 주소이다.
 * type casting을 해서 사용하면 된다.
 *
 * 결과로 a가 b보다 크면 양수,
 * 같으면 0 다르면
 * 음수를 return 한다.
 */
int struct_cmp_by_quantity(const void *a, const void *b)
{
    //TODO: 함수를 완성한다.
}
