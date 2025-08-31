// https://cses.fi/problemset/task/1133/

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

const int N = 2e5 + 1;

int n;
vector<int> g[N];
ll dp[N];
int sz[N];

void dfs(int node, int par)
{
	for (auto c : g[node])
		if (c != par)
		{
			dfs(c, node);
			dp[node] += dp[c] + sz[c];
			sz[node] += sz[c];
		}

	sz[node] += 1;
}

void dp_dfs(int node, int par)
{
	for (auto c : g[node])
		if (c != par)
		{
			// I removed the answer of the child from the parent,
			// by removing dp[c], sz[c] from the dp[node],
			dp[c] += dp[node] - (dp[c] + sz[c]);

			// then because we move distance 1 from every other node
			// that is not in the subtree of c,
			// then we should add 1 * remaining nodes which are
			// n - sz[c].
			dp[c] += n - sz[c];

			dp_dfs(c, node);
		}
}

void Solve()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);
	dp_dfs(1, 0);

	for (int i = 1; i <= n; ++i)
		cout << dp[i] << ' ';
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
