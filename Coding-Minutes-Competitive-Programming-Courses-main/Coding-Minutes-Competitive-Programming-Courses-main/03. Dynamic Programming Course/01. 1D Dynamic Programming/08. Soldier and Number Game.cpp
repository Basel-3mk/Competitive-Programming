// https://codeforces.com/problemset/problem/546/D

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

const int N = 5e6 + 1;
int pr_factor[N], dp[N];

void Solve()
{
    memset(pr_factor, 0, sizeof(pr_factor));
    memset(dp, 0, sizeof(dp));

    for (int i = 2; i < N; ++i)
        if (!pr_factor[i])
            for (int j = i; j < N; j += i)
                pr_factor[j] = i;

    for (int i = 2; i < N; ++i)
        dp[i] = dp[i / pr_factor[i]] + 1;

    for (int i = 2; i < N; ++i)
        dp[i] += dp[i - 1];

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        cout << dp[a] - dp[b] << endl;
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
