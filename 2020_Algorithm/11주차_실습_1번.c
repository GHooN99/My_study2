#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct Node
{
	int vertex;
	int weight;
	struct Node *next;
}Node;

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void sort(Node *list)
{
	Node *ptr_i = list;
	Node *ptr_j = list;
	while (ptr_i!=NULL)
	{
		ptr_j = list;
		while (ptr_j->next!=NULL)
		{
			if ((ptr_j->vertex) > (ptr_j->next->vertex))
			{
				swap(&ptr_j->vertex, &ptr_j->next->vertex);
				swap(&ptr_j->weight, &ptr_j->next->weight);
			}
			ptr_j = ptr_j->next;
		}
		ptr_i = ptr_i->next;
	}
}

bool isValidVertex(int v)
{
	return (1 <= v && v <= 6);
}
bool isValidEdge(Node *adjList[],int a,int b,int weight)
{

	Node *ptr = adjList[a];

	while (ptr!=NULL)
	{
		if (ptr->vertex == b)
			return true;
		ptr = ptr->next;
	}

	return false;

}
Node* allocNode()
{
	return calloc(1,sizeof(Node));
}
void addVertex(Node **vertex,int name, int weight)
{
	
	if (*vertex == NULL)
	{
		*vertex = allocNode();
		(*vertex)->next = NULL;
		(*vertex)->vertex = name;
		(*vertex)->weight = weight;
		return;
	}
	Node *new_node = allocNode();
	new_node->next = *vertex;
	*vertex = new_node;

	new_node->vertex = name;
	new_node->weight = weight;

}
void deleteEdge(Node *adjList[], int a, int b)
{
	Node *ptr = adjList[a];
	Node *prev = NULL;
	while (ptr != NULL)
	{
		if (ptr->vertex == b)
		{
			if (prev != NULL)
				prev->next = ptr->next;

			else
				adjList[a] = ptr->next;

			free(ptr);
			return;
		}
		prev = ptr;
		ptr = ptr->next;
	}
}
void buildAdjList(Node *vertex[])
{
	addVertex(&vertex[1], 6, 2);
	addVertex(&vertex[1],4, 1);
	addVertex(&vertex[1], 3, 1);
	addVertex(&vertex[1], 2, 1);

	addVertex(&vertex[2], 3, 1);
	addVertex(&vertex[2], 1, 1);
	
	addVertex(&vertex[3], 5, 4);
	addVertex(&vertex[3], 2, 1);
	addVertex(&vertex[3], 1, 1);
	
	addVertex(&vertex[4], 1, 1);

	addVertex(&vertex[5], 6, 3);
	addVertex(&vertex[5], 5, 4);
	addVertex(&vertex[5], 3, 4);
	
	addVertex(&vertex[6],5, 3);
	addVertex(&vertex[6],1, 2);
}
void printNode(Node *list[],int v)
{
	if (!isValidVertex(v))
	{
		printf("-1\n");
		return;
	}
	Node *ptr = list[v];
	
	while (ptr!=NULL)
	{
		printf(" %d %d", ptr->vertex, ptr->weight);
		ptr = ptr->next;
	}
	printf("\n");
}
void changeWeight(Node *vertex[], int a, int b, int weight)
{
	Node *ptr = vertex[a];
	while (ptr != NULL)
	{
		if (ptr->vertex == b)
		{
			ptr->weight = weight;
			return;
		}

		ptr = ptr->next;
	}
}
void modifyGraph(Node *vertex[], int a, int b, int weight)
{
	if (!isValidVertex(a) || !isValidVertex(b))
	{
		printf("-1\n");
		return;
	}
	if (weight == 0)
	{
		deleteEdge(vertex, a, b);
		if(a!=b)
		deleteEdge(vertex, b, a);
		return;
	}
	
	if (isValidEdge(vertex, a, b, weight))
	{

		changeWeight(vertex, a, b, weight);
		if(a!=b)
		changeWeight(vertex, b, a, weight);
		return;
	}
		
	addVertex(&vertex[a], b, weight);
	if(a!=b)
	addVertex(&vertex[b], a, weight);

	sort(vertex[a]);
	if(a!=b)
	sort(vertex[b]);

}
int main()
{

	char menu;
	Node *adjList[7] = { NULL };
	int a,b,weight;

 	buildAdjList(adjList);

	while (true)
	{
		scanf("%c", &menu);
		switch (menu)
		{
			case 'a':
				scanf("%d", &a);
				printNode(adjList,a);
				break;
			case 'm':
				scanf("%d %d %d", &a, &b, &weight);
				modifyGraph(adjList, a, b, weight);
				break;

			case 'q':
				return 0;
			default:
				break;
		}

		getchar();
	}

}