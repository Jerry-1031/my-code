#include <iostream>
#include <iomanip>
using namespace std;

int map[105][105];
int main()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << "ERROR" << endl;
		return 0;
	}
	int i = 1, j = (n + 1) / 2;
	int t = n * n, d = 0;
	while(t > 0)
	{
		t /= 10;
		d++;
	}
	for(int a = 1; a <= n * n; a++)
	{
		map[i][j] = a;
		if(i == 1 && j != n)
		{
			i = n;
			j++;
			continue;
		}
		if(j == n && i != 1)
		{
			j = 1;
			i--;
			continue;
		}
		if(i == 1 && j == n)
		{
			i++;
			continue;
		}
		if(i != 1 && j != n)
		{
			if(map[i-1][j+1] == 0)
			{
				i--;
				j++;
				continue;
			}
			else
			{
				i++;
				continue;
			}
		}
	}
	for(int a = 1; a <= n; a++)
	{
		for(int b = 1; b <= n; b++)
			cout << setw(d) << map[a][b] << " ";
		cout << endl;
	}
	return 0;
}
