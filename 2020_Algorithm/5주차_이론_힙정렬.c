#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define RIGHT_CHILD(X) ((2)*(X)+(1))
#define LEFT_CHILD(X) ((2)*(X))
#define PARENT(X) ((X)/(2))


typedef struct Heap
{
	int arr[MAX_SIZE];
	int size;
}Heap;

void initHeap(Heap *h)
{
	h->size = 0;
}
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void upHeap(Heap *h,int i)
{
	if (i == 1) return;
	if (h->arr[i] <= h->arr[PARENT(i)]) return;
	swap(&h->arr[i],&h->arr[PARENT(i)]);
	upHeap(h, PARENT(i));
}
void downHeap(Heap *h, int i)
{
	if (LEFT_CHILD(i) > h->size&&RIGHT_CHILD(i) > h->size)
		return;
	int bigger = LEFT_CHILD(i);

	if (RIGHT_CHILD(i) <= h->size)
	{
		if (h->arr[bigger] < h->arr[RIGHT_CHILD(i)])
			bigger = RIGHT_CHILD(i);
	}
	if (h->arr[bigger] <= h->arr[i])
		return;
	swap(&h->arr[i],&h->arr[bigger]);
	downHeap(h, bigger);
}
void insertItem(Heap *h, int data)
{
	h->arr[++(h->size)] = data;
	upHeap(h, h->size);
}
int removeMax(Heap *h)
{
	int key = h->arr[1];
	h->arr[1] = h->arr[h->size--];
	downHeap(h,1);
	return key;
}
void HeapSort(Heap *h)
{
	for(int i=0;i<10;i++)
		printf("%d ", removeMax(h));
}
void printHeap(Heap *h)
{
	for (int i = 1; i <= h->size; i++)
		printf("%d ", h->arr[i]);

	printf("\n");

}
void inPlaceHeapSort(Heap *h)
{
	int size = h->size;
	for (int i = 1; i < size; i++)
	{
		swap(&h->arr[1], &h->arr[h->size--]);
		downHeap(h, 1);
		printHeap(h);
	}

}

int main()
{

	Heap heap;
	initHeap(&heap);
	
	for (int i = 0; i < 10; i++)
	{
		int data = rand() % 100;
		printf("%d ", data);
		insertItem(&heap, data);
	}
	printf("\n");
	printHeap(&heap);
	printf("\n");
	inPlaceHeapSort(&heap);
	printf("inplace heap sort\n");
	for (int i = 1; i < 10; i++)
		printf("%d ", heap.arr[i]);
	
	

	return 0;
}





