#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	char player[50];
	char *pmark[5];//������ ��Ÿ���� 
	int dealer;
	char Sdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }; //�ϴ� A�� 1�̶�� ������
	char Cdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
	char Ddeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
	char Hdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };

	char mark[4][4] = { "��", "��", "��", "��" };

	int i, j;//ī�带 �����ϱ����� ����
	int k, l;
	int sum = 0;
	char cho;

	srand(time(NULL));


	for (k = 0; k < 2; k++)
	{
		i = rand() % 4;  //���⼭ ���� ������ ����
		j = rand() % 13;

		if (i == 0) //���翡 ���� ���ڰ��� ������
			player[k] = Sdeck[j];
		else if (i == 1)
			player[k] = Cdeck[j];
		else if (i == 2)
			player[k] = Ddeck[j];
		else
			player[k] = Hdeck[j];
		sum = sum + (j + 1);

		printf("%s%c ", &mark[i], player[k]);
	}

	while (1) //�÷��̾��� ��
	{


		if (sum < 15)
		{
			i = rand() % 4;  //���⼭ ���� ������ ����
			j = rand() % 13;

			if (i == 0) //���翡 ���� ���ڰ��� ������
				player[k] = Sdeck[j];
			else if (i == 1)
				player[k] = Cdeck[j];
			else if (i == 2)
				player[k] = Ddeck[j];
			else
				player[k] = Hdeck[j];

			sum = sum + (j + 1);
			printf("%s%c ", &mark[i], player[k]);

		}
		else
		{
			printf("ī�带 �� ������ �����Ͻÿ�(Y/N) :  ");
			fflush(stdin);
			scanf("%c", &cho);
			if (cho == 'y' || cho=='Y') //�ѹ��� �ް������ ������
			{

				i = rand() % 4;  //���⼭ ���� ������ ����
				j = rand() % 13;

				if (i == 0) //���翡 ���� ���ڰ��� ������
					player[k] = Sdeck[j];
				else if (i == 1)
					player[k] = Cdeck[j];
				else if (i == 2)
					player[k] = Ddeck[j];
				else
					player[k] = Hdeck[j];

				sum = sum + (j + 1);
				printf("%s%c ", &mark[i], player[k]);

			}
			else if (cho == 'N' || cho == 'n')
				break; // �ޱ� ������ ���Ϲ����� ��������
		}


	}
}