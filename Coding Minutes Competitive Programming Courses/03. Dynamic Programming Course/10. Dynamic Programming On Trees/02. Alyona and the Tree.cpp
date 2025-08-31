// https://codeforces.com/contest/682/problem/C

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

const int N = 1e5 + 1;

vector<pair<int, int>> g[N];
int sz[N], val[N], ans = 0;
ll dp[N];

void dp_dfs(int node, int par)
{
	sz[node] = 1;

	for (auto [c, cost] : g[node])
		if (c != par)
		{
			dp[c] = max(1LL * cost, dp[node] + cost);
			dp_dfs(c, node);
			sz[node] += sz[c];
		}
}

void ans_dfs(int node, int par)
{
	if (val[node] < dp[node])
	{
		ans += sz[node];
		return;
	}

	for (auto [c, cost] : g[node])
		if (c != par)
			ans_dfs(c, node);
}

void Solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> val[i];

	for (int i = 2; i <= n; ++i)
	{
		int x, w;
		cin >> x >> w;

		g[x].push_back(make_pair(i, w));
		g[i].push_back(make_pair(x, w));
	}

	dp_dfs(1, 0);
	ans_dfs(1, 0);
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
