// Given a tree with n nodes, q queries, there's two types of queries:
// 1. Update the value of node s to value x.
// 2. Output the sum of the subtree of node s.

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
vector<int> tin, tout, a;
int timer;

struct segment
{
	int n;
	vector<ll> st;

	segment(int n)
	{
		this->n = n;
		st.resize(n * 4, 0);
	}

	void build(int s, int e, int node, const vector<int> &arr)
	{
		if (s == e)
		{
			st[node] = arr[s];
			return;
		}

		int mid = (s + e) >> 1;
		build(s, mid, 2 * node + 1, arr);
		build(mid + 1, e, 2 * node + 2, arr);

		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	void build(const vector<int> &arr)
	{
		build(0, n - 1, 0, arr);
	}

	ll query(int s, int e, int node, int rs, int re)
	{
		if (s > re || e < rs)
			return 0;

		if (s >= rs and e <= re)
			return st[node];

		int mid = (s + e) >> 1;
		ll q1 = query(s, mid, 2 * node + 1, rs, re);
		ll q2 = query(mid + 1, e, 2 * node + 2, rs, re);
		return q1 + q2;
	}

	ll query(int rs, int re)
	{
		return query(0, n - 1, 0, rs, re);
	}

	void update(int s, int e, int node, int leaf, int val)
	{
		if (s == leaf and e == leaf)
		{
			st[node] = val;
			return;
		}

		int mid = (s + e) >> 1;
		if (leaf <= mid)
			update(s, mid, 2 * node + 1, leaf, val);
		else
			update(mid + 1, e, 2 * node + 2, leaf, val);

		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	void update(int leaf, int val)
	{
		update(0, n - 1, 0, leaf, val);
	}
};

void dfs(int node, int par)
{
	tin[node] = ++timer;

	for (auto c : g[node])
		if (c != par)
			dfs(c, node);

	tout[node] = timer;
}

void Solve()
{
	int n, q;
	cin >> n >> q;

	g.assign(n + 1, {});
	tin.assign(n + 1, 0);
	tout.assign(n + 1, 0);
	a.assign(n + 1, 0);
	timer = -1;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, 0);
	vector<int> tinarr(n); // Sorted array of a, depending on tin.
	for (int i = 1; i <= n; ++i)
		tinarr[tin[i]] = a[i];

	segment tree(n);
	tree.build(tinarr);

	while (q--)
	{
		int type;
		cin >> type;

		if (type == 1)
		{
			int s, x;
			cin >> s >> x;
			tree.update(tin[s], x);
		}

		else
		{
			int s;
			cin >> s;
			cout << tree.query(tin[s], tout[s]) << endl;
		}
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

