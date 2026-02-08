// https://vjudge.net/problem/USACO-919

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

const int N = 1003;

int arr[N][N];

void Solve()
{
	memset(arr, 0, sizeof(arr));

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x1++;
		y1++;

		arr[y1][x1]++;
		arr[y2 + 1][x2 + 1]++;
		arr[y1][x2 + 1]--;
		arr[y2 + 1][x1]--;
	}

	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];

	int ans = 0;
	for (int i = 1; i < N; ++i)
		for (int j = 1; j < N; ++j)
			if (arr[i][j] == k)
				ans++;

	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; ++i)
	{
		Solve();
	}

	cerr << "Basel Al-Jabari." << endl;

	return 0;
}
