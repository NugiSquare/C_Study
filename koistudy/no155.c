#include <stdio.h>

long long fib(int n, long long *array)
{
	if(n<3) return array[n];
	else
	{
		if(array[n-1] == 0) fib(n-1, array);
		if(array[n-2] == 0) fib(n-2, array);
		return array[n] = array[n-1] + array[n-2];
	}
}

int main(void)
{
	int n;
	long long result;
	long long array[91] = {0, 1, 1, };
	scanf("%d", &n);
	result = fib(n, array);
	printf("%lld", result);
	return 0;
}
