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
void printArr(int *arr)
{
	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void selectionSort(int *arr,int n)	//선택 정렬
{
	for (int i = 0; i < n-1; i++)
	{
						//int idx = i;
		int minidx;		//int min = arr[i];
		for (int j = i + 1; j < n; j++)
		{
			minidx = i;
			if (arr[j] < arr[minidx])
				minidx = j;
		}
		swap(&arr[i], &arr[minidx]);
		printArr(arr);
	}

}
void insertionSort(int *arr, int n)		//삽입 정렬
{
	for (int i = 1; i < n ; i++)
	{
		int n = arr[i];
		int j = i - 1;
		while (j >= 0 && n < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = n;
	}

}
void bubbleSort(int *arr, int n)		//버블정렬
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}

	}

}
void AinsertionSort(int *arr, int start , int end ,int gap)		//향상된 삽입 정렬
{
	for (int i = start + gap; i <= end; i+=gap)
	{
		int n = arr[i];
		int j = i-gap;
		while (j >= start && n < arr[j])
		{
			arr[j + gap] = arr[j];
			j-=gap;
		}
		arr[j + gap] = n;
	}

}
void shellSort(int *arr, int n)
{
	int gap ;
	for (gap = n/2; gap>0; gap/=2)
	{
		if (gap % 2 == 0) gap++;
		for (int i = 0; i < gap; i++)
			AinsertionSort(arr, i, n - 1, gap);
	}

}
int main()
{
	int *arr,n;
	
	scanf("%d", &n);
	arr = (int*)calloc(1)
	return 0;
}