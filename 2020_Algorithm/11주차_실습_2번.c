#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isValidVertex(int v)
{
	return (1 <= v && v <= 6);
}

void printNode(int adjMatrix[7][7],int a)
{
	if (!isValidVertex(a))
	{
		printf("-1\n");
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		if (adjMatrix[a][i] != 0)
			printf(" %d %d", i, adjMatrix[a][i]);
	}
	printf("\n");

}

void deleteEdge(int adjMatrix[7][7], int a, int b)
{
	adjMatrix[a][b] = 0;
	adjMatrix[b][a] = 0;
}
void changeWeight(int adjMatrix[7][7], int a, int b,int weight)
{
	adjMatrix[a][b] = weight;
	adjMatrix[b][a] = weight;
}
void modifyGraph(int adjMatrix[7][7], int a, int b, int weight)
{

	if (!isValidVertex(a) || !isValidVertex(b))
	{
		printf("-1\n");
		return;
	}

	if (weight == 0)
	{
		deleteEdge(adjMatrix, a, b);
		return;
	}

	changeWeight(adjMatrix, a, b, weight);

}
int main()
{

	char menu;
	int adjMatrix[7][7] = 
	{
	{0,0,0,0,0,0,0},
	{0,0,1,1,1,0,2},
	{0,1,0,1,0,0,0},
	{0,1,1,0,0,4,0},
	{0,1,0,0,0,0,0},
	{0,0,0,4,0,4,3},
	{0,2,0,0,0,3,0}
	};

	int a,b,weight;


	while (true)
	{
		scanf("%c", &menu);
		switch (menu)
		{
			case 'a':
				scanf("%d", &a);
				printNode(adjMatrix,a);
				break;
			case 'm':
				scanf("%d %d %d", &a, &b, &weight);
				modifyGraph(adjMatrix, a, b, weight);
				break;

			case 'q':
				return 0;
			default:
				break;
		}

		getchar();
	}

}