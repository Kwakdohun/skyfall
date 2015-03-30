#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	char player[50];
	char *pmark[5];//게임중 나타나는 
	int dealer;
	char Sdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K' }; //일단 A는 1이라고만 생각함
	char Cdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
	char Ddeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };
	char Hdeck[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' };

	char mark[4][4] = { "♤", "♧", "◇", "♡" };

	int i, j;//카드를 선택하기위한 변수
	int k, l;
	int sum = 0;
	char cho;

	srand(time(NULL));


	for (k = 0; k < 2; k++)
	{
		i = rand() % 4;  //여기서 앞의 문양이 결정
		j = rand() % 13;

		if (i == 0) //문양에 따라서 숫자값을 가져감
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

	while (1) //플레이어의 패
	{


		if (sum < 15)
		{
			i = rand() % 4;  //여기서 앞의 문양이 결정
			j = rand() % 13;

			if (i == 0) //문양에 따라서 숫자값을 가져감
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
			printf("카드를 더 받을지 선택하시오(Y/N) :  ");
			fflush(stdin);
			scanf("%c", &cho);
			if (cho == 'y' || cho=='Y') //한번더 받고싶으면 더받음
			{

				i = rand() % 4;  //여기서 앞의 문양이 결정
				j = rand() % 13;

				if (i == 0) //문양에 따라서 숫자값을 가져감
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
				break; // 받기 싫으면 와일문에서 빠져나감
		}


	}
}