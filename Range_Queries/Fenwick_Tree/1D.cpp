// Given n elements, and q queries, there are two types of operations:
// 1. Update k-th index to u.
// 2. Output the sum from a to b.
// a, b, k are 0-base.

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

class Fenwick_Tree {
 private:
  int _n;
  vector<ll> _fenwickTree;

 public:
  Fenwick_Tree(int n, const vector<int> &a) {
    _n = n;
    _fenwickTree.assign(n + 1, 0);
    Build(a);
  }

  void Build(const vector<int> &a) {
    for (int i = 1; i <= _n; ++i) {
      int index = i;
      while (index <= _n) {
        _fenwickTree[index] += a[i - 1];
        index += index & -index;
      }
    }
  }

  void Update(int index, int newValue, vector<int> &a) {
    int delta = newValue - a[index];
    a[index] = newValue;

    index++;
    while (index <= _n) {
      _fenwickTree[index] += delta;
      index += index & -index;
    }
  }

  ll Get(int index) {
    ll ans = 0;

    index++;
    while (index) {
      ans += _fenwickTree[index];
      index -= index & (index - 1);
    }

    return ans;
  }
};

void Solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Fenwick_Tree fenwickTree(n, a);
  for (int i = 1; i <= q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int k, u;
      cin >> k >> u;

      fenwickTree.Update(k, u, a);
    }

    else if (type == 2) {
      int a, b;
      cin >> a >> b;

      cout << fenwickTree.Get(b) - fenwickTree.Get(a - 1) << endl;
    }
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