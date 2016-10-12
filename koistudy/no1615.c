#include <stdio.h>
#include <string.h>

int main(void)
{
	int n = 0, m = 0;
	int i, j;
	scanf("%d %d", &n, &m);
	int arr[n][m];

	for (i=0 ; i<n; i++)
	{
		memset( arr[i], 0, sizeof(int) * m );
	}

	//set array
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	//caculate cumulative sum
	for(j=1; j<m; j++)
	{
		arr[0][j] = arr[0][j] + arr[0][j-1];
	}
	for(i=1; i<n; i++)
	{
		arr[i][0] = arr[i][0] + arr[i-1][0];
		for(j=1; j<m; j++)
		{
			arr[i][j] = arr[i][j] + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
		}
	}

	//print array
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
