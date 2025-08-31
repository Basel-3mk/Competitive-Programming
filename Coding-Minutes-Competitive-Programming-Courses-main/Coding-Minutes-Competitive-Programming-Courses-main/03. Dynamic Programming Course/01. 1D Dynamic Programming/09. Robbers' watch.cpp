// https://codeforces.com/contest/685/problem/A

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

const int N = 7;
int len1, len2;
int hrs[N], mins[N];

int power(int p)
{
    int ans = 1, a = 7;

    while (p)
    {
        if (p & 1)
            ans *= a;

        a *= a;
        p >>= 1;
    }

    return ans;
}

void tohrs(int num)
{
    for (int i = N - 1; i >= 0; --i)
    {
        int tmp = power(i);

        hrs[i] = num / tmp;
        num -= tmp * hrs[i];
    }
}

void tomins(int num)
{
    for (int i = N - 1; i >= 0; --i)
    {
        int tmp = power(i);

        mins[i] = num / tmp;
        num -= tmp * mins[i];
    }
}

bool comp(int a, int b)
{
    memset(hrs, 0, sizeof(hrs));
    memset(mins, 0, sizeof(mins));

    tohrs(a);
    tomins(b);

    set<int> check;
    for (int i = 0; i < len1; ++i)
    {
        if (check.count(hrs[i]))
            return 0;

        check.insert(hrs[i]);
    }

    for (int i = 0; i < len2; ++i)
    {
        if (check.count(mins[i]))
            return 0;

        check.insert(mins[i]);
    }

    return 1;
}

void Solve()
{
    int n, m;
    cin >> n >> m;

    len1 = 1, len2 = 1;

    int limit = power(7);
    for (int i = 7; i <= limit; i *= 7)
    {
        if (n > i)
            len1++;
        if (m > i)
            len2++;
    }

    if (len1 + len2 > 7)
        cout << 0 << endl;
    else
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += comp(i, j);

        cout << ans << endl;
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
