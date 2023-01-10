// 模板 by Jerry1031
#include <bits/stdc++.h>
#include <windows.h>
#include <cxxabi.h>
using namespace std;

#define let const auto
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;

constexpr int mod = 998244353, g = 3, invg = 332748118;
constexpr double EPS = 1e-6;
constexpr long double Pi = 3.14159265358979323846264338327950288419716939937511L;
constexpr long double E = 2.71828182845904523536028747135266249775724709369996L;
constexpr long double Phi = 1.61803398874989484820458683436563811772030917980576L;
constexpr long double EulerGamma = 0.57721566490153286060651209008240243104215933593992L;
constexpr long double Sqrt2 = 1.4142135623730950488016887242096980785696718753769L;
constexpr long double Sqrt3 = 1.7320508075688772935274463415058723669428052538104L;
constexpr long double Sqrt5 = 2.2360679774997896964091736687312762354406183596115L;
constexpr long double GoldenRatio = 1.6180339887498948482045868343656381177203091798058L;
constexpr int LightSpeed = 299792458;

// 快速幂
int qpow(int a, int n)
{
	int r = 1;
	for(; n; n >>= 1, a = 1ll * a * a % mod)
		if(n & 1) r = 1ll * r * a % mod;
	return r;
}
int qpow(int a, int n, const int p)
{
	int r = 1;
	for(; n; n >>= 1, a = 1ll * a * a % p)
		if(n & 1) r = 1ll * r * a % p;
	return r;
}

// 求逆/乘法逆元
int inv(int n, int p)
{
	if(n == 0 || n == 1)
		return n;
	return (long long)(p - p / n) * inv(p % n, p) % p;
}

// 快速乘
long long qmul(long long a, long long b, long long p)
{
	long long r = 0;
	for(; b; b >>= 1, a = (a + a) % p)
		if(b & 1) r = (r + a) % p;
	return r;
}
inline long long ldmul(long long a, long long b, long long p)
{
	return (a * b - (long long)((long double)a / p * b) * p + p) % p;
}
inline int mul(int a, int b, int p)
{
	int x;
	__asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n" : "=d"(x) : "a"(a), "b"(b), "c"(p));
	return x;
}

// 内嵌汇编随机数
inline int Rand()
{
	int x;
	__asm__ ("rdrand %%eax" : "=a" (x));
	return x;
}

// 光标移到(x, y)
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 数字的位数
int digits(int x)
{
	int d = 1;
	while(x /= 10) d++;
	return d;
}

// 无符号整数开根
// 支持 0 ~ 4294967295
unsigned Isqrt(unsigned n)
{
	unsigned x = n, a = 0, b = 1 << 30;
	while(b > n)
		b >>= 2;
	while(b)
	{
		if(x >= a + b)
		{
			x -= a + b;
			a = (a >> 1) + b;
		}
		else
			a >>= 1;
		b >>= 2;
	}
	return a;
}

