#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>



void Merge(int *arr, int left,int mid, int right)
{
	int tmp[15] = { 0 };
	int i = left;
	int j = mid + 1;
	int k = left;
	int l;

	while (i<=mid&&j<=right)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];

	for (l = left; l <= right; l++)
		arr[l] = tmp[l];
}
void mergeSort(int *arr,int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr,mid+1,right);
		Merge(arr, left, mid, right);
	}
}

int main()
{

	int list[15];
	for (int i = 0; i < 15; i++)
		list[i] = rand() % 100;

	for(int i=0;i<15;i++)
		printf("%d ", list[i]);

	
	mergeSort(list,0, 15-1);
	printf("\nsorted:\n");
	for (int i = 0; i < 15; i++)
		printf("%d ", list[i]);


	return 0;
}