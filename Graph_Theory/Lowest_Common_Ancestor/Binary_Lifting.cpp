// Given a tree with n nodes, q queries, the tree root is node 1.
// The next n - 1 lines will give x, y (Edge between node x and node y)(1-base index).
// The next q lines will give a and b.
// For each query, output the lowest common ancestor of a and b.

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

vector<vector<int>> g, anc;
vector<int> lvl;

void dfs(int node, int par)
{
	// The (2 ^ i)th ancestor = The (2 ^ (i - 1))th ancestor of the (2 ^ (i - 1))th ancestor.
	anc[node][0] = par;
	for (int i = 1; i < 32; ++i)
		anc[node][i] = anc[anc[node][i - 1]][i - 1];

	for (auto c : g[node])
		if (c != par)
		{
			lvl[c] = lvl[node] + 1;
			dfs(c, node);
		}
}

int lca(int a, int b)
{
	if (lvl[a] < lvl[b])
		swap(a, b);

	int delta = lvl[a] - lvl[b];

	// Why from 31 not from 0?
	// To reach a specific number, we always start with MSB, not LSB.
	// If we start with LSB, it will be wrong.
	// For example: 16.
	// If we start from LSB --> 01111 = 15 and we will never reach 16.
	// If we start from MSB --> 10000 = 16 and we will always reach 16.
	// Sometimes, starting from LSB or MSB will be correct.
	// Such as the numbers with only ones like: 1, 3, 7, 15, 31. ((2 ^ n) - 1).
	for (int i = 31; i >= 0; --i)
		if ((delta >> i) & 1)
			a = anc[a][i];

	if (a == b)
		return a;

	for (int i = 31; i >= 0; --i)
		if (anc[a][i] != anc[b][i])
		{
			a = anc[a][i];
			b = anc[b][i];
		}

	return anc[a][0];
}

void Solve()
{
	int n, q;
	cin >> n >> q;

	g.assign(n + 1, {});
	anc.assign(n + 1, vector<int> (32, 0));
	lvl.assign(n + 1, 0);

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);

	while (q--)
	{
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << endl;
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
