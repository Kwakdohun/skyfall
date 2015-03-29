#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char card[4][13] = { { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '@', 'J', 'Q', 'K' }, 
					 { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '@', 'J', 'Q', 'K' }, 
					 { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '@', 'J', 'Q', 'K' }, 
					 { 'A', '2', '3', '4', '5', '6', '7', '8', '9', '@', 'J', 'Q', 'K' } }; //카드 설정
void suits(int i) // 카드 모양 함수
{
	switch (i)
	{
	case 0:  printf("♠,"); break;
	case 1:  printf("♥,"); break;
	case 2:  printf("◆,"); break;
	case 3:  printf("♣,"); break;
	}

}
void cards() //카드 패
{
	int i, j;
	for (i = 0; i < 4; i++){
		suits(i);
		for (j = 0; j < 13; j++)
			printf("%c ", card[i][j]);
		printf("\n");
	}
}
void main()
{
	int i, j;
	int num1, num2; // num1 =모양 , num2 = 숫자 
	srand(time(NULL)); // 시간마다 랜덤함수를 뽑음
	for (int z = 0; z < 3; z++)
	{
		num1 = rand() % 4; // 0~ 3까지 숫자를 뽑음
		num2 = rand() % 13; // 0 ~  13 까지 숫자를 뽑음
		printf("\n\n");
		suits(num1); // 카드모양 뽑기 
		printf("%c\n", card[num1][num2]); // 카드숫자 뽑기
		card[num1][num2] = 0; // 이미 뽑았으니 없애기
		cards();
	}
}