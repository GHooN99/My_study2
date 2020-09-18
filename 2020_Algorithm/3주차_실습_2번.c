#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void printArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}

void insertionSort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = arr[i];
		int j = i -1;
		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		//printArr(arr, n);
		//printf("\n");
	}
}

int main()
{
	int *arr, n;

	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);

	insertionSort(arr, n);

	printArr(arr, n);

	free(arr);

	return 0;
}