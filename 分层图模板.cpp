//分层图模板: P4568, P2939, P4822
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Edge
{
	int to, nxt, w;
} e[4200005];
int head[220005], tot;
void add(int u, int v, int w)
{
	e[++tot] = Edge{v, head[u], w};
	head[u] = tot;
}
int dis[220005];
bool vis[220005];
void Dijkstra(int s)
{
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.emplace(0, s);
	while(!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if(!vis[u])
		{
			vis[u] = true;
			for(int i = head[u]; i; i = e[i].nxt)
			{
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].w)
				{
					dis[v] = dis[u] + e[i].w;
					q.emplace(dis[v], v);
				}
			}
		}
	}
}
int main()
{
	int n, m, k, s, t;
	cin >> n >> m >> k;
	s = 1, t = n;
	while(m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
		for(int i = 1; i <= k; i++)
		{
			add(u + n * i, v + n * i, w);
			add(v + n * i, u + n * i, w);
			add(u + n * (i - 1), v + n * i, 0);
			add(v + n * (i - 1), u + n * i, 0);
		}
	}
	for(int i = 1; i <= k; i++)
		add(t + n * (i - 1), t + n * i, 0);
	Dijkstra(s);
	cout << dis[t + n * k];
	return 0;
}
