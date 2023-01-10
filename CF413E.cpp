#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5, inf = 0x3f3f3f3f;
char a[2][MAXN];

#define lson p << 1
#define rson p << 1 | 1

struct Node
{
	int d1, d2, d3, d4;
} tree[MAXN << 2];

// no modify, so no tag/pushdown need

/*
x111x
 2 3
  x
 3 2
x444x

d1: a[0] -> a[0]
d2: a[0] -> a[1]
d3: a[1] -> a[0]
d4: a[1] -> a[1]
*/

Node merge(const Node &x, const Node &y)
{
	Node t;
	t.d1 = min(x.d1 + y.d1, x.d2 + y.d3) + 1;
	t.d2 = min(x.d1 + y.d2, x.d2 + y.d4) + 1;
	t.d3 = min(x.d3 + y.d1, x.d4 + y.d3) + 1;
	t.d4 = min(x.d3 + y.d2, x.d4 + y.d4) + 1;
	return t;
}
void pushup(int p)
{
	tree[p] = merge(tree[lson], tree[rson]);
}

void build(int p, int l, int r)
{
	if(l == r)
	{
		Node &t = tree[p];
		t.d1 = t.d2 = t.d3 = t.d4 = inf;
		// l can be r
		if(a[0][l] == '.')
			t.d1 = 0;
		if(a[1][l] == '.')
			t.d4 = 0;
		if(a[0][l] == '.' && a[1][l] == '.')
			t.d2 = t.d3 = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	pushup(p);
}
Node query(int p, int l, int r, int L, int R)
{
	if(L <= l && r <= R)
		return tree[p];
	int mid = (l + r) >> 1;
	if(R <= mid)
		return query(lson, l, mid, L, R);
	if(mid < L)
		return query(rson, mid + 1, r, L, R);
	return merge(query(lson, l, mid, L, R), query(rson, mid + 1, r, L, R));
}

int main()
{
	int n, m;
	cin >> n >> m >> (a[0] + 1) >> (a[1] + 1);
	build(1, 1, n);
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		int l = (u - 1) % n + 1, r = (v - 1) % n + 1;
		if(l > r)
		{
			swap(l, r);
			swap(u, v);
		}
		Node t = query(1, 1, n, l, r);
		int ans;
		if(u <= n && v <= n) // u [0], v [0]
			ans = t.d1;
		if(u <= n && v > n) // u [0], v [1]
			ans = t.d2;
		if(u > n && v <= n) // u [1], v [0]
			ans = t.d3;
		if(u > n && v > n) // u [1], v [1]
			ans = t.d4;
		cout << (ans < inf ? ans : -1) << endl;
	}
	return 0;
}