// 质数判断
bool isPrime(int n)
{
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}
bool is_Prime(unsigned long long n)
{
	if(n < 2) return false;
	if(n < 4) return true;
	if(!(n & 1) || n % 3 == 0)
		return false;
	for(unsigned int i = 5; i * i <= n; i += 6)
		if(n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}

bool MillerRabin(int x)
{
	int test[10] = {2, 3, 5, 7, 11, 13, 17};
	if(x == 1)
		return 0;
	int t = x - 1, k = 0;
	while(!(t & 1))
		k++, t >>= 1;
	for(int i = 0; i < 4; i++)
	{
		if(x == test[i])
			return 1;
		long long a = qpow(test[i], t, x), nxt = a;
		for(int j = 1; j <= k; j++)
		{
			nxt = (a * a) % x;
			if(nxt == 1 && a != 1 && a != x - 1)
				return false;
			a = nxt;
		}
		if(a != 1)
			return false;
	}
	return true;
}

// 欧拉函数 φ
int phi(int n)
{
	int ans = n;
	for(int i = 2; i * i <= n; i++)
		if(!(n % i))
		{
			ans = ans / i * (i - 1);
			while(!(n % i))
				n /= i;
		}
	if(n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

// 生成质数/欧拉函数
struct Prime
{
	bool p[100005];
	int prime[10000], phi[100005], mu[100005];
	void get_Prime(int n)
	{
		int cnt = 0;
		for(int i = 2; i <= n; i++)
		{
			if(!p[i])
				prime[++cnt] = i;
			for(int j = i + i; j <= n; j += i)
				p[j] = true;
		}
	}
	void getPrime(int n)
	{
		int cnt = 0;
		for(int i = 2; i <= n; i++)
		{
			if(!p[i])
				prime[++cnt] = i;
			for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
			{
				p[i * prime[j]] = true;
				if(i % prime[j] == 0)
					break;
			}
		}
	}
	void get_Phi(int n)
	{
		phi[1] = 1;
		for(int i = 2; i <= n; i++)
			if(!phi[i])
				for(int j = i; j <= n; j += i)
				{
					if(!phi[j])
						phi[j] = j;
					phi[j] = phi[j] / i * (i - 1);
				}
	}
	void getPhi(int n)
	{
		for(int i = 1; i <= n; i++)
			phi[i] = i;
		for(int i = 2; i <= n; i++)
			if(phi[i] == i)
				for(int j = i; j <= n; j += i)
					phi[j] = phi[j] / i * (i - 1);
	}
	void getPrimePhiMu(int n)
	{
		int cnt = 0;
		phi[1] = mu[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			if(!p[i])
			{
				prime[++cnt] = i;
				phi[i] = i - 1;
				mu[i] = -1;
			}
			for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
			{
				p[i * prime[j]] = true;
				if(i % prime[j])
				{
					phi[i * prime[j]] = phi[i] * phi[prime[j]];
					mu[i * prime[j]] = -mu[i];
				}
				else
				{
					phi[i * prime[j]] = phi[i] * prime[j];
					mu[i * prime[j]] = 0;
					break;
				}
			}
		}
	}
};

// lowbit
inline int lowbit(int x)
{
	return x & -x;
}

// 回文数
int reverse(int x)
{
	int t = 0;
	while(x)
	{
		t = t * 10 + x % 10;
		x /= 10;
	}
	return t;
}

// 最大公约数
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int gcd2(int a, int b)
{
	while(b ^= a ^= b ^= a %= b);
	return a;
}

// 扩展欧几里得
// 求 ax + by = gcd(a, b)，返回值为 gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

// Lucas 定理
// 求 C(n)(m)
long long fact[100010];
void initfact(int p)
{
	fact[0] = 1;
	for(int i = 1; i <= p; i++)
		fact[i] = fact[i - 1] * i % p;
}
long long C(long long n, long long m, int p)
{
	return m > n ? 0 : fact[n] * qpow(fact[m], p - 2, p) * qpow(fact[n - m], p - 2, p) % p;
}
long long Lucas(long long n, long long m, int p)
{
	return m ? C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p : 1;
}

// 中国剩余定理 CRT
int CRT(int a[], int b[], int n)
{
	int p = 1, x = 0;
	for(int i = 1; i <= n; i++)
		p *= a[i];
	for(int i = 1; i <= n; i++)
	{
		int r = p / a[i];
		x += (b[i] * r * inv(r, a[i])) % p;
	}
	return x % p;
}
int CRT2(int a[], int b[], int n)
{
	int p = 1, ans = 0;
	for(int i = 1; i <= n; i++)
		p *= b[i];
	for(int i = 1; i <= n; i++)
	{
		int r = p / b[i], x, y;
		exgcd(b[i], r, x, y);
		ans = (ans + qmul(y, qmul(r, a[i] + p, p), p)) % p;
	}
	return (ans + p) % p;
}

// KMP 字符串匹配
int KMP(string s, string p, int n, int m)
{
	int pos[10010], pmt[10010];
	int cnt = 0;
	for(int i = 1, j = 0; i < m; i++)
	{
		while(j && p[i] != p[j])
			j = pmt[j - 1];
		if(p[i] == p[j])
			j++;
		pmt[i] = j;
	}
	for(int i = 0, j = 0; i < n; i++)
	{
		while(j && s[i] != p[j])
			j = pmt[j - 1];
		if(s[i] == p[j])
			j++;
		if(j == m)
		{
			pos[++cnt] = i - j + 2;
			j = pmt[j - 1];
		}
	}
	return cnt;
}

// 最长上升子序列长度 (LIS)
// O(n^2)
int LIS(int a[], int n)
{
	static int f[1010];
	int len = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
		len = max(len, f[i]);
	}
	return len;
}
// O(n log n)
// 二分搜索段也可用 upper_bound
int LIS2(int a[], int n)
{
	static int f[1010];
	f[1] = a[1];
	int len = 1;
	for(int i = 2; i <= n; i++)
	{
		f[i] = 1e9;
		if(a[i] > f[len])
			f[++len] = a[i];
		else
		{
			int l = 0, r = len;
			while(l < r)
			{
				int mid = (l + r) >> 1;
				if(f[mid] > a[i])
					r = mid;
				else
					l = mid + 1;
			}
			f[l] = min(a[i], f[l]);
		}
	}
	return len;
}

// 最长公共子序列长度 (LCS)
// O(nm)
int LCS(int a[], int b[], int n, int m)
{
	static int f[1010][1010];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	return f[n][m];
}

// 马拉车（最长回文子串）
int Manacher(string s, int n)
{
	static int p[2010];
	string t = "**";
	for(int i = 0; i < n; i++)
	{
		t += s[i];
		t += "*";
	}
	n = (n << 1) + 1;
	int r = 0, mid = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i <= r)
			p[i] = min(p[(mid << 1) - i], r - i + 1);
		while(t[i - p[i]] == t[i + p[i]])
			p[i]++;
		if(p[i] + i > r)
		{
			r = p[i] + i - 1;
			mid = i;
		}
		if(p[i] > ans)
			ans = p[i];
	}
	return ans - 1;
}

