#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct HashTable
{
	int key;

}HashTable;

int hashFunction(int x, int M)
{
	return x % M;
}
int hashFunction2(int x,int q)
{
	return q - (x%q);
}
bool isEmpty(HashTable ht)
{
	return ht.key == 0;
}
void init(HashTable *ht, int M)
{
	for (int i = 0; i < M; i++)
		ht[i].key = 0;
}
void printHashTable(HashTable ht[], int M)
{
	for (int i = 0; i < M; i++)
		printf("%d ", ht[i].key);
}
int getNextBucket(int v, int i, int M,int q,int key)
{
	return (v + i*hashFunction2(key,q)) % M;
}

void insertItem(HashTable ht[], int key, int M,int q)
{
	int v = hashFunction(key, M);
	for (int i = 0; i < M; i++)
	{
		int b = getNextBucket(v, i, M,q,key);
		if (isEmpty(ht[b]))
		{
			printf("%d\n", b);
			ht[b].key = key;
			return;
		}
		printf("C");
	}
}
int findElement(HashTable ht[], int key, int M,int q)
{
	int v = hashFunction(key, M);
	for (int i = 0; i < M; i++)
	{
		int b = getNextBucket(v, i, M,q,key);
		if (isEmpty(ht[b]))
		{
			return -1;
		}
		else if (key == ht[b].key)
		{
			printf("%d ", b);
			return ht[b].key;
		}
	}
}
int main()
{
	HashTable *ht;

	int M, n, q,key;
	char menu;
	scanf("%d %d %d", &M, &n,&q);
	ht = (HashTable*)calloc(M, sizeof(HashTable));
	init(ht, M);
	getchar();
	while (true)
	{
		scanf("%c", &menu);
		switch (menu)
		{
		case 'i':
			scanf("%d", &key);
			insertItem(ht, key, M,q);
			break;
		case 's':
			scanf("%d", &key);
			int find = findElement(ht, key, M,q);
			printf("%d\n", find);

			break;

		case 'p':
			printHashTable(ht, M);
			printf("\n");
			break;
		case 'e':
			printHashTable(ht, M);
			free(ht);
			return 0;
		default:
			break;
		}


		getchar();
	}




	return 0;
}