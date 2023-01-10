#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) ((x) & -(x))
const int MAXK = 1e5 + 5;
int n, m, k;
struct Node
{
	int x, y, k;
	inline bool operator < (const Node &b) const
	{
		return x == b.x ? y < b.y : x < b.x;
	}
} a[MAXK];
int u[MAXK], tree[MAXK];
void update(int i, int w)
{
	for(; i <= k; i += lowbit(i))
		tree[i] = max(tree[i], w);
}
int query(int i)
{
	int ans = 0;
	for(; i; i -= lowbit(i))
		ans = max(ans, tree[i]);
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].k;
		u[i] = a[i].y;
	}
	sort(u + 1, u + k + 1);
	m = unique(u + 1, u + k + 1) - u - 1;
	for(int i = 1; i <= k; i++)
		a[i].y = lower_bound(u + 1, u + m + 1, a[i].y) - u;
	sort(a + 1, a + k + 1);
	int ans = 0;
	for(int i = 1; i <= k; i++)
	{
		int t = query(a[i].y) + a[i].k;
		update(a[i].y, t);
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}
