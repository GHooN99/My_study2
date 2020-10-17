#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>




int bSearch(int *dic, int left, int right, int key)
{
	int n = right;
	int mid;

	while (left<=right)
	{
		mid = (left + right) / 2;
		if (dic[mid] == key)
			return mid;

		else if (dic[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	if (dic[n] < key)
		return n+1;

	return left;

}

int main()
{

	int n, k, idx = -1;
	int *dic;
	scanf("%d %d", &n, &k);

	dic = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &dic[i]);

	idx = bSearch(dic, 0, n - 1, k);
	printf(" %d", idx);
	free(dic);
	return 0;
}