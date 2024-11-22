// Given a tree with n nodes, and array a (0-base index) with the values of each node.
// You have to process q queries, each query has root and val, you have to add val for every node that is in the subtree of root. 
// Output the final value of every node.

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
vector<int> in, out;
int timer;

void dfs(int node, int par)
{
	in[node] = ++timer;

	for (auto c : g[node])
		if (c != par)
			dfs(c, node);

	out[node] = timer;
}

void Solve()
{
	int n, q;
	cin >> n >> q;

	// 1-base index.
	g.assign(n + 1, {});
	in.assign(n + 1, 0);
	out.assign(n + 1, 0);
	timer = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);
	vector<ll> temp(n + 2); // For 0 and n + 1 (unused).
	for (int i = 0; i < q; ++i)
	{
		int root, val;
		cin >> root >> val;

		temp[in[root]] += val; // The nodes that are in the subtree of the root are the ones who applies --> (in[root] <= in[node] <= out[root]).
		temp[out[root] + 1] -= val;
	}

	for (int i = 1; i < n + 2; ++i)
		temp[i] += temp[i - 1];

	vector<int> ans(n);
	for (int i = 1; i <= n; ++i)
		cout << a[i - 1] + temp[in[i]] << ' ';
	cout << endl;
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
