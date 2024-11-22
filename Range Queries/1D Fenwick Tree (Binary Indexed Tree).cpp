// Given n elements, and q queries, there's two types of operations:
// 1. Update k-th index to u.
// 2. Output the sum from a to b.
// a, b, k are 1-base.

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

vector<int> a;

struct fenwick
{
	int n;
	vector<ll> ft;

	fenwick(int n)
	{
		this->n = n + 1;
		ft.resize(n + 1);
	}

	void build()
	{
		for (int i = 1; i <= n; ++i)
		{
			int temp = i;
			while (temp <= n)
			{
				ft[temp] += a[i - 1];
				temp += temp & -temp;
			}
		}
	}

	void set(int index, int val)
	{
		int delta = val - a[index - 1];
		a[index - 1] = val;

		while (index <= n)
		{
			ft[index] += delta;
			index += index & -index; // Add last set(1) bit.
		}
	}

	ll get(int index)
	{
		ll ans = 0;
		while (index)
		{
			ans += ft[index];
			index -= index & -index; // Remove last set(1) bit.
		}

		return ans;
	}
};

void Solve()
{
	int n, q;
	cin >> n >> q;

	a.assign(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	fenwick tree(n);
	tree.build();

	while (q--)
	{
		int type;
		cin >> type;

		if (type == 1)
		{
			int k, u;
			cin >> k >> u;
			tree.set(k, u);
		}

		else
		{
			int x, y;
			cin >> x >> y;
			cout << tree.get(y) - tree.get(x - 1) << endl;
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
