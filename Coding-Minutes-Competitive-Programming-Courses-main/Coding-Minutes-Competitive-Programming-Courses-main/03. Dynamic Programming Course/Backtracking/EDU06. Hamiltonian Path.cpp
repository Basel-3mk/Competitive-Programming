// Given an undirected graph with n vertices and m edges,
// your task is to find and print every possible Hamiltonian path in the graph.
// A Hamiltonian path is a simple path that visits every vertex exactly once.
// If there are multiple Hamiltonian paths, each should be printed on a separate line in any order.

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

int cnt, n, m;
vector<vector<int>> g;
vector<int> par;
vector<bool> v;

void ham(int node)
{
    cnt++;
    v[node] = true;

    if (cnt == n)
    {
        vector<int> temp(n);
        int current = node;
        for (int i = n - 1; i >= 0; --i, current = par[current])
            temp[i] = current;

        for (auto x : temp)
            cout << x << ' ';
        cout << endl;
    }

    else
        for (auto c : g[node])
            if (!v[c])
            {
                par[c] = node;
                ham(c);
                par[c] = -1;
            }

    v[node] = false;
    cnt--;
}

void Solve()
{
    cin >> n >> m;

    cnt = 0;
    g.assign(n + 1, {});
    par.assign(n + 1, -1);
    v.assign(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i)
        ham(i);
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
