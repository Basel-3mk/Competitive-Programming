// https://codeforces.com/contest/1037/problem/D

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
vector<bool> v;
vector<int> bfs_test, lvl;

void Solve()
{
	int n;
	cin >> n;

	g.assign(n + 1, {});
	v.assign(n + 1, false);
	bfs_test.assign(n + 1, 0);
	lvl.assign(n + 1, 0);

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	for (int i = 0; i < n; ++i)
		cin >> bfs_test[i];

	queue<int> q;
	q.push(1);

	bool ans = true;
	if (bfs_test[0] != 1)
		ans = false;

	set<int> check;
	int current = 1;

	while (q.size())
	{
		int node = q.front();
		v[node] = true;
		q.pop();

		int cnt = 0;
		for (auto c : g[node])
			if (!v[c])
			{
				cnt++;
				check.insert(c);
			}

		while (cnt--)
		{
			if (check.find(bfs_test[current]) == check.end())
				ans = false;
			else
				q.push(bfs_test[current]);

			current++;
		}

		check.clear();
	}

	cout << (ans ? "Yes" : "No") << endl;
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
