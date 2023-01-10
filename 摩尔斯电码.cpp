#include <iostream>
#include <algorithm>
using namespace std;

string morse[36] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
string a, b;

string change(char c)
{
    if ('A' <= c && c <= 'Z')
        return morse[c - 'A'];
    if ('a' <= c && c <= 'z')
        return morse[c - 'a'];
    if ('0' <= c && c <= '9')
        return morse[c - '0' + 26];
}

int main()
{
    getline(cin, a);
    for (int i = 0; i < a.length(); i++)
    {
    	b += change(a[i]);
    }
    cout << b << endl;
    return 0;
}
