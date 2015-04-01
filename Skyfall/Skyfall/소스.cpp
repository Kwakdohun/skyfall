#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int card[4][13] = { { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' } };

void suits(int num) //¸ð¾çÀ» »Ì°Ù´Ù.
{
	switch (num)
	{
	case 0: printf("¢À"); break;
	case 1: printf("¢¾"); break;
	case 2: printf("¡ß"); break;
	case 3: printf("¢¼"); break;
	}
}
void hole1()
{
	int i, j;

	for (i = 0; i < 4; i++){
		suits(i);
		for (j = 0; j < 13; j++){
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
		}
		printf("\n");
	}
}
void hole(int num1, int num2)
{
	while (1){
		if (card[num1][num2] == 0) //ÀÌ¹Ì »ÌÀº Ä«µå¸¦ »ÌÀ»½Ã ´Ù½Ã ·£´ýÇÔ¼ö¸¦ µ¹¸°´Ù.
		{
			num1 = rand() % 4;
			num2 = rand() % 13;
		}
		else{
			suits(num1); //¸ð¾ç À» Ãâ·Â
			if (card[num1][num2] == 65) // A ¸¦ »Ì¾ÑÀ»¶§
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 74) // J ¸¦ »Ì¾ÑÀ»¶§
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 81) // Q ¸¦ »Ì¾ÑÀ»¶§
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 75) // K ¸¦ »Ì¾ÑÀ»¶§ 
				printf("%c", card[num1][num2]);
			if (card[num1][num2] >= 2 && card[num1][num2] <= 10) // ±×¿Ü¿¡
				printf("%d", card[num1][num2]);
			card[num1][num2] = 0; // »Ì¾Ñ´Ù°í Ç¥½Ã
			break;
		}
	}
}
void main()
{
	int num1, num2;
	int a=0;
	srand(time(NULL)); //·£´ýÇÔ¼ö¸¦ ¾²°Ù´Ù°í È£Ãâ
	while (a < 10)  //10¹ø Ãâ·Â
	{
		num1 = rand() % 4;
		num2 = rand() % 13;
		hole(num1,num2);
		printf("\n\n");
		hole1();
		a++; 
	}
	
}