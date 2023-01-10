#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define SNAKESIZE 100
#define MAPWIDTH 78
#define MAPHEIGHT 24

struct Food
{
	int x;
	int y;
} food;

struct Snake
{
	int speed;
	int len;
	int x[SNAKESIZE];
	int y[SNAKESIZE];

} snake;

int key = 72;
int changeFlag = 0;
int score = 0;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int i;

void drawMap()
{
	for(i = 0; i <= MAPWIDTH; i += 2)
	{
		gotoxy(i, 0);
		printf("■");
		gotoxy(i, MAPHEIGHT);
		printf("■");
	}
	for(i = 1; i < MAPHEIGHT; i++)
	{
		gotoxy(0, i);
		printf("■");
		gotoxy(MAPWIDTH, i);
		printf("■");
	}
	while(1)
	{
		srand((unsigned int)time(0));
		food.x = rand() % (MAPWIDTH - 4) + 2;
		food.y = rand() % (MAPHEIGHT - 2) + 1;
		if(food.x % 2 == 0)
			break;
	}
	gotoxy(food.x, food.y);
	printf("*");
	snake.len = 3;
	snake.speed = 200;
	snake.x[0] = MAPWIDTH / 2 + 1;
	snake.y[0] = MAPHEIGHT / 2;
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
	for(i = 1; i < snake.len; i++)
	{
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("■");
	}
	gotoxy(MAPWIDTH - 2, 0);
	return;
}

void keyDown()
{
	int pre_key = key;
	if(_kbhit())
	{
		fflush(stdin);
		key = _getch();
		if(key == 0 || key == 224)
			key = _getch();
		if(key == 'w' || key == 'W')
			key = 72;
		if(key == 's' || key == 'S')
			key = 80;
		if(key == 'a' || key == 'A')
			key = 75;
		if(key == 'd' || key == 'D')
			key = 77;
	}
	if(changeFlag == 0)
	{
		gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		printf("  ");
	}
	for(i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}
	if(pre_key == 72 && key == 80)
		key = 72;
	if(pre_key == 80 && key == 72)
		key = 80;
	if(pre_key == 75 && key == 77)
		key = 75;
	if(pre_key == 77 && key == 75)
		key = 77;
	switch(key)
	{
		case 75:
			snake.x[0] -= 2;
			break;
		case 77:
			snake.x[0] += 2;
			break;
		case 72:
			snake.y[0]--;
			break;
		case 80:
			snake.y[0]++;
			break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("■");
	gotoxy(MAPWIDTH - 2, 0);
	changeFlag = 0;
	return;
}

void createFood()
{
	if(snake.x[0] == food.x && snake.y[0] == food.y)
	{
		while(true)
		{
			int flag = 1;
			srand((unsigned int)time(NULL));
			food.x = rand() % (MAPWIDTH - 4) + 2;
			food.y = rand() % (MAPHEIGHT - 2) + 1;
			for(i = 0; i < snake.len; i++)
				if(snake.x[i] == food.x && snake.y[i] == food.y)
				{
					flag = 0;
					break;
				}
			if(flag && food.x % 2 == 0)
				break;
		}
		gotoxy(food.x, food.y);
		printf("*");
		snake.len++;
		score += 10;
		snake.speed -= 5;
		changeFlag = 1;
	}
	return;
}

bool snakeStatus()
{
	if(snake.y[0] == 0 || snake.y[0] == MAPHEIGHT)
		return false;
	if(snake.x[0] == 0 || snake.x[0] == MAPWIDTH)
		return false;
	for(i = 1; i < snake.len; i++)
		if(snake.x[i] == snake.x[0] && snake.y[i] == snake.y[0])
			return false;
	return true;
}

int main()
{
	drawMap();
	while(true)
	{
		keyDown();
		if(!snakeStatus())
			break;
		createFood();
		Sleep(snake.speed);
	}
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2);
	printf("Game Over!\n");
	gotoxy(MAPWIDTH / 2, MAPHEIGHT / 2 + 1);
	printf("本次游戏得分为：%d\n", score);
	Sleep(3000);
	return 0;
}

