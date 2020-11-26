#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10

typedef struct Node
{
	int vertex;
	struct Node *next;
}Node;
typedef struct Stack
{
	Node *arr[SIZE];
	int size;
}Stack;
bool isEmptyStack(Stack *st)
{
	return st->size == 0;
}
void initStack(Stack *st)
{
	st->size = 0;
}
Node* Top(Stack *st)
{
	return st->arr[st->size - 1];
}
void Push(Stack *st, Node *data)
{
	st->arr[st->size++] = data;
}
void Pop(Stack *st)
{
	st->arr[--(st->size)] = NULL;
}


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
	while (ptr_i != NULL)
	{
		ptr_j = list;
		while (ptr_j->next != NULL)
		{
			if ((ptr_j->vertex) > (ptr_j->next->vertex))
				swap(&ptr_j->vertex, &ptr_j->next->vertex);

			ptr_j = ptr_j->next;
		}
		ptr_i = ptr_i->next;
	}
}
bool isValidVertex(int v)
{
	return (1 <= v && v <= SIZE);
}
Node* allocNode()
{
	return calloc(1, sizeof(Node));
}
void addVertex(Node **adjList, int vertex, int data)
{
	if (!isValidVertex(vertex))
	{
		printf("Invalid Vertex!\n");
		return;
	}
	if (adjList[vertex] == NULL)
	{
		adjList[vertex] = allocNode();
		adjList[vertex]->next = NULL;
		adjList[vertex]->vertex = data;
		return;
	}
	Node *new_node = allocNode();
	new_node->next = adjList[vertex];
	adjList[vertex] = new_node;
	new_node->vertex = data;
}

void printAdjList(Node *list[], int n)
{
	for (int i = 1; i <= n; i++)
	{
		Node *ptr = list[i];
		printf("정점 %d:", i);
		while (ptr != NULL)
		{
			printf("->%d ", ptr->vertex);
			ptr = ptr->next;
		}
		printf("\n");
	}

}

void Dfs(Node *adjlist[], int s)
{
	bool visited[SIZE] = { false };
	Stack st;

	initStack(&st);

	Push(&st, adjlist[s]);
	visited[s] = true;
	printf("%d 방문\n", s);

	while (!isEmptyStack(&st))
	{
		Node *ptr = Top(&st);
		while (true)
		{
			if (ptr == NULL)
			{
				Pop(&st);
				break;
			}
			if (!visited[ptr->vertex])
			{
				s = ptr->vertex;
				visited[s] = true;
				Push(&st, adjlist[s]);
				printf("%d 방문\n", s);
				break;
			}

			ptr = ptr->next;
		}

	}

}
int main()
{
	Node *adjList[SIZE] = { NULL };
	int start, end;
	int n;

	printf("정점의 개수 입력:");
	scanf("%d", &n);

	printf("시작점 끝점 입력 (끝났을시 0 0 입력)\n");
	while (true)
	{
		scanf("%d %d", &start, &end);
		if (start == 0 && end == 0) break;
		addVertex(adjList, start, end);
		addVertex(adjList, end, start);
	}
	

	for (int i = 1; i <= n; i++)
		sort(adjList[i]);

	printAdjList(adjList, n);

	Dfs(adjList, 1);


	return 0;

}
