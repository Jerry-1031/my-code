#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110], b[110][110], m, n, k;
void A()
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			b[j][m+1-i] = a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = b[i][j];
	swap(m, n);
}
void B()
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			b[n+1-j][i] = a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = b[i][j];
	swap(m, n);
}
void C()
{
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n / 2; j++)
			swap(a[i][j], a[i][n+1-j]);
}
void D()
{
	for(int i = 1; i <= m / 2; i++)
		for(int j = 1; j <= n; j++)
			swap(a[i][j], a[m+1-i][j]);
}
void ctl(char x)
{
    if(x == 'A') A();
    if(x == 'B') B();
    if(x == 'C') C();
    if(x == 'D') D();
    /*A:顺时针旋转90° 
    B:逆时针旋转90° 
    C:左右翻转 
    D:上下翻转*/
}
int main()
{
	cin >> m >> n >> k;//行，列，操作序列个数 
	for(int i = 1; i <= m; i++)
	    for(int j = 1;  j <= n; j++)
	        cin >> a[i][j];
    string c;
    cin >> c;
    for(int i = 0; i < k; i++)
        ctl(c[i]);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

