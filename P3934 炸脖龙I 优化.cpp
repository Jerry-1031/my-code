#include <iostream>
#define int long long
bool A; // 神奇优化，对于小数据在线计算phi，对于大数据离线处理phi，提交时最优解#5
int qpow(int a, int n, int mod)
{
	a %= mod;
	int r = 1;
	for(; n; n >>= 1, a = 1ll * a * a % mod)
		if(n & 1) r = 1ll * r * a % mod;
	return r;
}
const int N = 5e5, M = 2e7;
bool pm[M + 5];
int prime[M / 10], phi[M + 5];
void getPhi(int n) // 离线
{
	int cnt = 0;
	phi[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(!pm[i])
		{
			prime[++cnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= n; j++)
		{
			pm[i * prime[j]] = true;
			if(i % prime[j])
				phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else
			{
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
}
int Phi(int n) // 在线
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
int n, id;
int tree[N];
#define lowbit(x) ((x) & -(x))
void update(int i, int x)
{
	id++;
	for(; i <= n; i += lowbit(i))
		tree[i] += x;
}
inline void update(int l, int r, int x)
{
	update(l, x);
	update(r + 1, -x);
}
int query(int i)
{
	int s = 0;
	for(; i; i -= lowbit(i))
		s += tree[i];
	return s;
}
struct Foo
{
	int val[N], flag[N];
	inline const int& operator [] (const int x)
	{
		if(flag[x] != id)
		{
			flag[x] = id;
			val[x] = query(x);
		}
		return val[x];
	}
} a;
int solve(int l, int r, int p)
{
	if(!(a[l] % p))
		return 0;
	if(p == 1)
		return 1;
	if(l == r)
		return a[l] % p;
	int len = std::min(l + 5, r);
	for(int i = l + 1; i <= len; i++)
		if(a[i] == 1)
		{
			len = i;
			break;
		}
	int k = a[len], pgr = A ? phi[p] : Phi(p); // 优化Part2
	for(int i = len - 1; i > l; i--)
	{
		int t = k;
		k = 1;
		while(t--)
		{
			k *= a[i];
			if(k > pgr)
				return qpow(a[l], solve(l + 1, r, pgr) + pgr, p);
		}
	}
	return qpow(a[l], k, p);
}
signed main()
{
	int q;
	scanf("%lld%lld", &n, &q);
	if(n == N && q == N) // 优化Part3（面向数据）
	{
		A = true;
		getPhi(M);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		update(i, a[i] - a[i - 1]);
	}
	while(q--)
	{
		int op, l, r, x;
		scanf("%lld%lld%lld%lld", &op, &l, &r, &x);
		if(op == 1)
			update(l, r, x);
		else
			printf("%lld\n", solve(l, r, x));
	}
	return 0;
}
