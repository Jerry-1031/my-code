#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double n;
	cin >> n;
	double s = 1;
	for(int i = 1; i <= 100; i++)
		s = (s + n / s) / 2;
	cout << s << endl;
	cout << sqrt(n) << endl;
    return 0;
}

