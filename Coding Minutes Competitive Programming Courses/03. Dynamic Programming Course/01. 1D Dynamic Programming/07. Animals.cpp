// This solution used a greedy approach.

// https://codeforces.com/problemset/problem/35/D

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
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] *= n - i;
    }

    sort(a.begin(), a.end());

    int ans = 0, temp = -1;
    while (++temp < n and x >= a[temp])
    {
        ans++;
        x -= a[temp];
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solve();

    cerr << "Basel Al-Jabari." << endl;

    return 0;
}
