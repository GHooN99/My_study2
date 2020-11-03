#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARENT(x) ((x)/(2))
#define LEFT_CHILD(x) ((2)*(x))
#define RIGHT_CHILD(x) ((2)*(x)+(1))



void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void makeArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}
}
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void printHeap(int arr[], int n)
{
	for (int i = 1; i <= n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void insertionSort(int arr[], int n)
{

	for (int i = 1; i < n; i++)
	{
		int j = i-1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		printf("step : %d ->", i);
		printArr(arr, n);
	}
}
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;

		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		swap(&arr[i], &arr[min]);
		
		printf("step : %d ->", i);
		printArr(arr, n);
	}

}

void Merge(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int tmp[100];
	int k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];

	while (j <= right)
		tmp[k++] = arr[j++];

	for(int l=0;l<k;l++)
		arr[l+left] = tmp[l];

	printf("Merge ->");
	printArr(arr, left+k);
}
void mergeSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	Merge(arr, left, right);
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int idx = left - 1;
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= pivot)
			swap(&arr[++idx], &arr[i]);
	}
	swap(&arr[idx + 1], &arr[right]);
	printf("pivot : %d -> ", arr[idx + 1]);
	for (int k = left; k < right + 1; k++)
		printf("%d ", arr[k]);
	printf("\n");
	return idx + 1;

}
void quickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int pivot = Partition(arr, left, right);
	quickSort(arr, left, pivot - 1);
	quickSort(arr, pivot + 1, right);
}

void upHeap(int arr[], int i)
{
	if (i == 1)
		return;
	if (arr[i] <= arr[PARENT(i)])
		return;
	swap(&arr[i], &arr[PARENT(i)]);
	upHeap(arr,PARENT(i));
}
void downHeap(int arr[], int i,int n)
{
	if (LEFT_CHILD(i) > n && RIGHT_CHILD(i) > n)
		return;
	int bigger = LEFT_CHILD(i);

	if (RIGHT_CHILD(i) <= n)
		if (arr[bigger] < arr[RIGHT_CHILD(i)])
			bigger = RIGHT_CHILD(i);

	if (arr[i] >= arr[bigger])
		return;

	swap(&arr[i], &arr[bigger]);
	downHeap(arr,bigger,n);
}
void buildHeap(int arr[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		upHeap(arr, i);
	}
}
void heapSort(int arr[], int n)
{
	buildHeap(arr, n);
	printf("Heap-> : ");
	printHeap(arr, n);

	for (int i = 0; i <n-1; i++)
	{
		swap(&arr[1], &arr[n - i]);

		downHeap(arr,1,n-i-1);

		printf("arr-> : ");
		printHeap(arr, n);
	}
}



void partition(char str[], int idx)
{

	for (int i = 0; i < strlen(str); i++)
	{


		
	}





}




int main()
{
	
	char str[100];
	int idx;
	gets(str);

	scanf("%d", &idx);

	partition(str,n);
	return 0;
}