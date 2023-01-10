// Chtholly Tree
// Based on P5350
// Added CF896C
// By Jerry1031
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 5;
struct Node
{
	int l, r;
	mutable long long v;
	Node(int _l = 0, int _r = -1, long long _v = 0) : l(_l), r(_r), v(_v) {}
	bool operator<(const Node &x) const
	{
		return l < x.l;
	}
} A[MAXN], B[MAXN];
set<Node> s;

long long qpow(long long a, long long n, int mod)
{
	long long r = 1;
	for(; n >= 1; n >>= 1, a = a * a % mod)
		if(n & 1) r = r * a % mod;
	return r;
}

const int mod = 1e9 + 7;
auto split(int pos)
{
	auto it = s.lower_bound(Node(pos));
	if(it != s.end() && it -> l == pos)
		return it;
	--it;
	int l = it -> l, r = it -> r;
	long long v = it -> v;
	s.erase(it);
	s.insert(Node(l, pos - 1, v));
	return s.insert(Node(pos, r, v)).first;
}
void assign(int l, int r, long long v)
{
	auto itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(Node(l, r, v));
}
void add(int l, int r, long long v)
{
	auto itr = split(r + 1), itl = split(l);
	for(auto it = itl; it != itr; ++it)
		(it -> v += v) %= mod;
}

void copy(int l1, int r1, int l2, int r2)
{
	auto itr = split(r1 + 1), itl = split(l1);
	int p = 0;
	for(auto it = itl; it != itr; ++it)
		A[++p] = Node(it -> l, it -> r, it -> v);
	itr = split(r2 + 1), itl = split(l2);
	s.erase(itl, itr);
	for(int i = 1; i <= p; i++)
		s.insert(Node(A[i].l - l1 + l2, A[i].r - l1 + l2, A[i].v));
}
void change(int l1, int r1, int l2, int r2)
{
	if(l1 > l2)
	{
		swap(l1, l2);
		swap(r1, r2);
	}
	int p1 = 0;
	auto itr = split(r1 + 1), itl = split(l1);
	for(auto it = itl; it != itr; ++it)
		A[++p1] = Node(it -> l, it -> r, it -> v);
	s.erase(itl, itr);
	int p2 = 0;
	itr = split(r2 + 1), itl = split(l2);
	for(auto it = itl; it != itr; ++it)
		B[++p2] = Node(it -> l, it -> r, it -> v);
	s.erase(itl, itr);
	for(int i = 1; i <= p1; i++)
		s.insert(Node(A[i].l - l1 + l2, A[i].r - l1 + l2, A[i].v));
	for(int i = 1; i <= p2; i++)
		s.insert(Node(B[i].l + l1 - l2, B[i].r + l1 - l2, B[i].v));
}
void reverse(int l, int r)
{
	auto itr = split(r + 1), itl = split(l);
	int p = 0;
	for(auto it = itl; it != itr; ++it)
		A[++p] = Node(it -> l, it -> r, it -> v);
	s.erase(itl, itr);
	for(int i = 1; i <= p; i++)
		s.insert(Node(l + r - A[i].r, l + r - A[i].l, A[i].v));
}
long long query(int l, int r)
{
	auto itr = split(r + 1), itl = split(l);
	long long ans = 0;
	for(auto it = itl; it != itr; ++it)
		(ans += (it -> r - it -> l + 1ll) * it -> v) %= mod;
	return ans;
}

long long kth(int l, int r, int k)
{
	auto itr = split(r + 1), itl = split(l);
	vector<pair<long long, int> > v;
	for(auto it = itl; it != itr; ++it)
		v.push_back(make_pair(it -> v, it -> r - it -> l + 1));
	sort(v.begin(), v.end());
	for(auto i : v)
	{
		k -= i.second;
		if(k <= 0)
			return i.first;
	}
	return -1;
}
long long sum(int l, int r, int x, int p)
{
	long long ans = 0;
	auto itr = split(r + 1), itl = split(l);
	for(auto it = itl; it != itr; ++it)
		ans = (ans + qpow((it -> v) % p, x, p) * (it -> r - it -> l + 1)) % p;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		long long a;
		cin >> a;
		s.insert(Node(i, i, a));
	}
	s.insert(Node(n + 1, n + 1));
	while(m--)
	{
		int op, l, r;
		long long x, y;
		cin >> op >> l >> r;
		if(l > r)
			swap(l, r);
		if(op == 2)
		{
			cin >> x;
			assign(l, r, x);
		}
		if(op == 3)
		{
			cin >> x;
			add(l, r, x);
		}
		// P5350
		if(op == 1)
			cout << query(l, r) << '\n';
		if(op == 4)
		{
			cin >> x >> y;
			copy(l, r, x, y);
		}
		if(op == 5)
		{
			cin >> x >> y;
			change(l, r, x, y);
		}
		if(op == 6)
			reverse(l, r);
		// CF896C
		if(op == 7)
		{
			cin >> x;
			cout << kth(l, r, x) << '\n';
		}
		if(op == 8)
		{
			cin >> x >> y;
			cout << sum(l, r, x, y) << '\n';
		}
	}
	for(auto it = s.begin(); it != s.end() && it -> r <= n; ++it)
		for(int i = it -> l; i <= it -> r; i++)
			cout << (it -> v) << ' ';
	cout << flush;
	return 0;
}
