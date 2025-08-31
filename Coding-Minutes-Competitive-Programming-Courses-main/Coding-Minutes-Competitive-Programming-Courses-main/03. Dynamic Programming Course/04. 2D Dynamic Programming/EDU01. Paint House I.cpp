// https://leetcode.com/problems/paint-house/description/

// You are given n houses in a row that need to be painted,
// and there are 3 different colors available.
// The cost of painting the j-th house with the i-th color is provided as an integer.
// However, to ensure aesthetic appeal, no two adjacent houses can be painted with the same color.
// Your task is to determine the minimum total cost to paint all n houses,
// while satisfying the rule that adjacent houses must have different colors.

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

const int N = 2001, K = 3;
int dp[N][K];

void Solve()
{
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < K; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> dp[j][i];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min({ dp[n][0], dp[n][1], dp[n][2] }) << endl;
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
