#include <stdio.h>
#include "lib.h"

//int Getf(int x)
// 정렬될 순열의 x번째 원소의 값을 가져온다. (단 0이 시작값)

//void Putf(int x, int loc)
//순열의 loc번째 위치에 x값을 기록한다.

//int Sizef()
// 순열의 크기를 구한다. (n이 크기라면 원소는 0~n-1에 존재)

//void done()
// 정렬을 완료를 알리는 함수.

void quicksort(int left, int right){
	int i = left, j = right;
	int tmp;
	int pivot = Getf((left + right)/2);

	while(i<=j)
	{
		while(Getf(i) < pivot) i++;
		while(Getf(j) > pivot) j--;
		if(i<=j)
		{
			tmp = Getf(i);
			Putf(Getf(j), i);
			Putf(tmp, j);
			i++; j--;
		}
	}

	if(left < j)
	{
		quicksort(left, j);
	}
	if(i < right)
	{
		quicksort(i, right);
	}
}

int main(void)
{
	quicksort(0, Sizef()-1);
	done();
	return 0;
}