// 树状数组
class BIT
{
#define lowbit(x) ((x) & -(x))
	int n, tree[10010];
	void update(int i, int w)
	{
		for(; i <= n; i += lowbit(i))
			tree[i] += w;
	}
	int query(int i)
	{
		int s = 0;
		for(; i; i -= lowbit(i))
			s += tree[i];
		return s;
	}
	int query(int l, int r)
	{
		return query(r) - query(l - 1);
	}
};

// 并查集
class Union_Find
{
	int fa[5010], rnk[5010];
	void init(int n)
	{
		for(int i = 1; i <= n; i++)
		{
			fa[i] = i;
			rnk[i] = 1;
		}
	}
	int find(int x)
	{
		return x == fa[x] ? x : (fa[x] = find(fa[x]));
	}
	void merge(int a, int b)
	{
		int x = find(a), y = find(b);
		if(rnk[x] <= rnk[y])
			fa[x] = y;
		else
			fa[y] = x;
		if(rnk[x] == rnk[y] && x != y)
			rnk[y]++;
	}
};

// 匈牙利算法（二分图最大匹配）
class Hungarian
{
	int n, m;
	bool map[110][110], vis[110];
	int p[110];
	bool match(int i)
	{
		for(int j = 1; j <= m; j++)
			if(map[i][j] && !vis[j])
			{
				vis[j] = true;
				if(p[j] == 0 || match(p[j]))
				{
					p[j] = i;
					return true;
				}
			}
		return false;
	}
	int find()
	{
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			memset(vis, 0, sizeof vis);
			if(match(i))
				cnt++;
		}
		return cnt;
	}
};

