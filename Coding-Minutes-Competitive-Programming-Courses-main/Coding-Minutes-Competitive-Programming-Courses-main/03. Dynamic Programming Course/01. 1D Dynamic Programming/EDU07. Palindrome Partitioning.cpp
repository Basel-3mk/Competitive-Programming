// https://leetcode.com/problems/palindrome-partitioning/

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

bool check(string &s)
{
    int l = 0, r = s.size() - 1;
    while(l <= r)
        if(s[l++] != s[r--])
            return false;

    return true;
}

void Solve()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<vector<string>>> dp(n + 1);
    dp[n] = {{}};

    for (int i = n - 1; i >= 0; --i)
        for (int j = n - 1, pointer = 0; j >= i; --j)
        {
            int sz = j - i + 1;
            string temp = s.substr(i, sz);
            if (check(temp))
                for (auto &answer : dp[i + sz])
                {
                    dp[i].push_back({{ temp }});
                    for (auto &sub_answer : answer)
                        dp[i][pointer].push_back(sub_answer);
                    pointer++;
                }
        }

    for (auto &d1 : dp[0])
    {
        for (auto &d2 : d1)
            cout << d2 << ' ';
        cout << endl;
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
