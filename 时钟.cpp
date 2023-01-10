#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int num[12][5][3]={
1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,//0
0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,//1
1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,//2
1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,//3
1,0,1,1,0,1,1,1,1,0,0,1,0,0,1,//4
1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,//5
1,1,1,1,0,0,1,1,1,1,0,1,1,1,1,//6
1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,//7
1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,//8
1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,//9
0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,//:
0,0,0,0,0,0,1,1,1,0,0,0,0,0,0};//-

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void pyear1(int n)
{
	gotoxy(0, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		cout << endl;
	}
}
void pyear2(int n)
{
	gotoxy(7, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(7, i + 1);
	}
}
void pyear3(int n)
{
	gotoxy(14, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(14, i + 1);
	}
}
void pyear4(int n)
{
	gotoxy(21, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(21, i + 1);
	}
}
void p_1()
{
	gotoxy(28, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[11][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(28, i + 1);
	}
}
void pyear(int year)
{
	int year4 = year % 10;
	year /= 10;
	int year3 = year % 10;
	year /= 10;
	int year2 = year % 10;
	year /= 10;
	int year1 = year % 10;
	year /= 10;
	pyear1(year1);
	pyear2(year2);
	pyear3(year3);
	pyear4(year4);
}

void pmonth1(int n)
{
	gotoxy(35, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(35, i + 1);
	}
}
void pmonth2(int n)
{
	gotoxy(42, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(42, i + 1);
	}
}
void p_2()
{
	gotoxy(49, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[11][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(49, i + 1);
	}
}
void pmonth(int month)
{
	if(month < 10)
	{
		pmonth1(0);
		pmonth2(month);
	}
	if(month >= 10)
	{
		pmonth1(month / 10);
		pmonth2(month % 10);
	}
}

void pday1(int n)
{
	gotoxy(56, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(56, i + 1);
	}
}
void pday2(int n)
{
	gotoxy(63, 0);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(63, i + 1);
	}
}
void pday(int day)
{
	if(day < 10)
	{
		pday1(0);
		pday2(day);
	}
	if(day >= 10)
	{
		pday1(day / 10);
		pday2(day % 10);
	}
}

void phour1(int n)
{
	gotoxy(0, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(0, i + 7);
	}
}
void phour2(int n)
{
	gotoxy(7, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(7, i + 7);
	}
}
void p_3()
{
	gotoxy(14, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[10][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(14, i + 7);
	}
}
void phour(int hour)
{
	if(hour < 10)
	{
		phour1(0);
		phour2(hour);
	}
	if(hour >= 10)
	{
		phour1(hour / 10);
		phour2(hour % 10);
	}
}

void pminute1(int n)
{
	gotoxy(21, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(21, i + 7);
	}
}
void pminute2(int n)
{
	gotoxy(28, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(28, i + 7);
	}
}
void p_4()
{
	gotoxy(35, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[10][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(35, i + 7);
	}
}
void pminute(int minute)
{
	if(minute < 10)
	{
		pminute1(0);
		pminute2(minute);
	}
	if(minute >= 10)
	{
		pminute1(minute / 10);
		pminute2(minute % 10);
	}
}

void psecond1(int n)
{
	gotoxy(42, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(42, i + 7);
	}
}
void psecond2(int n)
{
	gotoxy(49, 6);
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(num[n][i][j] == 1)
				cout << "¡ö";
			else
				cout << "  ";
		}
		gotoxy(49, i + 7);
	}
}
void psecond(int second)
{
	if(second < 10)
	{
		psecond1(0);
		psecond2(second);
	}
	if(second >= 10)
	{
		psecond1(second / 10);
		psecond2(second % 10);
	}
}

int main()
{ 
	while(true)
	{
		gotoxy(0, 0);
		time_t now = time(0);
		tm *ltm = localtime(&now);
		int year = 1900 + ltm->tm_year;
		int month = 1 + ltm->tm_mon;
		int day = ltm->tm_mday;
		int hour = ltm->tm_hour;
		int minute = ltm->tm_min;
		int second = ltm->tm_sec;
		
		pyear(year);
		p_1();
		
		pmonth(month);
		p_2();
		
		pday(day);
		
		phour(hour);
		p_3();
		
		pminute(minute);
		p_4();
		
		psecond(second);
	}
	return 0;
}

