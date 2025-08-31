// You are given a set of n positive integers and a target sum S.
// Determine whether there exists a subset of the given integers whose sum is exactly equal to S.
// You can reuse the number as much as you want.

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

const int N = 2001, Sum = 20001;
bool dp[Sum];
int arr[N];

void Solve()
{
    int n, sum;
    cin >> n >> sum;

    for (int i = 0; i <= n; ++i)
        cin >> arr[i];

    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= sum; ++j)
            if (j - arr[i] >= 0)
                dp[j] |= dp[j - arr[i]];

    cout << (dp[sum] ? "YES" : "NO") << endl;
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
