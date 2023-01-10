#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int gcd(int a, int b)
{
	if(a == 0)
		return b;
	if(a < 0)
		return gcd(-a, b);
	while(b > 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int mod_mul(int a, int b, int mod)
{
	int res = 0;
	while(b > 0)
	{
		if(b & 1)
			(res += a) %= mod;
		(a <<= 1) %= mod;
		b >>= 1;
	}
	return res;
}
int mod_exp(int a, int b, int mod)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = mod_mul(res, a, mod);
		a = mod_mul(a, a, mod);
		b >>= 1;
	}
	return res;
}
bool MillerRabinPrimeCheck(int n)
{
	if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11)
		return true;
	if(n == 1 || n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0)
		return false;
	int k = 0, u = n - 1;
	while(!(u & 1))
	{
		k++;
		u >>= 1;
	}
	mt19937 rnd(random_device{}());
	int s = 5;
	for(int i = 1; i <= s; i++)
	{
		int x = rnd() % (n - 2) + 2;
		if(x % n == 0)
			continue;
		x = mod_exp(x, u, n);
		int pre = x;
		for(int j = 1; j <= k; j++)
		{
			x = mod_mul(x, x, n);
			if(x == 1 && pre != 1 && pre != n - 1)
				return false;
			pre = x;
		}
		if(x != 1)
			return false;
		return true;
	}
}
int Pollard_rho(int x, int c)
{
	mt19937 rnd(random_device{}());
	int i = 1, k = 2, x0 = rnd() % (x + 1), y = x0;
	while(true)
	{
		i++;
		x0 = (mod_mul(x0, x0, x) + c) % x;
		int d = gcd(y - x0, x);
		if(d != 1 && d != x)
			return d;
		if(y == x0)
			return x;
		if(i == k)
		{
			y = x0;
			k += k;
		}
	}
}
vector<int> factor(int n)
{
	vector<int> list;
	if(n <= 1)
		return list;
	if(MillerRabinPrimeCheck(n))
	{
		list.push_back(n);
		return list;
	}
	mt19937 rnd(random_device{}());
	int p = n;
	while(p >= n)
		p = Pollard_rho(p, rnd() % (n - 1) + 1);
	vector<int> l1 = factor(p);
	vector<int> l2 = factor(n / p);
	for(vector<int>::iterator it = l1.begin(); it != l1.end(); it++)
		list.push_back(*it);
	for(vector<int>::iterator it = l2.begin(); it != l2.end(); it++)
		list.push_back(*it);
	return list;
}
signed main()
{
	int n;
	cin >> n;
	vector<int> lst = factor(n);
	sort(lst.begin(), lst.end());
	for(vector<int>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << " ";
	return 0;
}
