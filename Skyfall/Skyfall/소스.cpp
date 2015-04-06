#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // gotoxy�� �������� ����Լ� ȣ��
void gotoxy();
void background();
void frontground();
void suits();
void selection();
void output();
void win();
void hideoff();
int card[4][13] = { { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
					{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' } };
int dearler[5];
int user[5];
int turn = 0; //ī�� �� ���嵹�ư����� 
int concept = 0; // �¸� ����
int x = 3, y = 1,sum1 = 0, sum2 = 0; //x,y = (3,1)�� �ʱ�ȭ , ����,���� ���� 0���� �ʱ�ȭ
int getA1=0, getA2=0; //������ A�� ���� �ִ��� ,������ ������ A�� ���� �ִ���
int hidesuit,hidenum;
void gotoxy(int x, int y) //���� x,y �� Ŀ���� �����̴� �Լ� 
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void background(){
	printf("������������������������������������������������������������������������������������������������\n");
	for (int c = 0; c < 17;c++)
	printf("��                                                                                            ��\n");
	printf("������������������������������������������������������������������������������������������������\n");
}
void frontground(int x, int y)
{
	gotoxy(x, y);
	printf("��������������\n");
	for (int d = 0; d < 4; d++){
		gotoxy(x, y + d+1);
		printf("��          ��");
	}
	gotoxy(x, y + 5);
	printf("��������������\n");
	Sleep(10);
}
void suits(int *num,int info) //����� �̰ٴ�.
{
	switch (*num)
	{
	case 0: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); } else{ printf("��"); } break;
	case 1: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); }	else{ printf("��"); } break;
	case 2: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); } else{ printf("��"); } break;
	case 3: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); }	else{ printf("��"); } break;
	}
}
void selection(int *num1, int *num2, int info)
{
	if (info == 0){
		while (1){
			if (card[*num1][*num2] == 0) //�̹̻���ī�带�����ôٽ÷����Լ���������.
			{
				*num1 = rand() % 4;
				*num1 = rand() % 13;
			}
			else{
				if (card[*num1][*num2] == 65){
					dearler[turn] = 11;
					getA1 = 1;
				}
				if (card[*num1][*num2] == 74)
					dearler[turn] = 10;
				if (card[*num1][*num2] == 81)
					dearler[turn] = 10;
				if (card[*num1][*num2] == 75)
					dearler[turn] = 10;
				if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10)
					dearler[turn] = card[*num1][*num2];
				if (turn == 0){ //ù��° �϶��� ���� ����
					hidesuit = *num1; //������ ����
					hidenum = card[*num1][*num2]; //������ ����
			}
				break;
			}
		}
	}
	else if (info == 1){
		while (1){
			if (card[*num1][*num2] == 0) //�̹̻���ī�带�����ôٽ÷����Լ���������.
			{
				*num1 = rand() % 4;
				*num1 = rand() % 13;
			}
			else{
				if (card[*num1][*num2] == 65){
					user[turn] = 11;
					getA2 = 1;
				}
				if (card[*num1][*num2] == 74)
					user[turn] = 10;
				if (card[*num1][*num2] == 81)
					user[turn] = 10;
				if (card[*num1][*num2] == 75)
					user[turn] = 10;
				if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10)
					user[turn] = card[*num1][*num2];
				break;
			}
		}
	}
}
void output(int *num1, int *num2,int info)  //  ���� ����1,����2, 0= ���� ,1 =����
{
	if (info == 0){
		if (turn == 0){
			gotoxy(x + 12, y + 2);
			printf("?");
		}
		else{
			if (card[*num1][*num2] == 65){ // A ���̾�����
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 74){ // J ���̾�����
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 81){ // Q ���̾�����
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 75){ // K ���̾�����
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10){ // �׿ܿ�
				gotoxy(x + 12, y + 2);
				printf("%d", card[*num1][*num2]);
				y++;
			}
		}
	}
	else if (info == 1){
		if (card[*num1][*num2] == 65){ // A ���̾�����
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 74){ // J ���̾�����
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 81){ // Q ���̾�����
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 75){ // K ���̾�����
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10){ // �׿ܿ�
			gotoxy(x + 12, y + 2);
			printf("%d", card[*num1][*num2]);
			y++;
		}
	}
	card[*num1][*num2] = 0;
}
void win(int sum1, int sum2, char stop)  // �¸� ���� (������,������, Y or N)
{
	int a, b;  //����, ���� ���� ��
	if (sum1 == 21){
		gotoxy(30, 9);  // ����ġ�� printf ���
		printf("dearler �¸�");
		gotoxy(1, 19); // ���Ͻðڽ��ϱ� ����
		printf("                        "); //���� ����
		concept = 1; //�¸������� 1�� �ʱ�ȭ ���� �̰�ٴ°� �ǹ�
	}
	else if (sum2 == 21){
		gotoxy(30, 9);
		printf("user �¸�");
		hideoff();
		concept = 1;
		gotoxy(1, 19);
		printf("                                            ");
	}
	if (sum1 > 21){
		if (getA1 == 1)
			sum1=sum1 - 10;
		else{
			gotoxy(30, 9);
			printf("user �¸�");
			hideoff();
			gotoxy(1, 19);
			printf("                                         ");
			concept = 1;
		}
	}
	else if (sum2 > 21){
		if (getA2 == 1)
			sum2 = sum2 - 10;
		else{
			gotoxy(30, 9);
			printf("dearler �¸�");
			hideoff();
			gotoxy(1, 19);
			printf("                                                 ");
		}
		concept = 1;
	}
	
	if (!(stop - 110) || !(stop - 78)){ // N �̳� n �� ���� ���

		if (sum1 == sum2)	{
			gotoxy(30, 9);
			printf("���� ");
			hideoff();
			gotoxy(1, 19);
			printf("                                            ");
			concept = 1;
		}
		else{
			if (sum1 < 16) //������ ���� 16���� �������
			{
				int one, two;
				one = rand() % 4;
				two = rand() % 13;
				x = 43;
				y = 1;
				turn = 2;
				selection(&one, &two, 0);
				suits(&one, 0);
				output(&one, &two, 0);
				sum1 = sum1 + dearler[2];
			}
			a = 21 - sum1;
			b = 21 - sum2;
			if (a < b){
				gotoxy(30, 9);
				printf("dearler �¸�");
				hideoff();
				gotoxy(1, 19);
				printf("                                       ");
				concept = 1;
			}
			else if (b < a){
				gotoxy(30, 9);
				printf("user �¸�");
				hideoff();
				gotoxy(1, 19);
				printf("                                  ");
				concept = 1;
			}
		}
	}
}
void hideoff()
{
	switch (hidesuit)
	{
	case 0: gotoxy(12, 3); printf("��"); break;
	case 1: gotoxy(12, 3); printf("��"); break;
	case 2: gotoxy(12, 3); printf("��"); break;
	case 3: gotoxy(12, 3); printf("��"); break;
	}
	gotoxy(15, 3);
	if (hidenum >= 2 && hidenum <= 10)
		printf("%d",hidenum);
	else
		printf("%c", hidenum);
	gotoxy(11, 1); 
	printf(" %d ", sum1+dearler[2]);
}
void main()
{
	int i, j;
	int a, b;
	char sure;
	system("mode con:lines=23 cols=100"); //����â ũ�� ����
	do{
		srand(time(NULL));
		background();
		for (i = 0; i < 2; i++){ // ���� ó�� 2�� �̱�
			a = rand() % 4;
			b = rand() % 13;
			selection(&a, &b, 0);
			Sleep(10);
			suits(&a, 0);
			Sleep(10);
			output(&a, &b, 0);
			Sleep(10);
			sum1 = sum1 + dearler[i];
			x += 20;
			y = 1;
			turn++;
		}
		gotoxy(2, 1);
		printf("���� �� : ? ");
		turn = 0; //���� �з� ��ȯ�ϱ� ���� �ʱ�ȭ
		x = 3;  // ��ġ ����
		y = 9; //  ��ġ ����
		for (j = 0; j < 2; j++){ // ���� ó�� 2�� �̱�
			a = rand() % 4;
			b = rand() % 13;
			selection(&a, &b, 1);
			Sleep(10);
			suits(&a, 1);
			Sleep(10);
			output(&a, &b, 1);
			Sleep(10);
			sum2 = sum2 + user[j];
			x += 20;
			y = 9;
			turn++;
		}
		gotoxy(2, 17);
		printf("���� �� : %d\n", sum2);
		do{
			gotoxy(1, 19);
			printf("�и� �� �����ڽ��ϱ�?('Y' OR 'N')");
			scanf("%c", &sure);
			fflush(stdin);
			gotoxy(1, 19);
			printf("                                     ");
			fflush(stdin);

			if (sure == 'Y' || sure == 'y'){ // ���� ī���� �� �ޱ� 
				a = rand() % 4;
				b = rand() % 13;
				selection(&a, &b, 1);
				suits(&a, 1);
				output(&a, &b, 1);
				printf("\n");
				sum2 = sum2 + user[j];
				gotoxy(2, 17);
				printf("���� �� : %d\n", sum2);
				j++;      // �迭 ����
				turn++;  //������ �Ͽ� user�迭�� ����
				x += 20;
				y = 9;
			}
			win(sum1, sum2, sure);
			if (concept == 1){ //�¸������� ������ �汸 ���� Ż��
				concept = 0; // �¸����� �ٽ� 0���� �ʱ�ȭ �Ͽ� �ٽ� �����Ҷ� ������ ������
				break;
			}
		} while ((sure - 110) && (sure - 78));
		printf("\n");
		gotoxy(1, 19);
		printf("  �׸��Ͻðڽ��ϱ�(Y or N) : ");
		scanf("%c", &sure);
		fflush(stdin); //���� �����
		if (sure == 'N' || sure == 'n'){
			Sleep(2000);
			system("cls");
			Sleep(100);
			memset(dearler, 0, sizeof(dearler));
			memset(user, 0, sizeof(user));
			turn = 0, concept = 0;
			x = 3, y = 1, sum1 = 0, sum2 = 0;
			getA1 = 0, getA2 = 0, hidesuit = 0, hidenum = 0;
			int card[4][13] = { { 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
			{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
			{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' },
			{ 'A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K' } };
		}
	} while ((sure == 'N' || sure == 'n'));
}