// 线段树（区间修改，区间求和）
class Segment_Tree
{
	long long tree[40005], tag[4005];
#define lson p << 1
#define rson p << 1 | 1
	void pushup(int p)
	{
		tree[p] = tree[lson] + tree[rson];
	}
	void build(int p, int l, int r)
	{
		if(l == r)
		{
			cin >> tree[p];
			return;
		}
		int mid = (l + r) >> 1;
		build(lson, l, mid);
		build(rson, mid + 1, r);
		pushup(p);
	}
	void pushdown(int p, int x)
	{
		tree[lson] += tag[p] * (x - (x >> 1));
		tag[lson] += tag[p];
		tree[rson] += tag[p] * (x >> 1);
		tag[rson] += tag[p];
		tag[p] = 0;
	}
	void update(int p, int l, int r, int L, int R, long long w)
	{
		if(L <= l && r <= R)
		{
			tree[p] += w * (r - l + 1);
			tag[p] += w;
			return;
		}
		pushdown(p, r - l + 1);
		int mid = (l + r) >> 1;
		if(L <= mid)
			update(lson, l, mid, L, R, w);
		if(mid < R)
			update(rson, mid + 1, r, L, R, w);
		pushup(p);
	}
	long long query(int p, int l, int r, int L, int R)
	{
		if(L <= l && r <= R)
			return tree[p];
		pushdown(p, r - l + 1);
		int mid = (l + r) >> 1;
		long long ans = 0;
		if(L <= mid)
			ans += query(lson, l, mid, L, R);
		if(mid < R)
			ans += query(rson, mid + 1, r, L, R);
		return ans;
	}
};

// 矩阵
struct Matrix
{
	int n, a[110][110];
	Matrix()
	{
		memset(a, 0, sizeof a);
	}
	/*
	Matrix(int n = 1, int k = 0) : n(n)
	{
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i++)
			a[i][i] = k;
	}
	*/
	Matrix operator + (const Matrix& T) const
	{
		Matrix res;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				res.a[i][j] = (a[i][j] + T.a[i][j]) % mod;
		return res;
	}
	Matrix operator - (const Matrix& T) const
	{
		Matrix res;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				res.a[i][j] = (a[i][j] - T.a[i][j]) % mod;
		return res;
	}
	Matrix operator * (const Matrix& T) const
	{
		Matrix res;
		for(int i = 1; i <= n; i++)
			for(int k = 1; k <= n; k++)
				for(int j = 1; j <= n; j++)
					(res.a[i][j] += T.a[k][j] * a[i][k]) %= mod;
		return res;
	}
	Matrix operator ^ (int x) const
	{
		Matrix ans, base;
		for(int i = 1; i <= n; i++)
			ans.a[i][i] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				base.a[i][j] = a[i][j] % mod;
		for(; x; x >>= 1, base = base * base)
			if(x & 1)
				ans = ans * base;
		return ans;
	}
};
// 矩阵快速幂
void mpow(int n, Matrix &ans, Matrix &base)
{
	for(; n; n >>= 1, base = base * base)
		if(n & 1)
			ans = ans * base;
}
struct Matrix67
{
	ll arr[2][2];
	Matrix67()
	{
		memset(arr, 0, sizeof arr);
	}
	ll* operator [] (int i)
	{
		return arr[i];
	}
	Matrix67 operator * (const Matrix67 &b) const
	{
		Matrix67 r;
		for(int i = 0; i < 2; i++)
			for(int k = 0; k < 2; k++)
				for(int j = 0; j < 2; j++)
					r[i][j] += arr[i][k] * b.arr[k][j];
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				r[i][j] %= mod;
		return r;
	}
};
void mpow(int n, Matrix67 &ans, Matrix67 &base)
{
	for(; n; n >>= 1, base = base * base)
		if(n & 1)
			ans = ans * base;
}
// 求解广义斐波那契数列第 n 项
// a[n] = p * a[n-1] + q * [n-2]
// 洛谷 P1349
int solveFib(int n, int p, int q, int a1, int a2)
{
	Matrix67 ans = Matrix67(), base = Matrix67();
	ans[0][0] = a2, ans[0][1] = a1;
	base[0][0] = p, base[1][0] = q, base[0][1] = 1;
	mpow(n - 2, ans, base);
	return ans[0][0] % mod;
}

