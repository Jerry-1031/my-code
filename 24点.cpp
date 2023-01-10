#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int mark_int[4] = {1, 2, 3, 4};
string mark_char = "+-*/";
bool flag = false;
int n = 24;
double cal(double a, int m, double b)
{
    switch(m)
    {
        case 1:
            return a + b;
        case 2:   
            return a - b;
        case 3:   
            return a * b;
        case 4:   
            return a / b;
    }
}
bool cal1(double a, double b, double c, double d, int m1, int m2, int m3)
{
    double r = cal(cal(cal(a, m1, b), m2, c), m3, d);
    if(abs(r - n) <= 0.00001)
    {
        cout << "(((" << a << mark_char[m1 - 1] << b << ")" << mark_char[m2 - 1] << c << ")" << mark_char[m3 - 1] << d << ")" << endl;
        return true;
    }
    else return false;
}
bool cal2(double a, double b, double c, double d, int m1, int m2, int m3)
{
    double r = cal(cal(a, m2, cal(b, m1, c)), m3, d);
    if(abs(r - n) <= 0.00001)
    {
        cout << "((" << a << mark_char[m2 - 1] << "(" << b << mark_char[m1 - 1] << c << "))" << mark_char[m3 - 1] << d << ")" << endl;
        return true;
    }
    else return false;
}
bool cal3(double a, double b, double c, double d, int m1, int m2, int m3)
{
    double r = cal(a, m3, cal(cal(b, m1, c), m2, d));
    if(abs(r - n) <= 0.00001)
    {
        cout << "(" << a << mark_char[m3 - 1] << "((" << b << mark_char[m1 - 1] << c << ")" << mark_char[m2 - 1] << d << "))" << endl;
        return true;
    }
    else return false;
}
bool cal4(double a, double b, double c, double d, int m1, int m2, int m3)
{
    double r = cal(a, m3, cal(b, m2, cal(c, m1, d)));
    if(abs(r - n) <= 0.00001)
    {
        cout << "(" << a << mark_char[m3 - 1] << "(" << b << mark_char[m2 - 1] << "(" << c << mark_char[m1 - 1] << d << ")))" << endl;
        return true;
    }
    else return false;
}
bool cal5(double a, double b, double c, double d, int m1, int m2, int m3)
{
    double r = cal(cal(a, m1, b), m2, cal(c, m3, d));
    if(abs(r - n) <= 0.00001)
    {
        cout << "((" << a << mark_char[m1 - 1] << b << ")" << mark_char[m2 - 1] << "(" << c << mark_char[m3 - 1] << d << "))" << endl;
        return true;
    }
    else return false;
}
bool all_cal(int a, int b, int c, int d)
{
    bool flag1 = false;
    for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
            for(int k = 1; k <= 4; k++)
                if(cal1(a, b, c, d, i, j, k) || cal2(a, b, c, d, i, j, k) || cal3(a, b, c, d, i, j, k) || cal4(a, b, c, d, i, j, k) || cal5(a, b, c, d, i, j, k))
                    flag1 = true;
    return flag1;
}
void judge(int a, int b, int c, int d)
{
    int all[24][4] =
    {
        {a,b,c,d}, {a,b,d,c}, {a,c,b,d}, {a,c,d,b}, {a,d,b,c}, {a,d,c,b},
        {b,a,c,d}, {b,a,d,c}, {b,c,a,d}, {b,c,d,a}, {b,d,a,c}, {b,d,c,a},
        {c,a,b,d}, {c,a,d,b}, {c,b,a,d}, {c,b,d,a}, {c,d,a,b}, {c,d,b,a},
        {d,a,b,c}, {d,a,c,b}, {d,b,a,c}, {d,b,c,a}, {d,c,a,b}, {d,c,b,a}
    };
    for(int i = 0; i < 24; i++)
        if(all_cal(all[i][0], all[i][1], all[i][2], all[i][3]))
            flag = true;
}
int main()
{
    int a, b, c, d;
    while(cin >> a >> b >> c >> d)
    {
        judge(a, b, c, d);
        if(!flag)
            cout << "No Solution!";
        flag = false;
    }
    return 0;
}
