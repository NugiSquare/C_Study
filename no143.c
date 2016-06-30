#include <stdio.h>

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	
	while(i <= j) {
		while(arr[i]<pivot) i++;
		while(arr[j]>pivot) j--;
		if(i<=j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	
	if(left<j) quickSort(arr, left, j);
	if(i<right) quickSort(arr, i, right);
}

int main(void)
{
	int n, i;
	scanf("%d", &n);
	int arr[n];
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quickSort(arr, 0, i);
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
}
