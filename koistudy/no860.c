#include <stdio.h>
#include <string.h>
#include <math.h>

long long prime_number(int k, long long *array)
{
	if(array[k] != 0) //다이나믹프로그래밍
	{
		return array[k];
	}
	else
	{
		int flag = 0;
		int divide_flag = 0;
		int i;
		if(array[k-1] == 0)
		{
			array[k-1] = prime_number(k-1, array);
		}
		int ans = array[k-1];
		while(!flag)
		{
			ans++; divide_flag = 0;
            #
			for(i=1; i<=sqrt((double)k); i++)//에라토스테네스의 체
			{
				if(ans % array[i] == 0)//   소수들 중 하나로만 나누어 떨어진다면
				{
					divide_flag = 1;//      그 숫자는 소수가 아니다.
				}
				if(divide_flag)
					break;
			}
			if(!divide_flag)
				flag = 1;
		}
		return ans;
	}
}

int main(void)
{
	int k;
	long long ans;

	scanf("%d", &k);

	long long array[k+1];
	memset( array, 0, (k+1)*sizeof(long long) );
	array[1] = 2;

	ans = prime_number(k, array);
	printf("%d", ans);
}
