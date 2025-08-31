// https://www.spoj.com/problems/KNAPSACK/

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

const int N = 2002, S = 2002;
int dp[S];
int sz[N], val[N];

void Solve()
{
    int s, n;
    cin >> s >> n;

    for (int i = 1; i <= n; ++i)
        cin >> sz[i] >> val[i];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        for (int j = s; j >= 0; --j)
            if (sz[i] <= j)
                dp[j] = max(dp[j], dp[j - sz[i]] + val[i]);

    cout << dp[s] << endl;
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
