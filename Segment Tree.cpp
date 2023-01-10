#include <iostream>
using namespace std;
const int inf = 1e9;
#define lson p << 1
#define rson p << 1 | 1
struct SegNode
{
	int sum;
	int l, r;
	int add, mul, tag;
} tree[40005];
void pushup(int p)
{
	tree[p].sum = tree[lson].sum + tree[rson].sum;
}
void pushdown(int p)
{
	if(tree[p].tag != inf)
	{
		tree[lson].sum = (tree[lson].r - tree[lson].l + 1) * tree[p].tag;
		tree[rson].sum = (tree[rson].r - tree[rson].l + 1) * tree[p].tag;
		tree[lson].add = tree[rson].add = 0;
		tree[lson].mul = tree[rson].mul = 1;
		tree[lson].tag = tree[rson].tag = tree[p].tag;
	}
	else
	{
		tree[lson].sum = tree[lson].sum * tree[p].mul + (tree[lson].r - tree[lson].l + 1) * tree[p].add;
		tree[rson].sum = tree[rson].sum * tree[p].mul + (tree[rson].r - tree[rson].l + 1) * tree[p].add;
		tree[lson].add = tree[p].add + tree[lson].add * tree[p].mul;
		tree[rson].add = tree[p].add + tree[rson].add * tree[p].mul;
		tree[lson].mul *= tree[p].mul;
		tree[rson].mul *= tree[p].mul;
	}
	tree[p].add = 0;
	tree[p].mul = 1;
	tree[p].tag = inf;
}
void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add = 0;
	tree[p].mul = 1;
	tree[p].tag = inf;
	if(l == r)
	{
		cin >> tree[p].sum;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	pushup(p);
}
void modifyAdd(int p, int L, int R, int k)
{
	if(L <= tree[p].l && tree[p].r <= R)
	{
		tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
		tree[p].add += k;
		return;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(L <= mid)
		modifyAdd(lson, L, R, k);
	if(mid < R)
		modifyAdd(rson, L, R, k);
	pushup(p);
}
void modifyMul(int p, int L, int R, int k)
{
	if(L <= tree[p].l && tree[p].r <= R)
	{
		tree[p].sum *= k;
		tree[p].add *= k;
		tree[p].mul *= k;
		return;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(L <= mid)
		modifyMul(lson, L, R, k);
	if(mid < R)
		modifyMul(rson, L, R, k);
	pushup(p);
}
void modifyAssign(int p, int L, int R, int k)
{
	if(L <= tree[p].l && tree[p].r <= R)
	{
		tree[p].sum = (tree[p].r - tree[p].l + 1) * k;
		tree[p].add = 0;
		tree[p].mul = 1;
		tree[p].tag = k;
		return;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(L <= mid)
		modifyAssign(lson, L, R, k);
	if(mid < R)
		modifyAssign(rson, L, R, k);
	pushup(p);
}
int querySum(int p, int L, int R)
{
	if(L <= tree[p].l && tree[p].r <= R)
		return tree[p].sum;
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1, ans = 0;
	if(L <= mid)
		ans += querySum(lson, L, R);
	if(mid < R)
		ans += querySum(rson, L, R);
	return ans;
}
int main()
{
	int n, q;
	cin >> n >> q;
	build(1, 1, n);
	while(q--)
	{
		int op, l, r, k;
		cin >> op >> l >> r;
		if(op == 1)
		{
			cin >> k;
			modifyAdd(1, l, r, k);
		}
		if(op == 2)
		{
			cin >> k;
			modifyMul(1, l, r, k);
		}
		if(op == 3)
		{
			cin >> k;
			modifyAssign(1, l, r, k);
		}
		if(op == 4)
			cout << querySum(1, l, r) << endl;
		for(int i = 1; i <= n; i++)
			cout << querySum(1, i, i) << ' ';
		cout << endl;
	}
	return 0;
}
