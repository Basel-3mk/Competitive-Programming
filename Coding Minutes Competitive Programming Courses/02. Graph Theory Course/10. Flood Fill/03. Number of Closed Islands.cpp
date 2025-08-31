// https://leetcode.com/problems/number-of-closed-islands/

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

int n, m;
vector<vector<int>> g;
vector<vector<bool>> v;

bool dfs(int x, int y)
{
	bool ans = true;
	v[x][y] = true;

	for (int k = 0; k < 4; ++k)
	{
		int xx = x + dx[k];
		int yy = y + dy[k];

		if (xx < 0 or yy < 0 or xx >= n or yy >= m)
			ans = false;

		else if (!v[xx][yy] and !g[xx][yy])
			ans &= dfs(xx, yy);
	}

	return ans;
}

void Solve()
{
	cin >> n >> m;

	g.assign(n, vector<int>(m));
	v.assign(n, vector<bool>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> g[i][j];

	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (!g[i][j] and !v[i][j])
				ans += dfs(i, j);

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
