#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int solve(int left, int right, char *str)
{
	int len = strlen(str);
	int mid = (left + right) / 2;
	int k = mid;
	for (int i = 0; i < len; i++)
	{
		mid = (left + right) / 2;

		if (str[i] == 'Y')
		{
			left = mid + 1;
		}

		else if (str[i] == 'N')
		{
			right = mid;
		}
	}

	return left;

}




int main()
{
	int a, b, n,k;
	char *str;

	scanf("%d %d %d", &a, &b, &n);
	str = (char*)calloc(n, sizeof(char));
	getchar();
	scanf("%s", str);

	
	k = solve(a,b,str);
	printf("%d", k);

	return 0;
}