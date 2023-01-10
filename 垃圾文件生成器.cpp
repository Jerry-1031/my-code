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
	cout << "请输入字符数，1024字节=1KB，1MB=1000KB" << endl;
	cin >> n;
	cout << "请输入文件个数" << endl;
	cin >> num;
	for(long long a = 1; a <= num; a++)
	{
		string FileName = "trash_00000000";
		for(int i = 6; i <= 13; i++)
			FileName[i] = RandChar();
		cout << "第" << a << "个文件名：" << FileName << endl;;
		const char* cFileName = FileName.data();
    	ofstream out(cFileName);
    	for(long long i = 1; i <= n; i++)
			out << char(rand() % 255);
	}
    cout << "输出完成！" << endl;
    cin >> n;
	return 0;
}

