#include <stdio.h>

int main(void)
{
	int cities, i;
	scanf("%d", &cities);
	printf("%d\n", cities);
	for(i=1; i<cities; i++)
	{
		printf("%d %d\n", i, i+1);
	}
	printf("%d %d\n", cities, 1);
	return 0;
}
