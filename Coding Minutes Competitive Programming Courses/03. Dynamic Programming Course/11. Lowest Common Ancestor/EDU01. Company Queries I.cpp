// https://cses.fi/problemset/task/1687/

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

const int N = 2e5 + 1, M = 32;

int anc[N][M];
vector<int> g[N];

void dfs(int node, int par)
{
	anc[node][0] = par;
	for (int i = 1; i < M; ++i)
		anc[node][i] = anc[anc[node][i - 1]][i - 1];

	for (auto c : g[node])
		if (c != par)
			dfs(c, node);
}

int ancestor(int x, int k)
{
	for (int i = 31; ~i; --i)
	{
		if ((1LL << i) <= k)
		{
			k -= (1 << i);
			x = anc[x][i];
		}
	}

	return (k == 0 ? (x == 0 ? -1 : x) : -1);
}

void Solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;

		g[i].push_back(p);
		g[p].push_back(i);
	}

	dfs(1, 0);

	while (q--)
	{
		int x, k;
		cin >> x >> k;
		cout << ancestor(x, k) << endl;
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
