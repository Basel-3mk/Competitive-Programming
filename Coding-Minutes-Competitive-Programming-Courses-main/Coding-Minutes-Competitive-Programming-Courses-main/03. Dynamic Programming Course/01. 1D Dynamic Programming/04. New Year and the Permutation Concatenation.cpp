// This solution used combinatorics (Without DP).

// https://codeforces.com/contest/1091/problem/D

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

const int N = 1e6 + 1;
const int MOD = 998244353;

vector<int> fact;

int sub(int a, int b)
{
    return (1LL * (a % MOD) - (b % MOD) + MOD) % MOD;
}

int mul(int a, int b)
{
    return (1LL * (a % MOD) * (b % MOD)) % MOD;
}

int power(int n, int p)
{
    int ans = 1, a = n;
    while (p)
    {
        if (p & 1)
            ans = mul(ans, a);

        a = mul(a, a);
        p >>= 1;
    }

    return ans;
}

int inv(int a)
{
    return power(a, MOD - 2);
}

void calculate_fact()
{
    for (int i = 1; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);
}

void Solve()
{
    fact.assign(N, 1);
    calculate_fact();

    int n;
    cin >> n;

    int ans = mul(fact[n], n);
    for (int i = 1; i < n; ++i)
        ans = sub(ans, mul(fact[n], inv(fact[i])));

    cout << ans << endl;
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
