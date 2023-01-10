#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[20];
bool flag[20];
int n;

bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

void dfs(int step)
{
	if (step > n)
	{
		if (isPrime(a[n] + a[1]))
		{
			for (int i = 1; i <= n; i++)
				cout << a[i] << " ";
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (flag[i]) continue;
		if(!isPrime(a[step - 1] + i))
			continue;
		a[step] = i;
		flag[i] = true;
		dfs(step + 1);
		flag[i] = false;
	}
}

int main()
{
	int t = 1;
	while(scanf("%d",&n) != EOF)
	{
		a[1] = 1;
		flag[1] = true;
		cout << "Case " << t << ":" << endl;
		t++;
		dfs(2);
	}
	return 0;
}
