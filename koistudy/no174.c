#include <stdio.h>

long long an(int input)
{
	int i;
	long long output = 0;
	for(i=1; i<=input; i++)
	{
		output = output + i;
	}
	return output;
}

int main(void)
{
	int input, i;
	long long answer = 0;
	scanf("%d", &input);
	for(i=1; i<=input; i++) {
		answer = answer + an(i);
	}
	printf("%lld", answer);
	return 0;
	
	// another solution
	// int n, i;
	// long long an = 0, sum = 0;
	// scanf("%d", &n);
	// for(i=1; i<=n; i++) {
	// 	an = an + i;
	// 	sum = sum + an;
	// }
	// printf("lld", sum);
	// return 0;
}
