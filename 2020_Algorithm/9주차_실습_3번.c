#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Tree
{
	struct Tree *parent;
	int key;
	int height;
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
	(*t)->height = 0;
	(*t)->key = 0;
}
void setTree(Tree **t, int key, Tree *parent)
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
bool isRoot(Tree *w)
{
	return w->parent == NULL;
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

bool isBalanced(Tree *w)
{
	return abs((w->left->height) - (w->right->height)) < 2;
}
bool updateHeight(Tree *w)
{
	int h = w->left->height;
	if (h < w->right->height)
		h = w->right->height;
	h++;

	if (h != w->height)
	{
		w->height = h;
		return true;
	}

	return false;
}

Tree* Restructure(Tree **root, Tree *x, Tree *y, Tree* z)
{
	Tree *T0, *T1, *T2, *T3;
	Tree *a, *b, *c;
	int keyx = x->key;
	int keyy = y->key;
	int keyz = z->key;

	if (keyz < keyy && keyy < keyx)//1 
	{
		a = z; b = y; c = x;
		T0 = a->left; T1 = b->left;
		T2 = c->left; T3 = c->right;
	}
	else if (keyx < keyy && keyy < keyz)//2 
	{
		a = x; b = y; c = z;
		T0 = a->left; T1 = a->right;
		T2 = b->right; T3 = c->right;
	}
	else if (keyz < keyx && keyx < keyy)//3 
	{
		a = z; b = x; c = y;
		T0 = a->left; T1 = b->left;
		T2 = b->right; T3 = c->right;
	}
	else
	{
		a = y; b = x; c = z;
		T0 = a->left; T1 = b->left;
		T2 = b->right; T3 = c->right;
	}


	if (isRoot(z))
	{
		*root = b;
		b->parent = NULL;
	}
	else if (z->parent->left == z)
	{
		z->parent->left = b;
		b->parent = z->parent;
	}
	else
	{
		z->parent->right = b;
		b->parent = z->parent;
	}


	a->left = T0;
	a->right = T1;

	T0->parent = a;
	T1->parent = a;
	updateHeight(a);

	c->left = T2;
	c->right = T3;
	T2->parent = c;
	T3->parent = c;
	updateHeight(c);

	b->left = a;
	b->right = c;

	a->parent = b;
	c->parent = b;

	updateHeight(b);

	return b;





}
void searchAndFixAfterInsertion(Tree **root, Tree *w)
{
	w->left->height = 0;
	w->right->height = 0;
	w->height = 1;
	if (isRoot(w))
		return;
	Tree *z = w->parent;
	Tree *x, *y;
	while (updateHeight(z) && isBalanced(z))
	{
		if (isRoot(z))
			return;
		z = z->parent;
	}
	if (isBalanced(z))
		return;

	if (z->left->height > z->right->height)
		y = z->left;
	else
		y = z->right;

	if (y->left->height > y->right->height)
		x = y->left;
	else
		x = y->right;

	Restructure(root, x, y, z);

}
void expandExternal(Tree *w)
{
	Tree *new_left = allocTree();
	Tree *new_right = allocTree();

	setTree(&new_left, 0, w);
	new_left->height = 0;
	setTree(&new_right, 0, w);
	new_right->height = 0;

	w->left = new_left;
	w->right = new_right;
	w->height = 1;

}
void insertItem(Tree **t, int key)
{
	Tree *new_tree = treeSearch(*t, key);

	new_tree->key = key;
	expandExternal(new_tree);
	searchAndFixAfterInsertion(t, new_tree);

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

Tree* reduceExternal(Tree **t, Tree *ptr, Tree *z)
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
	if (isInternal(new_tree))
		return new_tree->key;
	return -1;
}

void searchAndFixAfterRemoval(Tree **root, Tree *z)
{
	while (updateHeight(z) && isBalanced(z))
	{
		if (isRoot(z))
			return;
		z = z->parent;
	}
	if (isBalanced(z))
		return;
	Tree *x, *y;
	//fix 

	if (z->left->height > z->right->height)
		y = z->left;
	else
		y = z->right;


	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	else
	{
		if (z->left == y)
			x = y->left;
		else
			x = y->right;
	}
	Tree *b = Restructure(root, x, y, z);
	if (isRoot(b))
		return;
	searchAndFixAfterRemoval(root, b->parent);

}
int removeElement(Tree **t, int key)
{
	Tree *ptr = treeSearch(*t, key);
	Tree *zs;
	if (isExternal(ptr))
		return -1;
	int data = ptr->key;
	Tree *z = ptr->left;
	if (!isExternal(z))
		z = ptr->right;
	if (isExternal(z))
		zs= reduceExternal(t, ptr, z);
	else
	{
		Tree *y = inOrderSucc(ptr);
		z = y->left;
		ptr->key = y->key;
		zs = reduceExternal(t, ptr, z);
	}
	searchAndFixAfterRemoval(t,zs->parent);
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
				printf("%d\n", key);
			break;

		case 's':
			scanf("%d", &key);
			if (findElement(tree, key) != -1)
				printf("%d\n", key);
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