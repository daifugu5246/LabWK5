#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<conio.h>
#include <windows.h>
void draw_ship(int, int);
void erase_ship(int, int);
int main()
{
	char ch = ' ';
	int x = 38, y = 15;
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a' || ch == 'A')
			{
				if (x > 1)
					--x;
				else
					x = 1;
				draw_ship(x, y);
			}
			if (ch == 'd' || ch == 'D')
			{
				if (x < 80)
					x++;
				else
					x = 80;
				draw_ship(x, y);
			}
			if (ch == 'w' || ch == 'W')
			{
				if (y >= 2)
				{
					erase_ship(x, y);
					draw_ship(x, --y);
				}
				else if (y <= 2)
					y = 1;
			}
			if (ch == 's' || ch == 'S')
			{
				if (y <= 29) {
					erase_ship(x, y);
					draw_ship(x, ++y);
				}
				else
					y = 30;
			}
			fflush(stdin);
		}
	} while (ch != 'x');
	return 0;
}
void draw_ship(int x, int y)
{
	if (x >= 1 && x <= 80 && y >= 1 && y <= 30) {
		COORD pos1 = { x, y };
		COORD pos2 = { x, y++ };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos1);
		printf(" A ");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos2);
		printf(" <-O-> ");
		Sleep(50);
	}
}
void erase_ship(int x, int y)
{
	if (x >= 1 && x <= 80 && y >= 1 && y <= 40) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf("       ");
	}
}