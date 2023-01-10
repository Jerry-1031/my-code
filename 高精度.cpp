#include <iostream>
#include <string>
using namespace std;
void s2BIG(string s, int a[])
{
	int la = s.length();
	for(int i = 1; i <= la; i++)
		a[i] = s[la - i] - '0';
	a[0] = la;
}
void i2BIG(int n, int a[])
{
	int la = 0;
	while(n > 0)
	{
		la++;
		a[la] = n % 10;
		n /= 10;
	}
	if(la == 0)
		la++;
	a[0] = la;
}
void printBIG(int a[])
{
	int la = a[0];
	for(int i = la; i >= 1; i--)
		cout << a[i];
	cout << endl;
}
void clearBIG(int a[])
{
	int la = a[0];
	for(int i = 1; i <= la; i++)
		a[i] = 0;
	a[0] = 1;
}
bool cmpBIG(int a[], int b[])
{
	int la = a[0], lb = b[0];
	if(la != lb)
		return la < lb;
	for(int i = la; i >= 1; i--)
		if (a[i] != b[i])
			return a[i] < b[i];
	return false;
}
bool equBIG(int a[], int b[])
{
	int la = a[0], lb = b[0];
	if(la != lb)
		return false;
	for(int i = la; i >= 1; i--)
		if (a[i] != b[i])
			return false;
	return true;
}
void addBIG(int a[], int b[], int c[])
{
	int lc = max(a[0], b[0]), u = 0;
	for(int i = 1; i <= lc; i++)
	{
		int t = a[i] + b[i] + u;
		c[i] = t % 10;
		u = t / 10;
	}
	if(u > 0)
		c[++lc] = u;
	c[0] = lc;
}
void subBIG(int a[], int b[], int c[])
{
	if(cmpBIG(a, b))
		swap(a, b);
	int lb = b[0], lc = a[0];
	int u = 0;
	for(int i = 1; i <= lc; i++)
	{
		int t = a[i] - u;
		if(i <= lb)
			t -= b[i];
		if(t < 0)
		{
			c[i] = t + 10;
			u = 1;
		}
		else
		{
			c[i] = t;
			u = 0;
		}
	}
	while(c[lc] == 0 && lc > 1)
		lc--;
	c[0] = lc;
}
void mulBIG(int a[], int b, int c[])
{
	int lc = a[0], u = 0;
	for(int i = 1; i <= lc; i++)
	{
		int t = a[i] * b + u;
		c[i] = t % 10;
		u = t / 10;
	}
	while(u > 0)
	{
		c[++lc] = u % 10;
		u /= 10;
	}
	c[0] = lc;
}
void divBIG(int a[], int b, int c[])
{
	int lc = a[0], r = 0;
	for(int i = lc; i >= 1; i--)
	{
		int t = r * 10 + a[i];
		c[i] = t / b;
		r = t % b;
	}
	while(c[lc] == 0 && lc > 1)
		lc--;
	c[0] = lc;
}
int a[1005], b[1005], c[1005];
string sa, sb;
int main()
{
	cin >> sa >> sb;
	s2BIG(sa, a);
	s2BIG(sb, b);
	cout << "a = ";
	printBIG(a);
	cout << "b = ";
	printBIG(b);
	if(cmpBIG(a, b))
		cout << "a < b" << endl;
	else
		if(equBIG(a, b))
			cout << "a = b" << endl;
		else
			cout << "a > b" << endl;
	s2BIG(sa, a);
	s2BIG(sb, b);
	addBIG(a, b, c);
	cout << "a + b = ";
	printBIG(c);
	s2BIG(sa, a);
	s2BIG(sb, b);
	clearBIG(c);
	subBIG(a, b, c);
	cout << "a - b = ";
	if(cmpBIG(a, b))
		cout << "-";
	printBIG(c);
	s2BIG(sa, a);
	s2BIG(sb, b);
	clearBIG(c);
	return 0;
}

