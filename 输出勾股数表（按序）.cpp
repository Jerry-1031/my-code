#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	int n, a = 3, b = 4, c = 5;
	cin >> n;
	cout << a << " " << b << " " << c << endl;
	for(int i = 5; i <= n; i++)
	{
		if(i % 2)
		{
			//i是奇数
			a = i;
			b = (i * i - 1) / 2;
			c = (i * i + 1) / 2;
			cout << a << " " << b << " " << c << endl;
		}
		else
		{
			//i是偶数
			a = i;
			b = i * i / 4 - 1;
			c = i * i / 4 + 1;
			cout << a << " " << b << " " << c << endl;
		}
	}
	return 0;
}

