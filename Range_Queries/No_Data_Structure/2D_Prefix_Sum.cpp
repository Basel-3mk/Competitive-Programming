// https://cses.fi/problemset/task/1652/

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <bits/extc++.h>

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

void Solve()
{
	int n, q;
	cin >> n >> q;

	vector<vector<int>> arr(n + 1, vector<int> (n + 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;

			if (c == '*')
				arr[i][j] = 1;
		}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			arr[i][j] += arr[i - 1][j];
			arr[i][j] += arr[i][j - 1];
			arr[i][j] -= arr[i - 1][j - 1];
		}

	for (int i = 0; i < q; ++i)
	{
		int row1, column1, row2, column2;
		cin >> row1 >> column1 >> row2 >> column2;

		int ans = arr[row2][column2] - arr[row2][column1 - 1] - arr[row1 - 1][column2] + arr[row1 - 1][column1 - 1];
		cout << ans << endl;
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

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; ++i)
	{
		Solve();
	}

	cerr << "Basel Al-Jabari." << endl;

	return 0;
}
