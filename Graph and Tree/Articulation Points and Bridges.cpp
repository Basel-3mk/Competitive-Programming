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
vector<pair<int, int>> b;
vector<bool> v;
vector<int> lt, dt;
set<int> ap;
int t;

void dfs(int node, int par)
{
	v[node] = true;
	lt[node] = dt[node] = t++;

	int childs = 0;
	for (auto c : g[node])
		if (!v[c])
		{
			childs++;
			dfs(c, node);

			lt[node] = min(lt[node], lt[c]);
			if (lt[c] >= dt[node] and par != -1)
				ap.insert(node);

			if (lt[c] > dt[node])
				b.push_back(make_pair(c, node));
		}

		else if (c != par)
			lt[node] = min(lt[node], dt[c]);

	if (par == -1 and childs > 1)
		ap.insert(node);
}

void Solve()
{
	int n, m;
	cin >> n >> m;

	// 1-base index.
	g.assign(n + 1, {});
	v.assign(n + 1, false);
	dt.assign(n + 1, 0); // Distance Time.
	lt.assign(n + 1, 0); // Lowest Time.
	ap.clear(); // Articulation Points.
	b.clear(); // Bridges.
	t = 0;

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, -1);
	for (auto x : ap)
		cout << x << ' ';
	cout << endl;

	for (auto [f, s] : b)
		cout << f << ' ' << s << endl;
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
