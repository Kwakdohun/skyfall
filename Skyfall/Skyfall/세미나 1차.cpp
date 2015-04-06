#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int card[4][13] = { { 65, 2, 3, 4, 5, 6, 7, 8, 9, 10, 74, 'Q', 'K' },
					{ 65, 2, 3, 4, 5, 6, 7, 8, 9, 10, 74, 'Q', 'K' },
					{ 65, 2, 3, 4, 5, 6, 7, 8, 9, 10, 74, 'Q', 'K' },
					{ 65, 2, 3, 4, 5, 6, 7, 8, 9, 10, 74, 'Q', 'K' } };
void hole(int i, int j)
{
	

	
			if (card[i][j] == 65)
				printf("%c", card[i][j]);
			if (card[i][j] == 74)
				printf("%c", card[i][j]);
			if (card[i][j] == 81)
				printf("%c", card[i][j]);
			if (card[i][j] == 75)
				printf("%c", card[i][j]);
			if (card[i][j] >= 2 && card[i][j] <= 10)
				printf("%d", card[i][j]);
		
		printf("\n");
	
}
void grim(int c)
{
	if (c == 0)
		printf("¢½");
	if (c == 1)
		printf("¢»");
	if (c == 2)
		printf("¢¿");
	if (c == 3)
		printf("¡Þ");
}

void main()
{

	while (1)
	{
	srand((unsigned)time(NULL));
	int a, b;
	a = rand() % 4;
	b = rand() % 13;
	grim(a);
	hole(a,b);
	printf("\n");
	card[a][b] = 0;
	
		if (card[a][b] == 0)
		{
			a = rand() % 4;
			b = rand() % 13;
			hole(a, b);
		}
		else
		{
			hole(a, b);
			break;
		}
	}
}

