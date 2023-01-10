#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const long long maxn = 1024, mod = 1e9 + 7;
string equation, element[maxn];
long long T, cnt, num, lst, flg;
long long mat[maxn][maxn], ion[maxn], l[maxn], r[maxn], ret[maxn], rem[maxn][maxn];
map<string, long long> appear;
stack<long long> ct;
bool haveion;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}
long long pw(long long a, long long b)
{
	long long res = 1;
	while(b)
	{
		if(b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
string readelement(long long pos)
{
	string res = "";
	while(true)
	{
		if(!islower(equation[pos]))
			break;
		res += equation[pos];
		pos++;
		if(!islower(equation[pos]))
			break;
	}
	return res;
}
long long readratio(long long pos)
{
	long long res = 0;
	if(!isdigit(equation[pos]))
		return 1;
	while(true)
	{
		res = (res << 3) + (res << 1) + equation[pos] - '0';
		pos++;
		if(!isdigit(equation[pos]))
			break;
	}
	return res;
}
long long readion(long long pos)
{
	long long res = 0;
	while(true)
	{
		if(!isdigit(equation[pos]))
			break;
		res = (res << 3) + (res << 1) + equation[pos] - '0';
		pos++;
		if(!isdigit(equation[pos]))
			break;
	}
	if(!res)
		res = 1;
	if(equation[pos] == '-')
		res = -res;
	pos++;
	return res;
}
void read(long long l, long long r, long long tmp)
{
	for(long long i = l; i <= r; i++)
	{
		if(equation[i] == '[')
		{
			ion[cnt] = readion(i + 1) * flg;
			haveion = true;
		}
		if(equation[i] == ')')
		{
			tmp /= ct.top();
			ct.pop();
		}
		if(equation[i] == '(')
		{
			long long o = 1, nw = -1;
			for(long long j = i + 1; j <= r; j++)
			{
				if(equation[j] == ')')
					o--;
				else if(equation[j] == '(')
					o++;
				if(!o)
				{
					nw = j + 1;
					break;
				}
			}
			ct.push(readratio(nw));
			tmp *= ct.top();
		}
		if(isupper(equation[i]))
		{
			string now = equation[i] + readelement(i + 1);
			long long p = i + 1;
			while(islower(equation[p]))
				p++;
			if(!appear[now])
			{
				appear[now] = ++num;
				element[num] = now;
			}
			mat[appear[now]][cnt] += readratio(p) * flg * tmp;
		}
	}
}
bool gauss()
{
	for(long long i = 1; i <= num; i++)
	{
		for(long long j = 1; j <= cnt; j++)
		{
			rem[i][j] = mat[i][j];
			((mat[i][j] %= mod) += mod) %= mod;
		}
		mat[i][cnt] = (mod - mat[i][cnt]) % mod;
	}
	for(long long i = 1; i < cnt; i++)
	{
		long long pos = i;
		for(long long j = i + 1; j <= num; j++)
			if(abs(mat[j][i]) > abs(mat[pos][i]))
				pos = j;
		for(long long j = i; j <= cnt; j++)
			swap(mat[i][j], mat[pos][j]);
		if(!mat[i][i])
			return 0;
		long long inv = pw(mat[i][i], mod - 2);
		for(long long j = i + 1; j <= num; j++)
		{
			long long tmp = mat[j][i] * inv % mod;
			for(long long k = i; k <= cnt; k++)
				(((mat[j][k] -= mat[i][k] * tmp % mod) %= mod) += mod) %= mod;
		}
	}
	for(long long i = cnt - 1; i; i--)
	{
		for(long long j = i + 1; j < cnt; j++)
			(((mat[i][cnt] -= mat[i][j] * mat[j][cnt] % mod) %= mod) += mod) %= mod;
		(mat[i][cnt] *= pw(mat[i][i], mod - 2)) %= mod;
	}
	long long res = 0;
	for(long long i = 1; i <= (1 << 15); i++)
	{
		bool sol = true;
		for(long long j = 1; j < cnt; j++)
			if(mat[j][cnt] * i % mod > (1 << 15))
			{
				sol = false;
				break;
			}
		if(!sol)
			continue;
		long long g = i;
		for(long long j = 1; j < cnt; j++)
			g = gcd(g, mat[j][cnt] * i % mod);
		if(g == 1)
			res++;
	}
	if(res - 1)
		return 0;
	for(long long i = 1; i <= (1 << 15); i++)
	{
		bool sol = true;
		for(long long j = 1; j < cnt; j++)
			if(mat[j][cnt] * i % mod > (1 << 15))
			{
				sol = false;
				break;
			}
		if(!sol)
			continue;
		long long g = i;
		for(long long j = 1; j < cnt; j++)
			g = gcd(g, mat[j][cnt] * i % mod);
		if(g == 1)
		{
			for(long long j = 1; j < cnt; j++)
				ret[j] = mat[j][cnt] * i % mod;
			ret[cnt] = i;
			break;
		}
	}
	for(long long i = 1; i <= cnt; i++)
		if(!ret[i])
			return 0;
	for(long long i = 1; i <= num; i++)
	{
		long long mogic = 0;
		for(long long j = 1; j <= cnt; j++)
			mogic += rem[i][j] * ret[j];
		if(mogic)
			return 0;
	}
	return 1;
}
void SetColor(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void trim(string &s)
{
	int index = 0;
	if(!s.empty())
		while((index = s.find(' ', index)) != string::npos)
			s.erase(index, 1);
}
int main()
{
	while(true)
	{
		SetColor(7, 0);
		appear.clear();
		cout << ">>> ";
		getline(cin, equation);
		trim(equation);
		if(equation.empty()) continue;
		flg = 1, lst = 0, cnt = 0, num = 0, haveion = false;
		memset(mat, 0, sizeof mat);
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		memset(ret, 0, sizeof ret);
		memset(ion, 0, sizeof ion);
		long long len = equation.length();
		for(long long i = 0; i < len; i++)
		{
			if(i == equation.length() - 1)
			{
				cnt++;
				read(lst, i, 1);
				l[cnt] = lst;
				r[cnt] = i;
			}
			if(equation[i] == '=' || equation[i] == '+' && equation[i + 1] == '(' || equation[i] == '+' && isupper(equation[i + 1]))
			{
				cnt++;
				read(lst, i, 1);
				l[cnt] = lst;
				r[cnt] = i;
				lst = i + 1;
			}
			if(equation[i] == '=')
				flg = -1;
		}
		if(haveion)
		{
			num++;
			for(long long i = 1; i <= cnt; i++)
				mat[num][i] = ion[i];
		}
		if(!gauss())
		{
			puts("-1");
			continue;
		}
		for(long long i = 1; i <= cnt; i++)
		{
			SetColor(9, 0);
			if(ret[i] > 1)
				cout << ret[i];
			SetColor(15, 0);
			cout << equation.substr(l[i], r[i] - l[i] + 1);
		}
		puts("");
	}
	return 0;
}
