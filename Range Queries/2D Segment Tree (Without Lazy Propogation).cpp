// You are given an n * n grid representing the map of a forest.
// Each square is either empty '.' or contains a tree '*'. 
// The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
// Your task is to process q queries of the form: how many trees are inside a given rectangle in the forest?

// قال رسول الله صلى الله عليه وسلم: "مَن تواضَعَ للهِ رَفَعَهُ".

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

struct Two_D_Segment
{
	int n, m;
	vector<vector<int>> st;

	Two_D_Segment(int n, int m)
	{
		this->n = n;
		this->m = m;
		st.resize(4 * n, {});
		for (int i = 0; i < 4 * n; ++i)
			st[i].resize(4 * m, 0);
	}

	void build2(int s, int e, int node, const vector<vector<int>> &a, int d1, int index1)
	{
		if (s == e)
		{
			st[d1][node] = a[index1][s];
			return;
		}

		int mid = (s + e) >> 1;
		build2(s, mid, 2 * node + 1, a, d1, index1);
		build2(mid + 1, e, 2 * node + 2, a, d1, index1);

		st[d1][node] = st[d1][2 * node + 1] + st[d1][2 * node + 2];
	}

	void build1(int s, int e, int node, const vector<vector<int>> &a)
	{
		if (s == e)
		{
			build2(0, m - 1, 0, a, node, s);
			return;
		}

		int mid = (s + e) >> 1;
		build1(s, mid, 2 * node + 1, a);
		build1(mid + 1, e, 2 * node + 2, a);

		for (int i = 0; i < 4 * m; ++i)
			st[node][i] = st[2 * node + 1][i] + st[2 * node + 2][i];
	}

	void build1(const vector<vector<int>> &a)
	{
		build1(0, n - 1, 0, a);
	}

	int query2(int s, int e, int node, int rs, int re, int d1)
	{
		if (s > re || e < rs)
			return 0;

		if (s >= rs and e <= re)
			return st[d1][node];

		int mid = (s + e) >> 1;
		int Q1 = query2(s, mid, 2 * node + 1, rs, re, d1);
		int Q2 = query2(mid + 1, e, 2 * node + 2, rs, re, d1);

		return Q1 + Q2;
	}

	int query1(int s, int e, int node, int rs1, int re1, int rs2, int re2)
	{
		if (s > re1 || e < rs1)
			return 0;

		if (s >= rs1 and e <= re1)
			return query2(0, m - 1, 0, rs2, re2, node);

		int mid = (s + e) >> 1;
		int Q1 = query1(s, mid, 2 * node + 1, rs1, re1, rs2, re2);
		int Q2 = query1(mid + 1, e, 2 * node + 2, rs1, re1, rs2, re2);

		return Q1 + Q2;
	}

	int query1(int x1, int y1, int x2, int y2)
	{
		return query1(0, n - 1, 0, x1, x2, y1, y2);
	}

	void update2(int s, int e, int node, int leaf2, int d1, int val)
	{
		if (s == e)
		{
			st[d1][node] = val;
			return;
		}

		int mid = (s + e) >> 1;
		if (leaf2 <= mid)
			update2(s, mid, 2 * node + 1, leaf2, d1, val);
		else
			update2(mid + 1, e, 2 * node + 2, leaf2, d1, val);

		st[d1][node] = st[d1][2 * node + 1] + st[d1][2 * node + 2];
	}

	void update1(int s, int e, int node, int leaf1, int leaf2, int val)
	{
		if (s == e)
		{
			update2(0, m - 1, 0, leaf2, leaf1, val);
			return;
		}

		int mid = (s + e) >> 1;
		if (leaf1 <= mid)
			update1(s, mid, 2 * node + 1, leaf1, leaf2, val);
		else
			update1(mid + 1, e, 2 * node + 2, leaf1, leaf2, val);

		for (int i = 0; i < 4 * m; ++i)
			st[node][i] = st[2 * node + 1][i] + st[2 * node + 2][i];
	}

	void update1(int x, int y, int val)
	{
		update1(0, n - 1, node, x, y, val);
	}
};

void Solve()
{
	int n, q;
	cin >> n >> q;

	Two_D_Segment tree(n, n);
	vector<vector<int>> a(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			char x;
			cin >> x;
			a[i][j] = (x == '*' ? 1 : 0);
		}

	tree.build1(a);
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << tree.query1(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endl;
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
