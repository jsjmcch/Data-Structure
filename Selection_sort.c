/*
 * 알고리즘: selection sort
 * 가장 쉬운 selection sort에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 주어진 배열에 대해 선택 정렬을 진행한다.
 *
 * 선택 정렬(選擇整列, selection sort)은 제자리 정렬 알고리즘의 하나로, 다음과 같은 순서로 이루어진다.
 * 1. 주어진 리스트 중에 최솟값을 찾는다.
 * 2. 그 값을 맨 앞에 위치한 값과 교체한다(패스(pass)).
 * 3. 맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.
 * 출처: https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC
 *
 * @param list: 정렬을 진행 할 배열의 주소
 * @param n: 정렬을 진행 할 배열의 길이
 * @return: 없음
 */
void selectionSort(int *list, const int n)
{
    int i, j, indexMin, temp;

    for (i = 0; i < n - 1; i++)
    {
        indexMin = i;
        for (j = i + 1; j < n; j++)
        {
            if (list[j] < list[indexMin])
            {
                indexMin = j;
            }
        }
        temp = list[indexMin];
        list[indexMin] = list[i];
        list[i] = temp;
    }
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
	//정렬 할 배열을 초기화 한다.
	int array[10] = {3, 6, 4, 8, 9, 1, 2, 5, 7, 10};

	puts("before selection sort");
	printArr(array, 10);

	//배열을 선택 정렬 방식으로 정렬한다.
	selectionSort(array, 10);

	puts("after selection sort");
	printArr(array, 10);

	return EXIT_SUCCESS;
}
