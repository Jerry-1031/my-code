# include <iostream>
using namespace std;
//����n
//�����1��n�Ĺ����������ͣ�
int main()
{
    int n;
    cin >> n;
    cout << n << " ���ڹ����������ͣ�:" << endl;
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
    cout << "�� " << sum << " ��" <<endl;
    return 0;
}
