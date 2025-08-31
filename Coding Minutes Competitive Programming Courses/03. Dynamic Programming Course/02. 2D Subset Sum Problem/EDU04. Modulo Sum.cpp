// https://codeforces.com/problemset/problem/577/B

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

void Solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    if (n > m)
        cout << "YES" << endl;

    else
    {
        vector<vector<bool>> dp(2, vector<bool> (m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = m - 1; j >= 0; --j)
                if (dp[0][j])
                    dp[1][(arr[i] + j) % m] = true;

            dp[1][arr[i] % m] = true;
            dp[0] = dp[1];
        }

        cout << (dp[0][0] ? "YES" : "NO") << endl;
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
