// An Easy Brainfxxk Compiler & Runner

#include <iostream>
#include <stack>
using namespace std;

#define wc(c) O[len++] = c
const int SZ = 1 << 20, TM = 1 << 30;
int L[SZ], R[SZ], T[SZ];
char P[SZ], S[SZ], O[SZ];

bool complie(char *s)
{
	stack<int> st;
	for(int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == '[')
			st.push(i);
		else if(s[i] == ']')
			if(st.empty())
				return false;
			else
			{
				T[i] = st.top();
				st.pop();
			}
	}
	return true;
}

int run(char *s)
{
	int tot = 0, len = 0, cnt = 0, p = 1;
	tot++;
	for(int i = 0; s[i] != '\0'; i++, cnt++)
	{
		if(cnt > TM)
		{
			puts("Time Limit Exceeded!");
			return false;
		}
		if(tot > SZ)
		{
			puts("Memory Limit Exceeded!");
			return false;
		}
		if(len > SZ)
		{
			puts("Output Limit Exceeded!");
			return false;
		}
		switch(s[i])
		{
			case '<':
				if(!L[p])
				{
					L[p] = ++tot;
					R[tot] = p;
				}
				p = L[p];
				break;
			case '>':
				if(!R[p])
				{
					L[tot] = p;
					R[p] = ++tot;
				}
				p = R[p];
				break;
			case ']':
				if(P[p])
					i = T[i];
				break;
			case ',':
				P[p] = getchar();
				break;
			case '.':
				wc(P[p]);
				break;
			case'+':
				P[p]++;
				break;
			case '-':
				P[p]--;
				break;
		}
	}
	return len;
}

char sourcedir[256] = "source.txt";
char inputdir[256] = "in.txt";
char outputdir[256] = "out.txt";
int main()
{
	if(sourcedir[0] == '\0')
	{
		freopen("CON", "r", stdin);
		puts("Source File: ");
		scanf("%s", sourcedir);
	}
	freopen(sourcedir, "r", stdin);
	scanf("%s", S);

	if(!complie(S))
	{
		puts("Complie Error!");
		return 0;
	}

	if(inputdir[0] == '\0')
	{
		freopen("CON", "r", stdin);
		puts("Input File: ");
		scanf("%s", inputdir);
	}
	freopen(inputdir, "r", stdin);

	int l = run(S);
	if(l)
		puts("Run Successfully.");
	else
	{
		puts("Error Occurred!");
		return 0;
	}

	if(outputdir[0] == '\0')
	{
		freopen("CON", "r", stdin);
		puts("Output File: ");
		scanf("%s", outputdir);
	}
	freopen(outputdir, "w", stdout);
	fwrite(O, 1, l, stdout);
	return 0;
}
