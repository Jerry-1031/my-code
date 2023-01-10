#include <cstdio>
#include <cmath>
#include <algorithm>

const int MAXN = 1000010;
int a[MAXN], bel[MAXN], cnt[MAXN], ans[MAXN];
struct Query
{
	int l, r, id;
} q[MAXN];
int main()
{
	int n;
	scanf("%d", &n);
	int size = sqrt(n), block = ceil(1. * n / size);
	for(int i = 1; i <= block; i++)
		for(int j = (i - 1) * size + 1; j <= i * size; j++)
			bel[j] = i;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m;
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	std::sort(q + 1, q + m + 1, [](Query x, Query y)
	// { return bel[x.l] == bel[y.l] ? x.r < y.r : bel[x.l] < bel[y.l]; });
	{ return bel[x.l] ^ bel[y.l] ? bel[x.l] < bel[y.l] : (bel[x.l] & 1 ? x.r < y.r : x.r > y.r); });
	int l = 1, r = 0, cur = 0;
	for(int i = 1; i <= m; i++)
	{
		int ql = q[i].l, qr = q[i].r;
		while(l < ql)
			cur -= !--cnt[a[l++]];
		while(l > ql)
			cur += !cnt[a[--l]]++;
		while(r < qr)
			cur += !cnt[a[++r]]++;
		while(r > qr)
			cur -= !--cnt[a[r--]];
		ans[q[i].id] = cur;
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}
