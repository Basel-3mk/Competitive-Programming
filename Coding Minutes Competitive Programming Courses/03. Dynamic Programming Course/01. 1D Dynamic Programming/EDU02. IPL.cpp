// https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004

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
    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (n == 1)
        cout << a[0] << endl;

    else if (n == 2)
        cout << max(a[0], a[1]) << endl;

    else
    {
        vector<int> dp(n);

        for (int i = 0; i < 3; ++i)
            dp[i] = a[i];

        for (int i = 3; i < n; ++i)
            dp[i] = min({ dp[i - 1], dp[i - 2], dp[i - 3] }) + a[i];

        cout << sum - min({ dp[n - 1], dp[n - 2], dp[n - 3] }) << endl;
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
