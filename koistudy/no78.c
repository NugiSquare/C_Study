#include <stdio.h>

int main(void)
{
	char a;
	while(1) {
		scanf("%c", &a);
		printf("%c", a);
		if(a == 'q') return 0;
	}
}
