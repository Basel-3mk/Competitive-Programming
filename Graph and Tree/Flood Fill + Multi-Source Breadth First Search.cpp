// https://codeforces.com/problemset/problem/35/C

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define ll long long

template<typename data_type>
using ordered_set = tree<data_type, null_type, less<data_type>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[16] = { +0, +0, -1, +1, -1, -1, +1, +1, -1, -2, -1, -2, +1, +2, +1, +2 }; 
int dy[16] = { +1, -1, +0, +0, +1, -1, +1, -1, +2, +1, -2, -1, +2, +1, -2, -1 };

void Solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<bool>> vis(n + 1, vector<bool> (m + 1));
	queue<pair<int, int>> bfsQueue;

	int k;
	cin >> k;
	for(int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;

		vis[x][y] = true;
		bfsQueue.push(make_pair(x, y));
	}

	while(bfsQueue.size()) {
		int curX = bfsQueue.front().first, curY = bfsQueue.front().second;
		bfsQueue.pop();

		for(int d = 0; d < 4; ++d) {
			int newX = curX + dx[d];
			int newY = curY + dy[d];

			if(newX >= 1 and newY >= 1 and newX <= n and newY <= m and !vis[newX][newY] and k != n * m - 1) {
				vis[newX][newY] = true;
				bfsQueue.push(make_pair(newX, newY));
				k++;
			}
		}
	}

	pair<int, int> ans = make_pair(1, 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(!vis[i][j]) {
				ans = make_pair(i, j);
			}
		}
	}

	cout << ans.first << ' ' << ans.second << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Solve();

	return 0;
}

