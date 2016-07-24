#include <stdio.h>

int main(void)
{
	int n, i, tmp, tmp_index;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	/* Selection Sort */
	for(i=1; i<n; i++){
	      tmp = arr[i];
	      tmp_index = i-1;
	
	      while((tmp_index >= 0) && (arr[tmp_index] > tmp)) {
	         arr[tmp_index+1] = arr[tmp_index];
	         tmp_index--;
	      }
	      
	      arr[tmp_index + 1] = tmp;
	}
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
}
