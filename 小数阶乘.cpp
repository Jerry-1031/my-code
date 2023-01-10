#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double gamma(double x)
{
    double ret = (1.000000000190015 + 76.18009172947146 / (x+1) - 86.50532032941677 / (x+2) + 24.01409824083091 / (x+3) - 1.231739572450155 / (x+4) + 0.001208650973866179 / (x+5) - 0.000005395239384953 / (x+6)) * (2.506628274631000502415765284811 / x) * pow(x + 5.5, x + 0.5) * exp(-x - 5.5);
    return ret;
}
int main()
{
    double n;
    while(cin >> n)
        printf("%.5f! = %.15f\n", n, gamma(n + 1));
    return 0;
}