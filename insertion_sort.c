#include <stdio.h>

void insertion_sort(int aTmp[], int size);
int main(void) 
{
	int array[10] = {5, 2, 6, 9, 3, 1, 4, 7, 0, 8};
	int temp, i, j = 0;
	int size = 0;
	
	printf("before insertion sort\n");
	
	size = sizeof(array)/ sizeof(array[0]);
	
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
		
	insertion_sort(array, size);
	
	printf("After insertion sort\n");
	
	for (i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}

#if 0
void insertion_sort(int aTmp[], int size) {
	int i, j = 0;
	int val = 0;
	
	for (i = 0; i <= size - 1; i++) {		
		for (j = i+1; j > 0 ; j--) {
			if (aTmp[j] < aTmp[j-1]) {
				val = aTmp[j-1];
				aTmp[j-1] = aTmp[j];
				aTmp[j] = val;  
			}
		}
	}
}
#endif

void insertion_sort(int aTmp[], int size) {
	int i,j = 0;
	int temp = 0;
	
	for (i = 1; i < size; i++) {
		temp = aTmp[i];	// insertion value
		
		for (j = i-1; j >= 0 && aTmp[j] > temp; j--) {
			aTmp[j+1] = aTmp[j];  
		}  
		
		aTmp[j+1] = temp;
	}
}
