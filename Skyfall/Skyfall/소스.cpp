#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char card[4][13] = { { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }, { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }, { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }, { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' } };
void suits(int i) // ī�� ��� �Լ�
{
	switch (i)
	{
	case 0:  printf("��,"); break;
	case 1:  printf("��,"); break;
	case 2:  printf("��,"); break;
	case 3:  printf("��,"); break;
	}

}
void main()
{
	int i, j;
	int num1, num2; // num1 =��� , num2 = ���� 
	srand(time(NULL)); // �ð����� �����Լ��� ����
	for (i = 0; i < 4; i++){
		suits(i);
		for (j = 0; j < 13; j++)
			printf("%c ", card[i][j]);
		printf("\n");
	}
	num1 = rand() % 4; // 0~ 3���� ���ڸ� ����
	num2 = rand() % 13; // 0 ~  13 ���� ���ڸ� ����
	printf("\n\n");
	suits(num1);
	printf("%c", card[num1][num2]);
}