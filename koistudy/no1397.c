#include <stdio.h>

int main(void)
{
	int size, count, begin, end, i;
	long long int height;
	scanf("%d %d", &size, &count);
	
	//init world
	long long int world[size+1];
	memset( world, 0, (size+1)*sizeof(long long int) );
	
	//snowy
	for(i=0; i<count; i++)
	{
		scanf("%d %d %lld", &begin, &end, &height);
		do {
			world[begin] = world[begin] + height;
			begin = begin + 1;
		} while(begin <= end);
	}
	
	//print world
	for(i=1; i<=size; i++)
	{
		printf("%lld ", world[i]);
	}
	
	return 0;
}
