#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

Node* allocNode()
{
	return calloc(1, sizeof(Node));
}
int sizeOfList(Node *list)
{
	Node *ptr = list;
	int cnt = 0;

	while (ptr != NULL)
	{
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}
void addLast(Node **list, int data)
{
	if ((*list)->data == -1)
	{
		(*list)->data = data;
		return;
	}
	Node *ptr = (*list);
	
	while (ptr->next!=NULL)
		ptr = ptr->next;
	
	Node *new_node = allocNode();
	new_node->data = data;
	new_node->next = NULL;
	ptr->next = new_node;
}
void printList(Node *list)
{
	Node *ptr = list;
	while (ptr!=NULL)
	{
		printf(" %d", ptr->data);
		ptr = ptr->next;
	}

}

Node* Merge(Node **L1, Node **L2)
{
	Node *L = allocNode();

	Node *ptr;
	Node *ptr_L1 = *L1, *ptr_L2 = *L2;

	//init setting
	if (ptr_L1->data < ptr_L2->data)
	{
		L = ptr_L1;
		ptr_L1 = ptr_L1->next;
		ptr = L;
	}
	else
	{
		L = ptr_L2;
		ptr_L2 = ptr_L2->next;
		ptr = L;
	}
	// loop
	while (ptr_L1!=NULL && ptr_L2!=NULL)
	{
		if (ptr_L1->data < ptr_L2->data)
		{
			ptr->next = ptr_L1;
			ptr_L1 = ptr_L1->next;
		
		}
		else
		{
			ptr->next = ptr_L2;
			ptr_L2 = ptr_L2->next;
		}
		ptr = ptr->next;
	}
	// ³ª¸ÓÁö
	while (ptr_L1 != NULL)
	{
		ptr->next = ptr_L1;
		ptr = ptr_L1;
		ptr_L1 = ptr_L1->next;
	}
	while (ptr_L2 != NULL)
	{
		ptr->next = ptr_L2;
		ptr = ptr_L2;
		ptr_L2 = ptr_L2->next;
	}

	return L;
}
void partition(Node **list, Node **L1, Node **L2, int k)
{

	Node *ptr = *list;

	*L1 = *list;

	for (int i = 0; i < k-1; i++)
		ptr = ptr->next;

	*L2 = ptr->next;
	ptr->next = NULL;

}
void mergeSort(Node **list)
{
	Node *L1, *L2;
	L1 = allocNode();
	L2 = allocNode();

	if (sizeOfList(*list) > 1)
	{
		partition(list, &L1, &L2, sizeOfList(*list) / 2);

		//printList(L1);
		//printf("\n");
		//printList(L2);
		//printf("\n");
		mergeSort(&L1);
		mergeSort(&L2);

		*list = Merge(&L1, &L2);
		//printList(*list);
	}

}

int main()
{
	Node *list = allocNode();
	list->data = -1;
	list->next = NULL;


	int n,data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		addLast(&list,data);
	}
	mergeSort(&list);

	printList(list);

	return 0;
}