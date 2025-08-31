// Given a 2 × n board and tiles of size 2 × 1,
// count the number of ways to completely tile the board.
// Each tile can be placed either vertically or horizontally.

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <bits/extc++.h>

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

const int N = 31;

int f[N];

void pre_compute()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < N; ++i)
        f[i] = f[i - 1] + f[i - 2];
}

void Solve()
{
    int n;
    cin >> n;
    cout << f[n] << endl;
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

    int t = 1;
    cin >> t;
    pre_compute();
    for (int i = 0; i < t; ++i)
    {
        Solve();
    }

    cerr << "Basel Al-Jabari." << endl;

    return 0;
}
