#include <stdio.h>
int card[4][13] = { { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' } };
void hole()
{
	int i, j;

	for (i = 0; i < 4; i++){
		for (j = 0; j < 13; j++){
			if (card[i][j] ==65)
				printf("%c", card[i][j]);
			if (card[i][j] == 74)
				printf("%c", card[i][j]);
			if (card[i][j] == 81)
				printf("%c", card[i][j]);
			if (card[i][j] == 75)
				printf("%c", card[i][j]);
			if (card[i][j] >= 2 && card[i][j]<=10)
				printf("%d", card[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	hole();
}