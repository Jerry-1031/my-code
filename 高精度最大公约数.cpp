#include<iostream>
#include<string>
using namespace std;
const int N = 10005;
struct Bign
{
	int f[N], len;
	bool zero()
	{
		return len == 1 && f[1] == 0;
	}
	bool even()
	{
		return f[1] % 2 == 0;
	}
	void read()
	{
		string s;
		cin >> s;
		len = s.length();
		for(int i = 1; i <= len; i++)
			f[i] = s[len - i] - '0';
		f[0] = len;
	}
	void print()
	{
		for(int i = len; i >= 1; i--)
			cout << f[i];
		cout << endl;
	}
};
bool operator < (Bign a, Bign b)
{
	if(a.len != b.len)
		return a.len < b.len;
	for(int i = a.len; i >= 1; i--)
		if(a.f[i] != b.f[i])
			return a.f[i] < b.f[i];
	return false;
}
Bign operator - (Bign a, Bign b)
{
	Bign c;
	int len = a.len;
	int u = 0;
	for(int i = 1; i <= len; i++)
	{
		int t = a.f[i] - u;
		if(i <= b.len)
			t -= b.f[i];
		if(t < 0)
		{
			c.f[i] = t + 10;
			u = 1;
		}
		else
		{
			c.f[i] = t;
			u = 0;
		}
	}
	while(c.f[len] == 0 && len > 1)
		len--;
	c.len = len;
	return c;
}
Bign operator * (Bign a, int b)
{
	Bign c;
	int len = a.len;
	int u = 0;
	for(int i = 1; i <= len; i++)
	{
		int t = a.f[i] * b + u;
		c.f[i] = t % 10;
		u = t / 10;
	}
	while(u > 0)
	{
		c.f[++len] = u % 10;
		u /= 10;
	}
	c.len = len;
	return c;
}
Bign operator / (Bign a, int b)
{
	Bign c;
	int len = a.len;
	int r = 0;
	for(int i = len; i >= 1; i--)
	{
		int t = r * 10 + a.f[i];
		c.f[i] = t / b;
		r = t % b;
	}
	while(c.f[len] == 0 && len > 1)
		len--;
	c.len = len;
	return c;
} 
Bign a, b, c;
Bign GCD(Bign a, Bign b)
{
	Bign c;
	int n = 0;
	while(a.even() && b.even())
	{
		n++;
		a = a / 2;
		b = b / 2;
	}
	while(!a.zero() && !b.zero())
	{
		while(a.even()) a = a / 2;
		while(b.even()) b = b / 2;
		if(a < b)
			b = b - a;
		else
			a = a - b;
	}
	if(a.zero())
		c = b;
	else
		c = a;
	for(int i = 1; i <= n; i++)
		c = c * 2;
	return c;
}

int main()
{
	a.read();
	b.read();
	cout << "a = ";
	a.print();
	cout << "b = ";
	b.print();
	c = GCD(a, b);
	cout << "[a, b] = ";
	c.print();
	return 0;
}
