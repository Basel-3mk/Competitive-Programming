// http://poj.org/problem?id=2663

// Video: https://www.youtube.com/watch?v=yn2jnmlepY8&ab_channel=WilliamFiset

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

const int N = 31;

void Solve()
{
    vector<vector<int>> dp(N, vector<int>(8, 0));
    dp[0][7] = 1;
    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = dp[i - 1][7];

        dp[i][1] = dp[i - 1][6];

        dp[i][2] = dp[i - 1][5];

        dp[i][3] += dp[i - 1][7];
        dp[i][3] += dp[i - 1][4];

        dp[i][4] = dp[i - 1][3];

        dp[i][5] = dp[i - 1][2];

        dp[i][6] += dp[i - 1][7];
        dp[i][6] += dp[i - 1][1];

        dp[i][7] += dp[i - 1][0];
        dp[i][7] += dp[i - 1][6];
        dp[i][7] += dp[i - 1][3];
    }

    int n;
    while (cin >> n and n != -1)
        cout << dp[n][7] << endl;
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
