// https://codeforces.com/problemset/problem/1221/D

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

const int N = 300001, K = 3;
ll cost[N][K];
int sz[N];

void Solve()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> sz[i] >> cost[i][1];

        for (int i = 0; i < n; ++i)
        {
            cost[i][0] = 0;
            cost[i][2] = 2 * cost[i][1];
        }

        for (int i = 1; i < n; ++i)
            for (int j = 0; j < K; ++j)
            {
                ll mn = LLONG_MAX;

                for (int k = 0; k < K; ++k)
                    if (sz[i] + j != sz[i - 1] + k)
                        mn = min(mn, cost[i - 1][k]);

                cost[i][j] += mn;
            }

        cout << min({ cost[n - 1][0], cost[n - 1][1], cost[n - 1][2] }) << endl;
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
