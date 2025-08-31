// https://www.spoj.com/problems/THREECOL/

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

const int N = 1e5 + 1, M = 3;

int dp[N][M];
vector<vector<int>> g;
string in;

void dfs1(int node)
{
	for (auto c : g[node])
		dfs1(c);

	if (g[node].size() == 0)
	{
		dp[node][0] = 0;
		dp[node][1] = 0;
		dp[node][2] = 1;
	}

	else if (g[node].size() == 1)
	{
		int c1 = g[node][0];
		dp[node][0] = max(dp[c1][1], dp[c1][2]);
		dp[node][1] = max(dp[c1][0], dp[c1][2]);
		dp[node][2] = max(dp[c1][0], dp[c1][1]) + 1;
	}

	else
	{
		int c1 = g[node][0], c2 = g[node][1];
		dp[node][0] = max(dp[c1][1] + dp[c2][2], dp[c1][2] + dp[c2][1]);
		dp[node][1] = max(dp[c1][0] + dp[c2][2], dp[c1][2] + dp[c2][0]);
		dp[node][2] = max(dp[c1][1] + dp[c2][0], dp[c1][0] + dp[c2][1]) + 1;
	}
}

void dfs2(int node)
{
	for (auto c : g[node])
		dfs2(c);

	if (g[node].size() == 0)
	{
		dp[node][0] = 0;
		dp[node][1] = 0;
		dp[node][2] = 1;
	}

	else if (g[node].size() == 1)
	{
		int c1 = g[node][0];
		dp[node][0] = min(dp[c1][1], dp[c1][2]);
		dp[node][1] = min(dp[c1][0], dp[c1][2]);
		dp[node][2] = min(dp[c1][0], dp[c1][1]) + 1;
	}

	else
	{
		int c1 = g[node][0], c2 = g[node][1];
		dp[node][0] = min(dp[c1][1] + dp[c2][2], dp[c1][2] + dp[c2][1]);
		dp[node][1] = min(dp[c1][0] + dp[c2][2], dp[c1][2] + dp[c2][0]);
		dp[node][2] = min(dp[c1][1] + dp[c2][0], dp[c1][0] + dp[c2][1]) + 1;
	}
}


int input(int index, int par)
{
	if (par)
		g[par].push_back(index);

	if (in[index - 1] == '1')
	{
		int ended = input(index + 1, index);
		return ended;
	}

	if (in[index - 1] == '2')
	{
		int ended1 = input(index + 1, index);
		int ended2 = input(ended1 + 1, index);
		return ended2;
	}

	return index;
}

void Solve()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> in;

		int n = in.size();
		g.assign(n + 1, {});

		input(1, 0);

		dfs1(1);
		cout << max({ dp[1][0], dp[1][1], dp[1][2] }) << ' ';

		dfs2(1);
		cout << min({ dp[1][0], dp[1][1], dp[1][2] }) << endl;
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
