#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void printArr(int *arr,int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}
void selectionSort(int *arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int max_idx = n -i- 1;
		for (int j = 0; j < n - i-1; j++)
		{
			if (arr[j] > arr[max_idx])
				max_idx = j;
		}
		swap(&arr[max_idx], &arr[n - i - 1]);
	}
}

int main()
{
	int *arr, n;
	
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	
	selectionSort(arr, n);

	printArr(arr, n);

	free(arr);

	return 0;
}