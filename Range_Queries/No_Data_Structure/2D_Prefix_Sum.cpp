// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define ll long long

template <typename data_type>
using ordered_set = tree<data_type, null_type, less<data_type>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[16] = {0, 1, 0, -1, -1, 1, 1, -1, -1, -1, +1, +1, -2, -2, +2, +2};
int dy[16] = {1, 0, -1, 0, 1, 1, -1, -1, -2, +2, -2, +2, -1, +1, -1, +1};

void Solve() {
  int n, q;
  cin >> n >> q;

  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  vector<vector<ll>> preSum(n + 1, vector<ll>(n + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      preSum[i][j] = a[i][j] + preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1];
    }

  for (int i = 0; i < q; ++i) {
    array<int, 2> row, column;
    for (int j = 0; j < 2; ++j) {
      cin >> row[j] >> column[j];
    }

    int ans = preSum[row[1]][column[1]] - preSum[row[1]][column[0] - 1] - preSum[row[0] - 1][column[1]] + preSum[row[0] - 1][column[0] - 1];
    cout << ans << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }

  cerr << "Basel Al-Jabari." << endl;

  return 0;
}