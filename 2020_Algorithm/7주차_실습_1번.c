#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>



int bSearch(int *dic, int left, int right, int key)
{
	if (left > right)
	{
		if (key<dic[0])
			return -1;
		return left - 1;
	}
	int mid = (left + right) / 2;
	if (dic[mid] == key)
		return mid;
	else if (dic[mid] > key)
		bSearch(dic, left, mid - 1, key);
	else
		bSearch(dic, mid + 1, right,key);
	
}


int main()
{

	int n,k,idx=-1;
	int *dic;
	scanf("%d %d", &n, &k);

	dic = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d",&dic[i]);

	idx = bSearch(dic, 0, n - 1, k);
	printf(" %d", idx);
	free(dic);
	return 0;
}