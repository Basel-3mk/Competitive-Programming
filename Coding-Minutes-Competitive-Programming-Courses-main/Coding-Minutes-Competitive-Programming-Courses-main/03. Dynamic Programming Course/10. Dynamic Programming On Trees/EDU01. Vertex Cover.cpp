// https://www.spoj.com/problems/PT07X/

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int dx[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };

vector<vector<int>> g, dp;
vector<bool> v;

void dfs(int node)
{
    dp[node][1] = 1;
    v[node] = true;

    for (auto c : g[node])
        if (!v[c])
        {
            dfs(c);

            dp[node][0] += dp[c][1];
            dp[node][1] += min(dp[c][0], dp[c][1]);
        }
}

void Solve()
{
    int n;
    cin >> n;
    g.assign(n + 1, {});
    dp.assign(n + 1, vector<int> (2));
    v.assign(n + 1, false);

    for (int i = 0; i < n - 1; ++i)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << endl;
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
