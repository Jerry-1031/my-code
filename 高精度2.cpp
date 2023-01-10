#include<iostream>
#include<string>
using namespace std;

const int N = 65536;
struct Bign
{
	int f[N], len;
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
	}
	void set(int x)
	{
		if(x == 0)
			len = 1;
		else
			len = 0;
		while(x)
		{
			f[++len] = x % 10;
			x /= 10;
		}
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

bool operator > (Bign a, Bign b)
{
	if(a.len != b.len)
		return a.len > b.len;
	for(int i = a.len; i >= 1; i--)
		if(a.f[i] != b.f[i])
			return a.f[i] > b.f[i];
	return false;
}

bool operator == (Bign a, Bign b)
{
	if(a.len != b.len)
		return false;
	for(int i = a.len; i >= 1; i--)
		if(a.f[i] != b.f[i])
			return false;
	return true;
}

bool operator != (Bign a, Bign b)
{
	if(a.len != b.len)
		return true;
	for(int i = a.len; i >= 1; i--)
		if(a.f[i] != b.f[i])
			return true;
	return false;
}

bool operator <= (Bign a, Bign b)
{
	if((a < b) || (a == b))
		return true;
	else
		return false;
}

bool operator >= (Bign a, Bign b)
{
	if((a > b) || (a == b))
		return true;
	else
		return false;
}

Bign operator + (Bign a, Bign b)
{
	Bign c;
	int len = max(a.len, b.len);
	int u = 0;
	for(int i = 1; i <= len; i++)
	{
		int t = u;
		if(i <= a.len)
			t += a.f[i];
		if(i <= b.len)
			t += b.f[i];
		c.f[i] = t % 10;
		u = t / 10;
	}
	if(u > 0)
		c.f[++len] = u;
	c.len = len;
	return c;
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
int main()
{
	char ch;
	int d;
	a.read();
	cin >> ch;
	if(ch == '+')
	{
		b.read();
		c = a + b;
	}
	if(ch == '-')
	{
		b.read();
		if(a < b)
			c = b - a;
		else
			c = a - b;
	}
	if(ch == '*')
	{
		cin >> d;
		c = a * d;
	}
	if(ch == '/')
	{
		cin >> d;
		c = a / d;
	}
	c.print();
	return 0;
}
