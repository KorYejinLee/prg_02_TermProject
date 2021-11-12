#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define HEIGHT 10
#define WIDTH 10
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

// 게임판
void map(void) {
	int map[HEIGHT][WIDTH] = {

	{ 1,1,1,1,1,1,1,1,1,1 },

	{ 1,0,2,2,2,2,0,2,0,1 },

	{ 1,0,2,0,2,0,0,2,0,1 },

	{ 1,0,0,0,0,2,0,2,0,1 },

	{ 1,2,2,2,0,0,0,2,0,1 },

	{ 1,0,0,2,2,0,2,0,0,1 },

	{ 1,2,0,2,2,0,2,2,0,1 },

	{ 1,0,0,0,0,0,0,0,0,1 },

	{ 1,1,1,1,1,1,1,1,1,1 }

	};

	int i, j;

	for (i = 0; i < 10; i++)

	{

		for (j = 0; j < 10; j++)

		{

			if (map[i][j] == 1)

				printf("■");

			else if (map[i][j] == 0)

				printf("  ");

			else if (map[i][j] == 2)

				printf("♣");

		}

		printf("\n");

	}
}

// 방향키 조정
void gotoxy(int x, int y) {
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void keyboard(void) {
	int x = 1;
	int y = 1;
	gotoxy(x, y);
	while (1) {
		if (GetAsyncKeyState(VK_LEFT)) { //왼쪽
			x--;
		}
		if (GetAsyncKeyState(VK_RIGHT)) { //오른쪽
			x++;
		}
		if (GetAsyncKeyState(VK_UP)) { //위
			y--;
		}
		if (GetAsyncKeyState(VK_DOWN)) { //아래
			y++;
		}

		system("cls");
		map();
		gotoxy(x, y);
		printf("♥");
	}
}

int main(void) {

	map();
	keyboard();
}

