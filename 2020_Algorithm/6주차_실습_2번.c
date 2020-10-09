#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int findPivot(int L,int R)
{
	srand(time(NULL));		//무작위 난수
	return rand() % (R - L+1) + L;		// 범위 설정 
}
void inPlacePartition(int arr[], int L, int R,int k,int *idx_a,int *idx_b)
{
	int pivot = arr[k];
	//swap(&arr[k], &arr[R]);		//hide
	int low = L;
	int high = R;
	int ptr = L; //같은때 포인터 도입

	//3 분할 알고리즘 
	while (ptr<=high)
	{
		if (arr[ptr] < pivot)
		{
			swap(&arr[low], &arr[ptr]);
			low++;
			ptr++;
		}
		else if(arr[ptr] > pivot)
		{
			swap(&arr[ptr], &arr[high]);
			high--;
		}
		else	//같은거 처리
		{
			ptr++;
		}

	}

	*idx_a = low;
	*idx_b = ptr-1;
	//for (int i = 0; i < R+1; i++)
		//printf(" %d", arr[i]);

}
void quickSort(int arr[], int L,int R)
{
	int idx_a, idx_b;
	if (L >= R)
		return;
	int k = findPivot(L, R);
	inPlacePartition(arr, L, R, k, &idx_a, &idx_b);
	quickSort(arr, L, idx_a - 1);
	quickSort(arr, idx_b + 1, R);
}

int main()
{

	int *arr,n;
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quickSort(arr,0,n-1);

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	free(arr);
	return 0;
}