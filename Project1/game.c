#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int Game(void);
void show_background(void);
void gotoxy(int x, int y);

int Game() {

	int n = 0;
	int money = 1000;
	int betting = 0;
	printf("게임을 시작 합니다.\n");
	while (1) {
		system("cls");
		show_background();
		gotoxy(5, 4);
		printf("숫자를 배팅해주세요 숫자는 최대 6까지 가능합니다.(종료하려면 -1을 입력하세요) : ");
		scanf_s("%d", &n);
		if (n == -1) {
			system("cls");
			show_background();
			gotoxy(5, 4);
			printf("게임을 종료 합니다. 최종 금액 : %d\n", money);
			gotoxy(5, 5);
			system("pause");
			break;
		}
		srand(time(NULL));
		betting = rand() % 6 + 1;
		if (betting == n)
			money += 500;
		else
			money -= 100;
		gotoxy(5, 5);
		printf("배팅 결과 : %d, 배팅숫자 : %d, 현재금액 : %d\n", betting, n, money);
		gotoxy(5, 6);
		system("pause");
		if (money == 0) {
			system("cls");
			show_background();
			gotoxy(5, 4);
			printf("배팅금액이 모두 소진되 게임이 종료 됩니다.\n");
			gotoxy(5, 5);
			system("pause");
			break;

		}

	}
	return 0;
}

int KeyCTR()
{
	char Input = _getch();

	if (Input == 72) {
		return 0;
	}
	else if (Input == 80)
	{

		return 1;
	}
	else if (Input == 13)
	{

		return 2;
	}
}
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void yellow()
{
	textcolor(0x000E);
}

void black()
{
	textcolor(0x00F0);
}

void white()
{
	textcolor(0x000F);
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}



void console()
{
	system("title 선린프로젝트");
	system("color FF");
	system("mode con:cols=100 lines=30");
}


int start()
{
	int posY = 10;
	int posX = 45;
	int i, j;
	console();
	for (i = 0; i < 50; i++) {

		printf("■");

	}
	for (j = 0; j < 20; j++) {
		printf("■");
		for (i = 0; i < 96; i++) {
			printf(" ");
		}
		printf("■");
	}
	gotoxy(43, 5);
	yellow();
	printf("  선린코인");
	gotoxy(posX, posY);
	white();
	printf("게임 시작");
	gotoxy(posX, posY + 4);
	printf("게임 종료");
	gotoxy(57, 10);
	printf(":arrow_backward:");
	gotoxy(3, 20);
	printf("\n");
	for (i = 0; i < 50; i++) {
		printf("■");
	}
	gotoxy(posX - 1, posY);
	while (1) {

		int start = KeyCTR();
		switch (start)
		{
		case 1: if (posY == 10)
		{
			gotoxy(posX - 2, posY);
			printf(" ");
			gotoxy(posX - 2, posY += 4);
			printf(">");
		}
				break;
		case 0: if (posY == 14)
		{
			gotoxy(posX - 2, posY);
			printf(" ");
			gotoxy(posX - 2, posY -= 4);
			printf(">");

		}
				break;
		case 2: {

			if (posY == 10) {
				return 0;
			}
			if (posY == 14) {
				return 1;
			}

		}

		default:
			break;
		}

	}
}
void show_background(void)
{
	int arr[50] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int i, j;
	for (i = 0; i < 50; i++) {
		if (arr[i] == 1)
			printf("■");
	}
	for (j = 0; j < 20; j++) {
		if (arr[j] == 1)
			printf("■");
		for (i = 0; i < 96; i++) {
			printf(" ");
		}
		if (arr[j] == 1)
			printf("■");
	}
	for (i = 0; i < 50; i++) {
		if (arr[i] == 1)
			printf("■");
	}
}
int main()
{


	while (1) {
		int ReturnNumber = start();
		if (ReturnNumber == 0) {
			system("cls");
			Game();
		}
		if (ReturnNumber == 1) {
			exit(1);
		}

	}
	return 0;
	system("pause");
}