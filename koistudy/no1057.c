#include <stdio.h>

int main(void)
{
	int i, n, k, tmp, answer;
	answer = 0;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &tmp);
		if(tmp >= k && answer == 0) answer = i;
	}
	if(answer != 0) printf("%d", answer);
	else printf("%d", n+1);
	return 0;
}
