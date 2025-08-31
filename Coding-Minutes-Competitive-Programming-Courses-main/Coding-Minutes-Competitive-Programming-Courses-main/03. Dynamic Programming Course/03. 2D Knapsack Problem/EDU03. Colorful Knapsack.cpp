// Given n items, each with a weight and a color (1 to m). 
// Select one item from each color such that the total weight is maximized without exceeding x. 
// Output the maximum weight achievable or -1 if it's impossible.

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

const int N = 10001;
ll dp[N];

void Solve()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> c(m + 1);
    for (int i = 0; i < n; ++i)
    {
        int weight, color;
        cin >> weight >> color;

        c[color].push_back(weight);
    }

    memset(dp, false, sizeof(dp));
    for (int i = 0; i < c[1].size(); ++i)
        dp[c[1][i]] = true;

    for (int i = 2; i <= m; ++i)
    {
        vector<int> cnts;
        for (int j = 0; j <= x; ++j)
        {
            if (dp[j])
                cnts.push_back(j);
            dp[j] = false;
        }

        for (int p1 = 0; p1 < cnts.size(); ++p1)
            for (int p2 = 0; p2 < c[i].size(); ++p2)
                if (cnts[p1] + c[i][p2] <= x)
                    dp[cnts[p1] + c[i][p2]] = true;
    }

    for (int i = x; i >= 0; --i)
        if (i == 0)
            cout << -1 << endl;
        else if (dp[i])
        {
            cout << i << endl;
            break;
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