// 非精确求方程实根
class solveEQ
{
	double f(double x)
	{
		return x * x * x - 5 * x * x - 4 * x + 20;
	}
	// 二分法
	double solveBinary(double l, double r)
	{
		while(r - l > EPS)
		{
			double mid = (l + r) / 2;
			if(abs(f(mid)) < EPS)
				return mid;
			//if(f(l) > 0 && f(mid) > 0 || f(l) < 0 && f(mid) < 0)
			if(f(l) * f(mid) > 0)
				l = mid;
			else
				r = mid;
		}
		return (l + r) / 2;
	}
	// 牛顿迭代法
	double f_(double x) // f(x)的导函数f'(x)
	{
		return 3 * x * x - 10 * x - 4;
	}
	double solveNewton(double x)
	{
		while(abs(f(x)) > EPS)
			x -= f(x) / f_(x);
		return x;
	}
	// 割线法
	double solveSecant(double x0, double x1)
	{
		double x;
		while(abs(x1 - x0) > EPS)
		{
			x = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
			x0 = x1;
			x1 = x;
		}
		return x;
	}
};

// Simpson 定积分
class Simpson_Integrate
{
	// 递归
	double f(double x)
	{
		// Do Something
		return x;
	}
	inline double simpson(double l, double r)
	{
		return (r - l) * (f(l) + 4 * f((l + r) / 2) + f(r)) / 6;
	}
	double asr(double l, double r, double ans)
	{
		double mid = (l + r) / 2;
		double L = simpson(l, mid), R = simpson(mid, r);
		if(fabs(L + R - ans) < EPS)
			return L + R;
		else
			return asr(l, mid, L) + asr(mid, r, R);
	}
	inline double NIntegrate(double l, double r)
	{
		return asr(l, r, simpson(l, r));
	}
	// 非递归
	// 极端情况误差较大
	double Simpson(double a, double b)
	{
		const int n = 1000;
		double h = (b - a) / n, s = f(a) + f(b);
		for(int i = 1; i < n; i += 2)
			s += 4 * f(a + i * h);
		for(int i = 2; i < n - 1; i += 2)
			s += 2 * f(a + i * h);
		return s * h / 3.0;
	}
};

// 模拟退火
class Simulated_Annealing
{
	int calc()
	{
		// Do Something
		return 0;
	}
	const double T_BEGIN = 3000, T_EPS = 1e-9, T_DELTA = 0.99;
	int ans;
	void SA()
	{
		for(double T = T_BEGIN; T > T_EPS; T *= T_DELTA)
		{
			int ans_ = calc(), d = ans_ - ans;
			if(d < 0)
			{
				// 更新答案
				ans = ans_;
				// Do Something
			}
			else if(exp(-d / T) * RAND_MAX > rand())
			{
				// Do Something
			}
		}
	}
};

// 01分数规划
class ZeroOne
{
	int n, k, a[1010], b[1010];
	double c[1010];
	bool check(double x)
	{
		for(int i = 1; i <= n; i++)
			c[i] = a[i] - x * b[i];
		sort(c + 1, c + n + 1);
		double ans = 0;
		for(int i = k + 1; i <= n; i++)
			ans += c[i];
		return ans >= 0;
	}
	double solve()
	{
		double l = 0, r = 1e9;
		while(r - l > EPS)
		{
			double mid = (l + r) / 2;
			if(check(mid))
				l = mid;
			else
				r = mid;
		}
		return l;
	}
};

// 是否是完全平方数
bool isPerfectSquare(int x)
{
	return sqrt(x) == int(x + 0.5);
}

// 因数个数
int fracs(int x)
{
	int f = 0, t = x;
	for(int i = 1; i * i <= x; i++)
		if(!(x % i))
		{
			f++;
			t /= x;
		}
	f *= 2;
	if(isPerfectSquare(x))
		f--;
	return f;
}

// 数字各位的和
int sumD(int n)
{
	return (n - 1) % 9 + 1;
}

// 是否为闰年
bool isLeapYear(int y)
{
	return (!(y % 4) && y % 100) || !(y % 400);
}

