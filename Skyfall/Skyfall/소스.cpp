#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // gotoxy를 쓰기위해 헤더함수 호출
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
int turn = 0; //카드 패 몇장돌아갔는지 
int concept = 0; // 승리 조건
int x = 3, y = 1,sum1 = 0, sum2 = 0; //x,y = (3,1)로 초기화 , 딜러,유저 합을 0으로 초기화
int getA1=0, getA2=0; //딜러가 A를 갖고 있느냐 ,유저가 딜러가 A를 갖고 있느냐
int hidesuit,hidenum;
void gotoxy(int x, int y) //지정 x,y 로 커서를 움직이는 함수 
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void background(){
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	for (int c = 0; c < 17;c++)
	printf("┃                                                                                            ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
void frontground(int x, int y)
{
	gotoxy(x, y);
	printf("┏━━━━━┓\n");
	for (int d = 0; d < 4; d++){
		gotoxy(x, y + d+1);
		printf("┃          ┃");
	}
	gotoxy(x, y + 5);
	printf("┗━━━━━┛\n");
	Sleep(10);
}
void suits(int *num,int info) //모양을 뽑겟다.
{
	switch (*num)
	{
	case 0: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); } else{ printf("♣"); } break;
	case 1: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); }	else{ printf("♥"); } break;
	case 2: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); } else{ printf("◆"); } break;
	case 3: gotoxy(x, y); frontground(x + 7, y + 1);  gotoxy(x + 9, y + 2); if (turn == 0 && info == 0){ printf("?"); }	else{ printf("♠"); } break;
	}
}
void selection(int *num1, int *num2, int info)
{
	if (info == 0){
		while (1){
			if (card[*num1][*num2] == 0) //이미뽑은카드를뽑을시다시랜덤함수를돌린다.
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
				if (turn == 0){ //첫번째 일때만 조건 형성
					hidesuit = *num1; //숨겨준 문양
					hidenum = card[*num1][*num2]; //숨겨준 숫자
			}
				break;
			}
		}
	}
	else if (info == 1){
		while (1){
			if (card[*num1][*num2] == 0) //이미뽑은카드를뽑을시다시랜덤함수를돌린다.
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
void output(int *num1, int *num2,int info)  //  각각 숫자1,숫자2, 0= 딜러 ,1 =유저
{
	if (info == 0){
		if (turn == 0){
			gotoxy(x + 12, y + 2);
			printf("?");
		}
		else{
			if (card[*num1][*num2] == 65){ // A 를뽑앗을때
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 74){ // J 를뽑앗을때
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 81){ // Q 를뽑앗을때
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] == 75){ // K 를뽑앗을때
				gotoxy(x + 12, y + 2);
				printf("%c", card[*num1][*num2]);
				y++;
			}
			if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10){ // 그외에
				gotoxy(x + 12, y + 2);
				printf("%d", card[*num1][*num2]);
				y++;
			}
		}
	}
	else if (info == 1){
		if (card[*num1][*num2] == 65){ // A 를뽑앗을때
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 74){ // J 를뽑앗을때
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 81){ // Q 를뽑앗을때
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] == 75){ // K 를뽑앗을때
			gotoxy(x + 12, y + 2);
			printf("%c", card[*num1][*num2]);
			y++;
		}
		if (card[*num1][*num2] >= 2 && card[*num1][*num2] <= 10){ // 그외에
			gotoxy(x + 12, y + 2);
			printf("%d", card[*num1][*num2]);
			y++;
		}
	}
	card[*num1][*num2] = 0;
}
void win(int sum1, int sum2, char stop)  // 승리 조건 (딜러합,유저합, Y or N)
{
	int a, b;  //딜러, 유저 각각 합
	if (sum1 == 21){
		gotoxy(30, 9);  // 이위치에 printf 출력
		printf("dearler 승리");
		gotoxy(1, 19); // 더하시겠습니까 지움
		printf("                        "); //위와 같음
		concept = 1; //승리조건을 1로 초기화 시켜 이겼다는걸 의미
	}
	else if (sum2 == 21){
		gotoxy(30, 9);
		printf("user 승리");
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
			printf("user 승리");
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
			printf("dearler 승리");
			hideoff();
			gotoxy(1, 19);
			printf("                                                 ");
		}
		concept = 1;
	}
	
	if (!(stop - 110) || !(stop - 78)){ // N 이나 n 을 쳤을 경우

		if (sum1 == sum2)	{
			gotoxy(30, 9);
			printf("비기심 ");
			hideoff();
			gotoxy(1, 19);
			printf("                                            ");
			concept = 1;
		}
		else{
			if (sum1 < 16) //딜러의 합이 16보다 작을경우
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
				printf("dearler 승리");
				hideoff();
				gotoxy(1, 19);
				printf("                                       ");
				concept = 1;
			}
			else if (b < a){
				gotoxy(30, 9);
				printf("user 승리");
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
	case 0: gotoxy(12, 3); printf("♣"); break;
	case 1: gotoxy(12, 3); printf("♥"); break;
	case 2: gotoxy(12, 3); printf("◆"); break;
	case 3: gotoxy(12, 3); printf("♠"); break;
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
	system("mode con:lines=23 cols=100"); //실행창 크기 변경
	do{
		srand(time(NULL));
		background();
		for (i = 0; i < 2; i++){ // 딜러 처음 2장 뽑기
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
		printf("딜러 합 : ? ");
		turn = 0; //유저 패로 전환하기 위해 초기화
		x = 3;  // 위치 지정
		y = 9; //  위치 지정
		for (j = 0; j < 2; j++){ // 유저 처음 2장 뽑기
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
		printf("유저 합 : %d\n", sum2);
		do{
			gotoxy(1, 19);
			printf("패를 더 받으겠습니까?('Y' OR 'N')");
			scanf("%c", &sure);
			fflush(stdin);
			gotoxy(1, 19);
			printf("                                     ");
			fflush(stdin);

			if (sure == 'Y' || sure == 'y'){ // 유저 카드패 더 받기 
				a = rand() % 4;
				b = rand() % 13;
				selection(&a, &b, 1);
				suits(&a, 1);
				output(&a, &b, 1);
				printf("\n");
				sum2 = sum2 + user[j];
				gotoxy(2, 17);
				printf("유저 합 : %d\n", sum2);
				j++;      // 배열 증가
				turn++;  //턴증가 하여 user배열에 넣음
				x += 20;
				y = 9;
			}
			win(sum1, sum2, sure);
			if (concept == 1){ //승리조건을 만족한 경구 루프 탈출
				concept = 0; // 승리조건 다시 0으로 초기화 하여 다시 게임할때 루프를 돌게함
				break;
			}
		} while ((sure - 110) && (sure - 78));
		printf("\n");
		gotoxy(1, 19);
		printf("  그만하시겠습니까(Y or N) : ");
		scanf("%c", &sure);
		fflush(stdin); //버퍼 지우기
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
