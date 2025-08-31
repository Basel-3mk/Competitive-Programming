// You are given an integer n representing the size of a set. Each subset of this set has a value of 1 assigned to every element.
// Your task is to calculate the sum of the sums of all subsets of each subset of the given set.
// Example:
// If n = 2, the set can be represented as {0, 1}. The subsets of this set are:
// 00 (Empty set) → Sum = 0
// 01 → Subsets: {00, 01} → Sum = 2
// 10 → Subsets: {00, 10} → Sum = 2
// 11 → Subsets: {00, 01, 10, 11} → Sum = 4
// Objective:
// For each subset, calculate the sum of all subsets it contains, and return the total sum of all these values.


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
    ll bits;
    cin >> bits;

    vector<ll> dp(1 << bits, 1);

    int n = dp.size();
    for (int i = 0; i < bits; ++i)
        for (int j = 0; j < n; ++j)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];

    cout << dp[n - 1] << endl;
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
