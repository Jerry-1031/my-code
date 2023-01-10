#include <iostream>
using namespace std;
int main()
{
	cout << "char size:" << sizeof(char) << endl;
	cout << "short size:" << sizeof(short) << endl;
	cout << "short int size:" << sizeof(short int) << endl;
	cout << "int size:" << sizeof(int) << endl;
	cout << "long int size:" << sizeof(long int) << endl;
	cout << "long size:" << sizeof(long) << endl;
	cout << "float size:" << sizeof(float) << endl;
	cout << "long long size:" << sizeof(long long) << endl;
	cout << "double size:" << sizeof(double) << endl;
	cout << "long double size:" << sizeof(long double) << endl;
	cout << "__int8 size:" << sizeof(__int8) << endl;
	cout << "__int16 size:" << sizeof(__int16) << endl;
	cout << "__int32 size:" << sizeof(__int32) << endl;
	cout << "__int64 size:" << sizeof(__int64) << endl;
	cout << "__int128 size:" << sizeof(__int128) << endl;
    return 0;
}

