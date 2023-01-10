#include <iostream>
#include <set>
#include <cstring>
using namespace std;

#define IT set<Node>::iterator
const int MAXN = 100005, MAXM = 110, inf = 2.1e9;
int n, c;
struct Node
{
	int l, r;
	mutable int v;
	Node(int _l = 0, int _r = -1, int _v = 0) : l(_l), r(_r), v(_v) {}
	bool operator < (const Node &x) const
	{
		return l < x.l;
	}
};
set<Node> s;

#define lowbit(x) ((x) & -(x))
int T[MAXN];
void update(int i, int w)
{
	for(; i <= n; i += lowbit(i))
		T[i] += w;
}
int query(int i)
{
	int ans = 0;
	for(; i; i -= lowbit(i))
		ans += T[i];
	return ans;
}
inline int query(int l, int r)
{
	return query(r) - query(l - 1);
}

#define lson p << 1
#define rson p << 1 | 1
int tree[MAXN << 2];
void pushup(int p)
{
	tree[p] = max(tree[lson], tree[rson]);
}
void update(int p, int l, int r, int X, int w)
{
	if(l == r)
	{
		tree[p] = w;
		return;
	}
	int mid = (l + r) >> 1;
	if(X <= mid)
		update(lson, l, mid, X, w);
	else
		update(rson, mid + 1, r, X, w);
	pushup(p);
}
int query(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R)
		return tree[p];
	int mid = (l + r) >> 1, ans = 0;
	if(L <= mid)
		ans = max(ans, query(lson, l, mid, L, R));
	if(mid < R)
		ans = max(ans, query(rson, mid + 1, r, L, R));
	return ans;
}

IT split(int p)
{
	IT it = s.lower_bound(Node(p));
	if(it != s.end() && it -> l == p)
		return it;
	--it;
	int l = it -> l, r = it -> r, v = it -> v;
	s.erase(it);
	s.insert(Node(l, p - 1, v));
	return s.insert(Node(p, r, v)).first;
}
void assign(int l, int r, int v)
{
	IT itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(Node(l, r, v));
}

int t[MAXM];
int query3(int l, int r)
{
	memset(t, 0, sizeof t);
	int ans = inf, tl = c;
	IT itr = split(r + 1), itl = split(l);
	--itl;
	IT L = itl, R = itl;
	while(R != itr)
	{
		if(L != itl)
		{
			t[L -> v]--;
			if(t[L -> v] == 0)
				tl++;
		}
		++L;
		while(R != itr && tl)
		{
			++R;
			t[R -> v]++;
			if(t[R -> v] == 1)
				tl--;
		}
		if(R == itr)
			break;
		while(L != R && !tl)
		{
			t[L -> v]--;
			if(t[L -> v] == 0)
				tl++;
			++L;
		}
		if(tl)
		{
			--L;
			t[L -> v]++;
			tl--;
		}
		ans = min(ans, query(L -> r, R -> l));
	}
	return ans;
}

bool check(IT l, IT r)
{
	if(l == r || (++l)-- == r)
		return false;
	++l;
	for(IT it = l; it != r; ++it)
		if(it -> l != it -> r)
			return true;
	return false;
}
int query4(int l, int r)
{
	memset(t, 0, sizeof t);
	int ans = query(1, 1, n, l, r);
	IT itr = split(r + 1), itl = split(l), L = itl, R = itl;
	for(; R != itr; ++R)
	{
		t[R -> v]++;
		while(check(L, R) || (L != R && t[R -> v] > 1))
		{
			t[L -> v]--;
			++L;
		}
		if(L != R)
			ans = max(ans, query(L -> r, R -> l));
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> q >> c;
	s.insert(Node(0, 0, -1));
	for(int i = 1, a; i <= n; i++)
	{
		cin >> a;
		update(i, a);
		update(1, 1, n, i, a);
	}
	for(int i = 1, b; i <= n; i++)
	{
		cin >> b;
		s.insert(Node(i, i, b));
	}
	while(q--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int x, y;
			cin >> x >> y;
			update(x, y - query(x, x));
			update(1, 1, n, x, y);
		}
		if(op == 2)
		{
			int l, r, y;
			cin >> l >> r >> y;
			assign(l, r, y);
		}
		if(op == 3)
		{
			int l, r;
			cin >> l >> r;
			int a = query3(l, r);
			cout << (a == inf ? -1 : a) << endl;
		}
		if(op == 4)
		{
			int l, r;
			cin >> l >> r;
			cout << query4(l, r) << endl;
		}
	}
	return 0;
}
