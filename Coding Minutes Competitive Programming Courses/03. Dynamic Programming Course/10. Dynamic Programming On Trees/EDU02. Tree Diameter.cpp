// https://cses.fi/problemset/task/1131/

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

const int N = 2e5 + 1;

vector<int> g[N];
int dp[N], depth[N];

void dfs(int node, int par)
{
    int max1 = 0, max2 = 0;

    for (auto c : g[node])
        if (c != par)
        {
            dfs(c, node);

            dp[node] = max(dp[node], dp[c]);
            depth[node] = max(depth[node], depth[c] + 1);
            if (depth[c] + 1 > max1)
            {
                max2 = max1;
                max1 = depth[c] + 1;
            }

            else if (depth[c] + 1 > max2)
                max2 = depth[c] + 1;
        }

    dp[node] = max(dp[node], max1 + max2);
}

void Solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
    cout << dp[1] << endl;
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
