// Given a weighted connected directed graph with n nodes, and m edges (1-base index).
// If there's a negative cycle output -1.
// Else output the shortest path from the node 1 to the other nodes.

// Note: If there's any negative weight in an undirected graph, automatically the answer will be -1 (No solution).
// But if there's a negative weight in a directed graph, then if there's a negative cycle then the answer will be -1 (No solution).
// Else we use Bellman Ford's Algorithm, or Floyd Warshall's Algorithm to find the answer.

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
vector<int> dist;

void Solve()
{
	int n, m;
	cin >> n >> m;

	// Edge List.
	g.clear();
	dist.assign(n + 1, INT_MAX);

	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;

		g.push_back({ x, y, w });
	}

	dist[1] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (auto edge : g)
		{
			int x = edge[0], y = edge[1], w = edge[2];

			// dist[x] != INT_MAX to prevent overflow in dist[x] + w.
			// We can fix it also by making dist long long instead of int.
			if (dist[x] != INT_MAX and dist[x] + w < dist[y])
				dist[y] = dist[x] + w;
		}

	bool neg_cycle = false;
	for (auto edge : g)
	{
		int x = edge[0], y = edge[1], w = edge[2];

		if (dist[x] != INT_MAX and dist[x] + w < dist[y])
			neg_cycle = true;
	}

	if (neg_cycle)
		cout << -1 << endl;

	else
	{
		for (int i = 2; i <= n; ++i)
			cout << dist[i] << ' ';
		cout << endl;
	}
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
