#include <iostream>
using namespace std;

const unsigned int INITNUM = 100000;
int divsum(int x)
{
    int sum = 0;
    for(int i = 1; i < x; i++)
        if(x % i == 0)
            sum += i;
    return sum;
}
int main()
{
    for (int num1 = 1; num1 <= INITNUM; num1++)
    {
        int num2 = divsum(num1);
        if (num1 != num2 && num1 == divsum(num2))
            cout << num1 << " " << num2 << endl;
    }
    return 0;
}

