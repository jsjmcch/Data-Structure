/*
 * 알고리즘: bubble sort
 * 비교적 쉬운 정렬 알고리즘인 bubble sort에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 주어진 배열에 대해 bubble sort를 진행한다.
 *
 * 거품 정렬(Bubble sort)은 두 인접한 원소를 검사하여 정렬하는 방법이다.
 * 정렬이 상당히 느리지만, 코드가 단순하기 때문에 자주 사용된다. 원소의
 * 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어진 이름이다.
 * 출처: https://ko.wikipedia.org/wiki/%EA%B1%B0%ED%92%88_%EC%A0%95%EB%A0%AC
 *
 * @param list: 정렬을 진행 할 배열의 주소
 * @param n: 정렬을 진행 할 배열의 길이
 * @return: 없음
 */
void bubbleSort(int *list, const int n)
{
	int tmp=0, loop, i;

    for (loop = 0; loop < n - 1; loop++) {
        for (i = 0; i < n - 1 - loop; i++) {
            if (list[i] > list[i+1]) {
                tmp = list[i];
                list[i] = list[i+1];
                list[i+1] = tmp;
            }
        }
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


int main(void) {
	int array[10] = {3, 6, 4, 8, 9, 1, 2, 5, 7, 10};
	puts("before bubble sort");
	printArr(array, 10);

	//bubble sort를 진행한다.
	bubbleSort(array, 10);

	puts("after bubble sort");
	printArr(array, 10);

	return EXIT_SUCCESS;
}
========================================================================================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BubbleSort_up(char * str)
{
    int nLen = strlen(str);
    int i,j;
    char cTemp;

    printf("[BUBBLE SORT(low->big)]\n%s\n",str);
    for (i=0; i<nLen - 1; i++)
    {
        for (j=0; j<nLen-i-1; j++)
        {
            if (str[j] > str[j+1])
            {
                cTemp = str[j];
                str[j] = str[j+1];
                str[j+1] = cTemp;
            }
        }
    }
    printf("%s\n", str);
}

void BubbleSort_down(char * str)
{
    int nLen = strlen(str);
    int i,j;
    char cTemp;

    printf("[BUBBLE SORT(big->low)]\n%s\n",str);
    for (i=0; i<nLen - 1; i++)
    {
        for (j=0; j<nLen-1-i; j++)
        {
            if (str[j] < str[j+1])
            {
                cTemp = str[j];
                str[j] = str[j+1];
                str[j+1] = cTemp;
            }
        }
    }
    printf("%s\n", str);
}

void main(void)
{
    char bubble_buf[] = "2431";

    // down -> up
    BubbleSort_up(bubble_buf);
    // up -> down
    BubbleSort_down(bubble_buf);
}
