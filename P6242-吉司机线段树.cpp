#include <iostream>
using namespace std;
const long long inf = 9e18;
#define lson p << 1
#define rson p << 1 | 1
struct TreeNode
{
	long long sum, max1, max2, maxhis, cnt;
	int l, r;
	long long tag1, tag2, tag3, tag4;
} tree[2000005];
void pushup(int p)
{
	tree[p].sum = tree[lson].sum + tree[rson].sum;
	tree[p].max1 = max(tree[lson].max1, tree[rson].max1);
	tree[p].maxhis = max(tree[lson].maxhis, tree[rson].maxhis);
	if(tree[lson].max1 == tree[rson].max1)
	{
		tree[p].max2 = max(tree[lson].max2, tree[rson].max2);
		tree[p].cnt = tree[lson].cnt + tree[rson].cnt;
	}
	if(tree[lson].max1 > tree[rson].max1)
	{
		tree[p].max2 = max(tree[lson].max2, tree[rson].max1);
		tree[p].cnt = tree[lson].cnt;
	}
	if(tree[lson].max1 < tree[rson].max1)
	{
		tree[p].max2 = max(tree[lson].max1, tree[rson].max2);
		tree[p].cnt = tree[rson].cnt;
	}
}
void build(int p, int l, int r)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		cin >> tree[p].sum;
		tree[p].max1 = tree[p].maxhis = tree[p].sum;
		tree[p].max2 = -inf;
		tree[p].cnt = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	pushup(p);
}
void update(int p, long long t1, long long t2, long long t3, long long t4)
{
	tree[p].sum += t1 * tree[p].cnt + t3 * (tree[p].r - tree[p].l + 1 - tree[p].cnt);
	tree[p].maxhis = max(tree[p].maxhis, tree[p].max1 + t2);
	tree[p].max1 += t1;
	if(tree[p].max2 != -inf)
		tree[p].max2 += t3;
	tree[p].tag2 = max(tree[p].tag2, tree[p].tag1 + t2);
	tree[p].tag1 += t1;
	tree[p].tag4 = max(tree[p].tag4, tree[p].tag3 + t4);
	tree[p].tag3 += t3;
}
void pushdown(int p)
{
	long long t = max(tree[lson].max1, tree[rson].max1);
	if(tree[lson].max1 == t)
		update(lson, tree[p].tag1, tree[p].tag2, tree[p].tag3, tree[p].tag4);
	else
		update(lson, tree[p].tag3, tree[p].tag4, tree[p].tag3, tree[p].tag4);
	if(tree[rson].max1 == t)
		update(rson, tree[p].tag1, tree[p].tag2, tree[p].tag3, tree[p].tag4);
	else
		update(rson, tree[p].tag3, tree[p].tag4, tree[p].tag3, tree[p].tag4);
	tree[p].tag1 = tree[p].tag2 = tree[p].tag3 = tree[p].tag4 = 0;
}
void modifyAdd(int p, int L, int R, int k)
{
	if(tree[p].l > R || tree[p].r < L)
		return;
	if(L <= tree[p].l && tree[p].r <= R)
	{
		update(p, k, k, k, k);
		return;
	}
	pushdown(p);
	modifyAdd(lson, L, R, k);
	modifyAdd(rson, L, R, k);
	pushup(p);
}
void modifyMin(int p, int L, int R, int k)
{
	if(tree[p].l > R || tree[p].r < L || tree[p].max1 <= k)
		return;
	if(L <= tree[p].l && tree[p].r <= R && tree[p].max2 < k)
	{
		update(p, k - tree[p].max1, k - tree[p].max1, 0, 0);
		return;
	}
	pushdown(p);
	modifyMin(lson, L, R, k);
	modifyMin(rson, L, R, k);
	pushup(p);
}
long long querySum(int p, int L, int R)
{
	if(tree[p].l > R || tree[p].r < L)
		return 0;
	if(L <= tree[p].l && tree[p].r <= R)
		return tree[p].sum;
	pushdown(p);
	return querySum(lson, L, R) + querySum(rson, L, R);
}
long long queryMax(int p, int L, int R)
{
	if(tree[p].l > R || tree[p].r < L)
		return -inf;
	if(L <= tree[p].l && tree[p].r <= R)
		return tree[p].max1;
	pushdown(p);
	return max(queryMax(lson, L, R), queryMax(rson, L, R));
}
long long queryMaxHis(int p, int L, int R)
{
	if(tree[p].l > R || tree[p].r < L)
		return -inf;
	if(L <= tree[p].l && tree[p].r <= R)
		return tree[p].maxhis;
	pushdown(p);
	return max(queryMaxHis(lson, L, R), queryMaxHis(rson, L, R));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
			modifyMin(1, l, r, k);
		}
		if(op == 3)
			cout << querySum(1, l, r) << endl;
		if(op == 4)
			cout << queryMax(1, l, r) << endl;
		if(op == 5)
			cout << queryMaxHis(1, l, r) << endl;
	}
	return 0;
}
