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
	printf("������ ���� �մϴ�.\n");
	while (1) {
		system("cls");
		show_background();
		gotoxy(5, 4);
		printf("���ڸ� �������ּ��� ���ڴ� �ִ� 6���� �����մϴ�.(�����Ϸ��� -1�� �Է��ϼ���) : ");
		scanf_s("%d", &n);
		if (n == -1) {
			system("cls");
			show_background();
			gotoxy(5, 4);
			printf("������ ���� �մϴ�. ���� �ݾ� : %d\n", money);
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
		printf("���� ��� : %d, ���ü��� : %d, ����ݾ� : %d\n", betting, n, money);
		gotoxy(5, 6);
		system("pause");
		if (money == 0) {
			system("cls");
			show_background();
			gotoxy(5, 4);
			printf("���ñݾ��� ��� ������ ������ ���� �˴ϴ�.\n");
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
	system("title ����������Ʈ");
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

		printf("��");

	}
	for (j = 0; j < 20; j++) {
		printf("��");
		for (i = 0; i < 96; i++) {
			printf(" ");
		}
		printf("��");
	}
	gotoxy(43, 5);
	yellow();
	printf("  ��������");
	gotoxy(posX, posY);
	white();
	printf("���� ����");
	gotoxy(posX, posY + 4);
	printf("���� ����");
	gotoxy(57, 10);
	printf(":arrow_backward:");
	gotoxy(3, 20);
	printf("\n");
	for (i = 0; i < 50; i++) {
		printf("��");
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
			printf("��");
	}
	for (j = 0; j < 20; j++) {
		if (arr[j] == 1)
			printf("��");
		for (i = 0; i < 96; i++) {
			printf(" ");
		}
		if (arr[j] == 1)
			printf("��");
	}
	for (i = 0; i < 50; i++) {
		if (arr[i] == 1)
			printf("��");
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