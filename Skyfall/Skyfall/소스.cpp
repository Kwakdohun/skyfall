#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int card[4][13] = { { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' } };

void suits(int num) //����� �̰ٴ�.
{
	switch (num)
	{
	case 0: printf("��"); break;
	case 1: printf("��"); break;
	case 2: printf("��"); break;
	case 3: printf("��"); break;
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
		if (card[num1][num2] == 0) //�̹� ���� ī�带 ������ �ٽ� �����Լ��� ������.
		{
			num1 = rand() % 4;
			num2 = rand() % 13;
		}
		else{
			suits(num1); //��� �� ���
			if (card[num1][num2] == 65) // A �� �̾�����
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 74) // J �� �̾�����
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 81) // Q �� �̾�����
				printf("%c", card[num1][num2]);
			if (card[num1][num2] == 75) // K �� �̾����� 
				printf("%c", card[num1][num2]);
			if (card[num1][num2] >= 2 && card[num1][num2] <= 10) // �׿ܿ�
				printf("%d", card[num1][num2]);
			card[num1][num2] = 0; // �̾Ѵٰ� ǥ��
			break;
		}
	}
}
void main()
{
	int num1, num2;
	int a=0;
	srand(time(NULL)); //�����Լ��� ���ٴٰ� ȣ��
	while (a < 10)  //10�� ���
	{
		num1 = rand() % 4;
		num2 = rand() % 13;
		hole(num1,num2);
		printf("\n\n");
		hole1();
		a++; 
	}
	
}