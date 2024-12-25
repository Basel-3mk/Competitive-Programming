// Given a directed weighted graph with n nodes and m edges.
// Output the maximum flow from the node 1 to the node n.

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define endl '\n'
#define ll long long

template<typename data_type>
using ordered_set = tree<data_type, null_type, less<data_type>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(high_resolution_clock::now().time_since_epoch().count());

int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

vector<vector<int>> g;
vector<array<int, 3>> edges;
vector<int> par;
int src, dst;

int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(src, INT_MAX));

	while (q.size())
	{
		int node = q.front().first, flow = q.front().second;
		q.pop();

		if (node == dst)
			return flow;

		for (auto idx : g[node])
		{
			int y = edges[idx][1], w = edges[idx][2];

			if (par[y] == -1 and w)
			{
				par[y] = idx;
				q.push(make_pair(y, min(flow, w)));
			}
		}
	}

	return 0;
}

void Solve()
{
	int n, m;
	cin >> n >> m;

	g.assign(n + 1, {});
	par.assign(n + 1, -1);
	edges.clear();
	src = 1;
	dst = n;

	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;

		g[x].push_back(cnt++);
		edges.push_back({ x, y, w });

		g[y].push_back(cnt++);
		edges.push_back({ y, x, 0 });
	}

	ll ans = 0;
	while (true)
	{
		fill(par.begin(), par.end(), -1);
		par[src] = -2;

		int flow = bfs();
		if (!flow)
			break;

		ans += flow;

		int node = dst;
		while (par[node] != -2)
		{
			edges[par[node]][2] -= flow;
			edges[par[node] ^ 1][2] += flow;
			node = edges[par[node]][0];
		}
	}

	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("C:\\Sublime\\input.txt", "r", stdin);
	freopen("C:\\Sublime\\output.txt", "w", stdout);
#endif

	Solve();

	cerr << "Basel Al-Jabari." << endl;

	return 0;
}
