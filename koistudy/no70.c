#include <stdio.h>

int main(void)
{
	int n;
	reload:     //레이블은 콜론( : ) 으로 끝난다. 
	scanf("%d", &n);
	if(n==0) return 0;
	printf("%d\n", n);
	goto reload; //reload라고 적혀있는 레이블로 실행 이동
}
