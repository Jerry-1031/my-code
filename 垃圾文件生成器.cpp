#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

char RandChar()
{
	char c;
	if(rand() % 2 == 0)
		c = char(rand() % 9 + 48);
	else
		c = char(rand() % 25 + 97);
	return c;
}

int main()
{
	srand(time(0));
	long long n, num;
	cout << "�������ַ�����1024�ֽ�=1KB��1MB=1000KB" << endl;
	cin >> n;
	cout << "�������ļ�����" << endl;
	cin >> num;
	for(long long a = 1; a <= num; a++)
	{
		string FileName = "trash_00000000";
		for(int i = 6; i <= 13; i++)
			FileName[i] = RandChar();
		cout << "��" << a << "���ļ�����" << FileName << endl;;
		const char* cFileName = FileName.data();
    	ofstream out(cFileName);
    	for(long long i = 1; i <= n; i++)
			out << char(rand() % 255);
	}
    cout << "�����ɣ�" << endl;
    cin >> n;
	return 0;
}

