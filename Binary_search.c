/*
 * 알고리즘: binary search
 * 정렬된 자료에 사용할 수 있는 이진검색 알고리즘에 대해 알아본다.
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 리스트에서 binary search 방식으로 특정 값의 index를 검색한다.
 *
 * 이진 검색 알고리즘(binary search algorithm)은 오름차순으로
 * 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다.
 * 처음 중간의 값을 임의의 값으로 선택하여, 그 값과 찾고자 하는 값의 크고
 * 작음을 비교하는 방식을 채택하고 있다. 처음 선택한 중앙값이 만약 찾는
 * 값보다 크면 그 값은 새로운 최고값이 되며, 작으면 그 값은 새로운 최하값이 된다.
 * 검색 원리상 정렬된 리스트에만 사용할 수 있다는 단점이 있다.
 * 출처: https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
 *
 * @param array: 검색을 진행 할 배열의 주소
 * @param n: 검색을 진행 할 배열의 길이
 * @param value: 검색할 값
 * @return: 검색에 성공한 경우 원소의 index, 실패한경우 -1
 */
int binarySearch(int array[], int n, int value)
{
	int first=0, last, middle;
	first = 0;
	last = n - 1;
	middle = (first+last)/2;

	while (first <= last) {
		if (array[middle] < value)
			first = middle + 1;
		else if (array[middle] == value) {
			return middle;
			break;
		}
		else
			last = middle - 1;

		middle = (first + last)/2;
	}
	return -1;
}

/*
 * 주어진 배열에 대해 bubble sort를 진행한다.
 *
 * 거품 정렬(Bubble sort)은 두 인접한 원소를 검사하여 정렬하는 방법이다.
 * 정렬이 상당히 느리지만, 코드가 단순하기 때문에 자주 사용된다. 원소의
 * 이동이 거품이 수면으로 올라오는 듯한 모습을 보이기 때문에 지어진 이름이다.
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


int main(void)
{
	int array[10] = {3, 6, 4, 8, 9, 1, 2, 5, 7, 10};
	int find = 7;
	//binary search는 정렬된 리스트에만 적용 가능하다.
	//따라서, 검색을 진행하기 전 우선 bubble sort를 진행한다.
	bubbleSort(array, 10);

	printf("find %d on array as below\n", find);
	printArr(array, 10);

	//binary search를 통해서 값을 찾고, 인덱스를 출력한다.
	printf("found at index: %d", binarySearch(array, 5, find));

	return EXIT_SUCCESS;
}
