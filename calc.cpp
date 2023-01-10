#include <iostream>
#include <stack>
using namespace std;

int calc(string s)
{
	stack<int> stk;
	int num = 0, len = s.length();
	char sign = '+';
	for(int i = 0; i < len; i++)
	{
		char c = s[i];
		if(isdigit(c))
			num = 10 * num - '0' + c;
		//if(c == '(')
			//num = calc(s.substr(i + 1, 1e9));
		if(!isdigit(c) && c != ' ' || i == len - 1)
		{
			switch(sign)
			{
				int p;
				case '+':
					stk.push(num);
					break;
				case '-':
					stk.push(-num);
					break;
				case '*':
					p = stk.top();
					stk.pop();
					stk.push(p * num);
					break;
				case '/':
					p = stk.top();
					stk.pop();
					stk.push(p / num);
					break;
			}
			sign = c;
			num = 0;
		}
		//if(c == ')')
			//break;
	}
	int r = 0;
	while(!stk.empty())
	{
		r += stk.top();
		stk.pop();
	}
	return r;
}
int main()
{
	string s;
	cin >> s;
	cout << calc(s);
	return 0;
}
