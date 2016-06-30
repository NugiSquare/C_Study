#include <stdio.h>

int main(void)
{
	int i, n, k;
	int ans = -1;
	scanf("%d %d", &n, &k);
	int array[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
	}
	for(i=0; i<n; i++)
	{
		if(array[i] == k)
		{
			ans = i+1;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}
