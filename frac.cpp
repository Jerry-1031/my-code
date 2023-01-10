#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}
struct frac
{
	public:
		long long x, y;
	private:
		void r()
		{
			if(y < 0) x = -x, y = -y;
			long long a = gcd(abs(x), y);
			x /= a, y /= a;
		}
	public:
		frac(long long x = 0, long long y = 1): x(x), y(y) {r();}
		double todb() {return double(x) / double(y);}
		frac operator =(frac b) {x = b.x, y = b.y; return *this;}
};
frac operator +(frac a, frac b) {long long d = gcd(a.y, b.y); b.y /= d, a.y /= d; return frac(a.x * b.y + a.y * b.x, d * a.y * b.y);}
frac operator -(frac a) {return frac(-a.x, a.y);}
frac operator -(frac a, frac b) {return a + (-b);}
frac operator *(frac a, frac b) {return frac(a.x * b.x, a.y * b.y);}
frac operator /(frac a, frac b) {return frac(a.x * b.y, a.y * b.x);}
frac operator +=(frac& a, frac b) {return a = a + b;}
frac operator -=(frac& a, frac b) {return a = a - b;}
frac operator *=(frac& a, frac b) {return a = a * b;}
frac operator /=(frac& a, frac b) {return a = a / b;}
bool operator >(frac a, frac b) {return a.x * b.y > b.x * a.y;}
bool operator <(frac a, frac b) {return a.x * b.y < b.x * a.y;}
bool operator >=(frac a, frac b) {return a.x * b.y >= b.x * a.y;}
bool operator <=(frac a, frac b) {return a.x * b.y <= b.x * a.y;}
bool operator ==(frac a, frac b) {return a.x * b.y == b.x * a.y;}
bool operator !=(frac a, frac b) {return a.x * b.y != b.x * a.y;}

int main()
{
	frac a = {3, 5}, b = {7, 8};
	frac c = b;
	cout << (a != c) << endl;
	return 0;
}
