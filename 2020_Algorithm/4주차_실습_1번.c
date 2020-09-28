#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100
#define RIGHT_CHILD(X) ((2)*(X)+(1))
#define LEFT_CHILD(X) ((2)*(X))
#define PARENT(X) ((X)/(2))

int H[MAX_SIZE] = { 0 };
int n = 0;



void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void upHeap(int i)
{
	if (i == 1)
		return;
	if (H[i] <= H[PARENT(i)])
		return;
	swap(&H[i],&H[PARENT(i)]);
	upHeap(PARENT(i));
}
void downHeap(int i)
{
	if (LEFT_CHILD(i)>n && RIGHT_CHILD(i)>n)
		return;
	int bigger = LEFT_CHILD(i);

	if(RIGHT_CHILD(i) <= n)
		if (H[bigger] < H[RIGHT_CHILD(i)])
			bigger =RIGHT_CHILD(i);

	if (H[i] >= H[bigger])
		return;

	swap(&H[i], &H[bigger]);
	downHeap(bigger);
}


void insertItem(int key)
{
	H[++n] = key;
	upHeap(n);
	printf("0\n");
}
int removeMax()
{
	int key = H[1];
	H[1] = H[n--];

	downHeap(1);
	return key;
}
void printHeap()
{
	for (int i = 1; i < n+1; i++)
		printf(" %d", H[i]);
	printf("\n");
}

int main()
{
	char menu;
	int key;
	while (true)
	{
		scanf("%c", &menu);
		switch (menu)
		{
			case 'i':
				scanf("%d", &key);
				getchar();
				insertItem(key);
				break;

			case 'd':
				key = removeMax();
				printf("%d\n", key);
				break;

			case 'p':
				printHeap();
				break;

			case 'q':
				return 0;

			default:
				break;
		}
	}
}