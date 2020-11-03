#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tree
{
	struct Tree *parent;
	int key;
	struct Tree *left;
	struct Tree *right;
}Tree;

Tree* allocTree()
{
	return calloc(1, sizeof(Tree));
}
void init(Tree **t)
{
	*t = allocTree();
	(*t)->parent = NULL;
	(*t)->left = NULL;
	(*t)->right = NULL;
	(*t)->key = 0;
}
void setTree(Tree **t,int key,Tree *parent)
{
	(*t)->parent = parent;
	(*t)->left = NULL;
	(*t)->right = NULL;
	(*t)->key = key;
}
bool isInternal(Tree *w)
{
	return w->left != NULL || w->right != NULL;
}
bool isExternal(Tree *w)
{
	return w->left == NULL && w->right == NULL;
}
void printTree(Tree *t)
{
	if (isExternal(t))
		return;
	printf(" %d", t->key);
	printTree(t->left);
	printTree(t->right);
}
Tree* treeSearch(Tree *t, int key)
{
	if (isExternal(t))
		return t;
	if (key == t->key)
		return t;
	else if (key < t->key)
	{
		return treeSearch(t->left, key);
	}
	else
	{
		return treeSearch(t->right, key);
	}
}

void insertItem(Tree **t, int key)
{
	Tree *new_left = allocTree();
	Tree *new_right = allocTree();
	Tree *new_tree = treeSearch(*t, key);

	new_tree->key = key;
	new_tree->left = new_left;
	new_tree->right = new_right;

	setTree(&new_left, 0, new_tree);
	setTree(&new_right, 0, new_tree);

}

Tree* Sibling(Tree *w)
{
	if (w->parent->left == w)
		return w->parent->right;
	return w->parent->left;
}
Tree* inOrderSucc(Tree *w)
{
	Tree *ptr = w->right;
	if (isExternal(w))
		return NULL;
	while (isInternal(ptr->left))
	{
		ptr = ptr->left;
	}
	return ptr;
}

Tree* reduceExternal(Tree **t ,Tree *ptr,Tree *z)
{
	Tree *w = z->parent;
	Tree *zs = Sibling(z);
	if (w->parent == NULL)	// isRoot()
	{
		zs->parent = NULL;
		*t = zs;
	}
	else
	{
		Tree *g = w->parent;
		zs->parent = g;
		if (w == g->left)
			g->left = zs;
		else
			g->right = zs;
	}
	free(z);
	free(w);
	return zs;
}
int findElement(Tree *t, int key)
{
	Tree *new_tree = treeSearch(t, key);
	if(isInternal(new_tree))
		return new_tree->key;
	return -1;
}

int removeElement(Tree **t,int key)
{
	Tree *ptr = treeSearch(*t, key);
	if (isExternal(ptr))
		return -1;
	int data = ptr->key;
	Tree *z = ptr->left;
	if (!isExternal(z))
		z = ptr->right;
	if (isExternal(z))
		reduceExternal(t,ptr,z);
	else
	{
		Tree *y = inOrderSucc(ptr);
		z = y->left;
		ptr->key = y->key;
		reduceExternal(*t,ptr,z);
	}
	//printf("removed: ");
	//printTree(*t);
	return data;
}


int main()
{
	Tree *tree;

	init(&tree);

	char menu;
	int key;

	while (true)
	{
		scanf("%c", &menu);
		

		switch (menu)
		{
			case 'i':
				scanf("%d", &key);
				insertItem(&tree, key);
				break;

			case 'd':
				scanf("%d", &key);
				key = removeElement(&tree, key);
				if (key == -1)
					printf("X\n");
				else
					printf("%d\n",key);
				break;
				
			case 's':
				scanf("%d", &key);
				if (findElement(tree, key)!=-1)
					printf("%d\n",key);
				else
					printf("X\n");
				break;

			case 'p':
				printTree(tree);
				printf("\n");
				break;

			case 'q':
				return 0;
			default:
				break;

		}
		getchar();
	}




	return 0;
}