// 下一个合法日期(yyyymmdd)
int nextDate(int x)
{
	int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y, m, d;
	d = x % 100;
	x /= 100;
	m = x % 100;
	x /= 100;
	y = x;
	if(m == 2 && isLeapYear(y))
	{
		if(d == 29)
		{
			m++;
			d = 1;
		}
		else
			d++;
	}
	else
	{
		if(day[m] == d)
		{
			if(m == 12)
			{
				y++;
				m = 1;
				d = 1;
			}
			else
			{
				m++;
				d = 1;
			}
		}
		else
			d++;
	}
	return y * 10000 + m * 100 + d;
}

// 两点间距离
double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// 递归 max
template <typename T>
T MAX(T a, T b)
{
	return a > b ? a : b;
}
template <typename First, typename... Rest>
First MAX(First first, Rest... rest)
{
	return MAX(first, MAX(rest...));
}

// int读入优化
int readint()
{
	char C = getchar();
	int N = 0, F = 1;
	while(('0' > C || C > '9') && (C != '-'))
		C = getchar();
	if(C == '-')
		F = -1, C = getchar();
	while('0' <= C && C <= '9')
		N = (N << 1) + (N << 3) + (C - 48), C = getchar();
	return F * N;
}

// 双调排序(n为2的幂次)
void bitonicSort(int a[], int n)
{
	int t;
	for(int i = 1, i2 = 2; i2 <= n; i++, i2 <<= 1)
	{
		for(int j = 1, j2 = i2 - 1; j2 >= 1; j++, j2 -= 2)
			for(int k = j; k <= n; k += i2)
				if(a[k] < a[k + j2])
					t = a[k], a[k] = a[k + j2], a[k + j2] = t;
		for(int j = (i2 >> 2); j >= 1; j >>= 1)
			for(int k = 1; k <= j; k++)
				for(int l = k; l <= n; l += (j << 1))
					if(a[l] < a[l + j])
						t = a[l], a[l] = a[l + j], a[l + j] = t;
	}
}

// 希尔排序
// O(n^1.3)
void shellSort(int a[], int l)
{
	int h = 1;
	while(h + h < l)
		h = h + h + 1;
	while(h /= 2)
		for(int i = h; i < l; i++)
			for(int j = i; j >= h && a[j] < a[j - h]; j -= h)
				swap(a[j], a[j - h]);
}

// 变量类型
const char* type(auto x)
{
	return typeid(x).name();
	// or
	return abi::__cxa_demangle(typeid(x).name(), 0, 0, 0);
}

// 获取用户名
string GetUsername()
{
	char currentUser[256] = {};
	DWORD dwSize = 256;
	GetUserName(currentUser, &dwSize);
	return currentUser;
}

// int128模板
void read(__int128 &x)
{
	x = 0;
	short f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	x *= f;
}
__int128 read()
{
	__int128 x = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}
void write(__int128 x)
{
	if(x < 0)
		putchar('-'), x = -x;
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

// 位运算卡常技巧
// 转换为小写
inline char toLower(char c)
{
	return c | ' ';
}
// 转换为大写
inline char toUpper(char c)
{
	return c & '_';
}
// 大小写互转
inline char toInv(char c)
{
	return c ^ ' ';
}
// 判断是否异号
inline bool isSignDiff(int a, int b)
{
	return (a ^ b) < 0;
}
// 是否是 2 的指数
inline bool isPowerOfTwo(int n)
{
	return !(n & (n - 1));
}
// 只出现一次的数
inline int singleNumber(vector<int> a)
{
	int r = 0;
	for(int n : a)
		r ^= n;
	return r;
}
// 汉明距离（二进制）
inline int HammingDistance(int x, int y)
{
	return __builtin_popcount(x ^ y);
}

// invsqrt  1/sqrt(x)
float Q_Rsqrt( float number )
{
	long i;
	float x2, y;
	const float threeHalfs = 1.5f;
	x2 = number * 0.5f;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // What the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threeHalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threeHalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
	return y;
}
