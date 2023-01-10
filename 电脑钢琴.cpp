#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define qdo 262
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494
#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988
#define do1 1046
#define re1 1175
#define mi1 1318
#define fa1 1480
#define so1 1568
#define la1 1760
#define si1 1976

int main()
{
	char ch;
	int a = 150;
	cout<<"欢迎使用电脑钢琴!\n";
	system("pause");
	system("cls");
	cout<<"电脑钢琴正在运行......";
	while(true)
	{
		ch = getch();
		switch(ch)
		{
			case'Q':case'q':Beep(qdo,a);break;
			case'W':case'w':Beep(qre,a);break;
			case'E':case'e':Beep(qmi,a);break;
			case'R':case'r':Beep(qfa,a);break;
			case'T':case't':Beep(qso,a);break;
			case'Y':case'y':Beep(qla,a);break;
			case'U':case'u':Beep(qsi,a);break;
			case'I':case'i':Beep(do,a);break;
			case'O':case'o':Beep(re,a);break;
			case'P':case'p':Beep(mi,a);break;
			
			case'A':case'a':Beep(do,a);break;
			case'S':case's':Beep(re,a);break;
			case'D':case'd':Beep(mi,a);break;
			case'F':case'f':Beep(fa,a);break;
			case'G':case'g':Beep(so,a);break;
			case'H':case'h':Beep(la,a);break;
			case'J':case'j':Beep(si,a);break;
			case'K':case'k':Beep(do1,a);break;
			case'L':case'l':Beep(re1,a);break;
			
			case'Z':case'z':Beep(do1,a);break;
			case'X':case'x':Beep(re1,a);break;
			case'C':case'c':Beep(mi1,a);break;
			case'V':case'v':Beep(fa1,a);break;
			case'B':case'b':Beep(so1,a);break;
			case'N':case'n':Beep(la1,a);break;
			case'M':case'm':Beep(si1,a);break;
			
			case'`':Beep(qsi,a);break;
			case'1':Beep(do,a);break;
			case'2':Beep(re,a);break;
			case'3':Beep(mi,a);break;
			case'4':Beep(fa,a);break;
			case'5':Beep(so,a);break;
			case'6':Beep(la,a);break;
			case'7':Beep(si,a);break;
			case'8':Beep(do1,a);break;
			case'9':Beep(re1,a);break;
			case'0':Beep(mi1,a);break;
			case'-':case'_':Beep(fa1,a);break;
			case'=':case'+':Beep(so1,a);break;
			
			case'\\':case'|':
			{
				system("cls");
				cout<<"谢谢使用!\n";
				return 0;
			}
		}
	}
	return 0;
}
