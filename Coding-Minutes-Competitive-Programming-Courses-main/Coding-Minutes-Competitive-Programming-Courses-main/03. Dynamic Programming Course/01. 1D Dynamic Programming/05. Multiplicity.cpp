// https://codeforces.com/problemset/problem/1061/C

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

const int MOD = 1e9 + 7;

int add(int a, int b)
{
    return ((a % MOD) + (b % MOD)) % MOD;
}

void Solve()
{
    vector<vector<int>> divisors(1e6 + 1);
    for (int i = 1; i <= 1e5; ++i)
        for (int j = i; j <= 1e6; j += i)
            divisors[j].push_back(i);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    map<int, int> m;
    m[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int number = a[i];
        auto &div = divisors[number];
        int idx = upper_bound(div.begin(), div.end(), i) - div.begin();

        idx--;
        if (idx != -1)
            while (idx >= 0)
            {
                if (m.find(div[idx] - 1) != m.end())
                    m[div[idx]] = add(m[div[idx]], m[div[idx] - 1]);
                idx--;
            }
    }

    int sum = 0;
    m.erase(0);
    for (auto [f, s] : m)
        sum = add(sum, s);
    cout << sum << endl;
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
