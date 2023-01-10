# include <iostream>
using namespace std;
//输入n
//输出从1到n的勾股数表（按和）
int main()
{
    int n;
    cin >> n;
    cout << n << " 以内勾股数表（按和）:" << endl;
	int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = a; b <= n; b++)
            {
                int c = i - a - b;
                if (c < b) break;
                if (a * a + b * b == c * c)
                {
                    cout << i << ": ";
                    cout << a << " ";
                    cout << b << " ";
                    cout << c << endl;
                    sum++;
                }
            }
        }
    }
    cout << "共 " << sum << " 组" <<endl;
    return 0;
}
