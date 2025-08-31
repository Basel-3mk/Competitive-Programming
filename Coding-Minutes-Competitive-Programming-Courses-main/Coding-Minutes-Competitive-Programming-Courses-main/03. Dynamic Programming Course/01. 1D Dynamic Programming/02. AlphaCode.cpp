// https://www.spoj.com/problems/ACODE/

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
    string s;
    while (cin >> s)
    {
        if (s == "0")
            break;

        int n = s.size();
        vector<int> dp(n);
        dp[0] = 1;

        if (n > 1)
        {
            if (s[1] != '0')
                dp[1]++;
            
            int sum = (s[0] - '0') * 10 + s[1] - '0';
            if (sum >= 10 and sum <= 26)
                dp[1]++;
        }

        for (int i = 2; i < n; ++i)
        {
            if (s[i] != '0')
                dp[i] = dp[i - 1];
            
            int sum = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (sum >= 10 and sum <= 26)
                dp[i] += dp[i - 2];
        }

        cout << dp[n - 1] << endl;
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
