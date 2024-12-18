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

int n, src, dst;
vector<vector<int>> g;
vector<array<int, 3>> edges;
vector<int> lvl;

bool lvl_graph()
{
	fill(lvl.begin(), lvl.end(), -1);

	queue<int> q;
	q.push(src);
	lvl[src] = 0;

	while (q.size())
	{
		int node = q.front();
		q.pop();

		for (auto c : g[node])
		{
			int x = edges[c][0], y = edges[c][1], w = edges[c][2];

			if (lvl[y] == -1 and w)
			{
				lvl[y] = lvl[x] + 1;
				q.push(y);
			}
		}
	}

	return lvl[dst] != -1;
}

int augment_path(int node, int flow)
{
	if (node == dst)
		return flow;

	for (auto c : g[node])
	{
		int x = edges[c][0], y = edges[c][1], w = edges[c][2];

		if (w and lvl[y] == lvl[x] + 1)
		{
			int bottleneck = augment_path(y, min(flow, w));

			if (bottleneck)
			{
				// Forward edges have even indices.
				// Back edges have odd indices.
				// So when we want to remove value from one of them, then we have to add the same value to the complement of it.
				// So to change from even to odd, or odd to even, we just use xor 1.
				edges[c][2] -= bottleneck; 
				edges[c ^ 1][2] += bottleneck; 
				return bottleneck;
			}
		}
	}

	return 0;
}

int max_flow()
{
	int ans = 0;

	while (lvl_graph())
		while (int flow = augment_path(src, INT_MAX))
			ans += flow;

	return ans;
}

void Solve()
{
	int m;
	cin >> n >> m >> src >> dst;

	g.assign(n + 1, {});
	edges.assign(2 * m, {});
	lvl.assign(n + 1, -1);

	int cnt = 0;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;

		edges[cnt] = { x, y, w };
		g[x].push_back(cnt);
		cnt++;

		edges[cnt] = { y, x, 0 };
		g[y].push_back(cnt);
		cnt++;
	}

	cout << max_flow() << endl;
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
