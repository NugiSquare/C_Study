#include <stdio.h>

int main(void)
{
	int i, j;
	int ax = 1;
	int ay = 1;
	int board[10][10] = {};
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	do {
		if(board[ax][ay] == 2) {
			board[ax][ay] = 9; break;
		} else { board[ax][ay] = 9;}
		if(board[ax+1][ay] == 1 && board[ax][ay+1] == 1)
			break;
		else if(board[ax][ay+1] == 1) {
			ax++;
		}
		else {
			ay++;
		}
	} while(1);
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}
