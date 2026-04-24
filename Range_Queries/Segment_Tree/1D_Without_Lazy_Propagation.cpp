// Given n elements, and q queries, there's two types of operations:
// 1. Update k-th index to val.
// 2. Output the sum from a to b.
// a, b, k are 1-base.

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

class Node {
 public:
  ll curVal;

  Node(int newVal) {
    curVal = newVal;
  }
};

class Segment_Tree {
 private:
  int _n;
  vector<Node> segmentTree;

  void Build(int curL, int curR, int curNode, const vector<int> &a) {
    if (curL == curR) {
      segmentTree[curNode].curVal = a[curL];
      return;
    }

    int curM = (curL + curR) / 2;
    Build(curL, curM, 2 * curNode + 1, a);
    Build(curM + 1, curR, 2 * curNode + 2, a);

    segmentTree[curNode].curVal = segmentTree[curNode * 2 + 1].curVal + segmentTree[curNode * 2 + 2].curVal;
  }

  ll Query(int curL, int curR, int curNode, int requiredL, int requiredR) {
    if (curL > requiredR or curR < requiredL) {
      return 0;
    }

    if (curL >= requiredL and curR <= requiredR) {
      return segmentTree[curNode].curVal;
    }

    int curM = (curL + curR) / 2;
    ll Q1 = Query(curL, curM, 2 * curNode + 1, requiredL, requiredR);
    ll Q2 = Query(curM + 1, curR, 2 * curNode + 2, requiredL, requiredR);
    return Q1 + Q2;
  }

  void Update(int curL, int curR, int curNode, int requiredLeaf, int newVal) {
    if (curL == requiredLeaf and curR == requiredLeaf) {
      segmentTree[curNode].curVal = newVal;
      return;
    }

    int curM = (curL + curR) / 2;
    if (requiredLeaf <= curM) {
      Update(curL, curM, 2 * curNode + 1, requiredLeaf, newVal);
    }

    else {
      Update(curM + 1, curR, 2 * curNode + 2, requiredLeaf, newVal);
    }

    segmentTree[curNode].curVal = segmentTree[curNode * 2 + 1].curVal + segmentTree[curNode * 2 + 2].curVal;
  }

 public:
  Segment_Tree(int n, const vector<int> &a) {
    _n = n;
    segmentTree.resize(n * 4, Node(0));
    Build(0, _n - 1, 0, a);
  }

  ll Query(int requiredL, int requiredR) {
    return Query(0, _n - 1, 0, requiredL, requiredR);
  }

  void Update(int requiredLeaf, int newVal) {
    Update(0, _n - 1, 0, requiredLeaf, newVal);
  }
};

void Solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  Segment_Tree segmentTree(n, a);
  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int k, val;
      cin >> k >> val;
      segmentTree.Update(k - 1, val);
    }

    else {
      int x, y;
      cin >> x >> y;
      cout << segmentTree.Query(x - 1, y - 1) << endl;
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
