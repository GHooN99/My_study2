#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Heap
{
	int arr[MAX_SIZE];
	int size;
}Heap;

void initHeap(Heap *h)
{
	h->size = 0;
}
void upHeap(Heap *h)
{
	int	i = h->size;
	int key = h->arr[i];
	while (i!=1&&(key<h->arr[i/2]))
	{
		h->arr[i] = h->arr[i / 2];
		i /= 2;
	}
	h->arr[i] = key;
}
void downHeap(Heap* h)
{
	int tmp = h->arr[1];
	int parent = 1, child = 2;
	while (child<=h->size)
	{
		if ((child < h->size) && h->arr[child] > h->arr[child + 1])
			child++;
		if (tmp <= h->arr[child])
			break;
		h->arr[parent] = h->arr[child];
		// 내려가기
		parent = child;
		child *= 2;
	}
	h->arr[parent] = tmp;
}
void insertItem(Heap *h, int key)
{
	h->size++;
	h->arr[h->size] = key;
	upHeap(h);
}

void printHeap(Heap *h)
{
	for (int i = 1; i <= h->size; i++)
		printf("%d ", h->arr[i]);

	printf("\n");

}
int removeMin(Heap *h)
{
	int min = h->arr[1];
	h->arr[1] = h->arr[h->size--];
	downHeap(&h);

	return min;
}



int main()
{
	Heap h;
	initHeap(&h);
	insertItem(&h,5 );
	insertItem(&h,3 );
	insertItem(&h,7 );
	insertItem(&h, 4);
	insertItem(&h, 1);
	printHeap(&h);
	printf("%d\n", removeMin(&h));
	printHeap(&h);
	return 0;
}