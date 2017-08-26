/*
 * 알고리즘: linear search
 * 정렬되지 않은 자료에 사용할 수 있는 선형검색 알고리즘에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 리스트에서 linear search 방식으로 특정 값의 index를 검색한다.
 *
 * 순차 검색 알고리즘(sequential search algorithm), 또는 선형 검색 알고리즘(linear search algorithm)은
 * 리스트에서 특정한 값을 찾는 알고리즘의 하나다. 이것은 리스트에서 찾고자 하는 값을 맨 앞에서부터
 * 끝까지 차례대로 찾아 나가는 것이다.
 * 출처: https://ko.wikipedia.org/wiki/%EC%88%9C%EC%B0%A8_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
 *
 * @param array: 검색을 진행 할 배열의 주소
 * @param m: 검색을 진행 할 배열의 길이
 * @param value: 검색할 값
 * @return: 검색에 성공한 경우 원소의 index, 실패한경우 -1
 */
int linearSearch(int array[], int m, int value)
{
    int i;
    for (i = 0; i < m; i++)
        if (array[i] == value)
            return i;
    return -1;
}

/*
 * 배열의 내용을 출력한다.
 * @param list: 출력 할 배열의 주소
 * @param n: 출력 할 배열의 길이
 * @return: 없음
 */
void printArr(int *list, const int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
}


int main(void)
{
	int array[10] = {3, 6, 4, 8, 9, 1, 2, 5, 7, 10};
	int find = 7;
	printf("find %d on array as below\n", find);
	printArr(array, 10);

	//linear search를 통해서 값을 찾고, 인덱스를 출력한다.
	printf("found at index: %d", linearSearch(array, 10, find));

	return EXIT_SUCCESS;
}
