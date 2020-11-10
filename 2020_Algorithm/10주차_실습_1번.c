#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



typedef struct Node
{
	int key;
	struct Node *next;
}Node;

Node* allocNode()
{
	return calloc(1, sizeof(Node));
}
void init(Node *ht[],int M)
{
	for (int i = 0; i < M; i++)
		ht[i] = NULL;
}

int hashFunction(int x, int M)
{
	return x % M;
}

void insertItem(Node *ht[], int key,int M)
{
	int v = hashFunction(key, M);

	if (ht[v] == NULL)
	{
		ht[v] = allocNode();
		ht[v]->key = key;
		ht[v]->next = NULL;
		return;
	}

	Node *new_node = allocNode();
	new_node->next = ht[v];
	ht[v] = new_node;
	new_node->key = key;
	
	
}
int findElement(Node *ht[], int key,int M)
{
	int v = hashFunction(key, M);

	Node *ptr = ht[v];
	int cnt = 1;
	while (ptr!=NULL)
	{
		if (ptr->key == key)
			return cnt;
		ptr = ptr->next;
		cnt++;
	}
	return 0;

}
int removeElement(Node *ht[], int key, int M)
{
	int v = hashFunction(key, M);

	Node *ptr = ht[v];
	Node *prev = NULL;
	int cnt = 1;
	while (ptr != NULL)
	{
		if (ptr->key == key)
		{
			//삭제 연결
			if (prev != NULL)
				prev->next = ptr->next;
			else
				ht[v] = ptr->next;

			free(ptr);
			return cnt;
		}
		prev = ptr;
		ptr = ptr->next;
		cnt++;
	}
	return 0;
}
void printHashTable(Node *ht[], int M)
{
	for (int i = 0; i < M; i++)
	{
		Node *ptr = ht[i];
		while (ptr!=NULL)
		{
			printf(" %d", ptr->key);
			ptr = ptr->next;
		}
	}
	printf("\n");
}

int main()
{
	int M, key,find;
	char menu;
	Node **ht;


	scanf("%d", &M);

	ht = (Node**)calloc(M, sizeof(Node*));
	init(ht, M);
	getchar();

	while (true)
	{
		scanf("%c", &menu);
		switch (menu)
		{
		case 'i':
			scanf("%d", &key);
			insertItem(ht, key,M);
			break;
		case 's':
			scanf("%d", &key);
			find = findElement(ht, key,M);
			printf("%d\n", find);
			break;

		case 'd':
			scanf("%d", &key);
			find = removeElement(ht, key, M);
			printf("%d\n", find);
			break;
		case 'p':
			printHashTable(ht, M);
			printf("\n");
			break;
			
		case 'e':
			return 0;
		default:
			break;
		}
	}
}