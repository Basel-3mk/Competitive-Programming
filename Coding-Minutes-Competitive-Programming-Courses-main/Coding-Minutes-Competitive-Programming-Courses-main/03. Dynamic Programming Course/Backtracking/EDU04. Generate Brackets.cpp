// https://leetcode.com/problems/generate-parentheses/description/

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

string output;
int n, open, close;

void generate(int i)
{
    if (i == n * 2)
    {
        cout << output << endl;
        return;
    }

    if (open < n)
    {
        open++;
        output.push_back('(');
        generate(i + 1);
        output.pop_back();
        open--;
    }

    if (open > close)
    {
        close++;
        output.push_back(')');
        generate(i + 1);
        output.pop_back();
        close--;
    }
}

void Solve()
{
    open = close = 0;
    cin >> n;
    generate(0);
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
