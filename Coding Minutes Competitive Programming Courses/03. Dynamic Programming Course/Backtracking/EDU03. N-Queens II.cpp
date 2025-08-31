// https://leetcode.com/problems/n-queens-ii/

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

int n, ans;
vector<vector<char>> board;

bool check(int x, int y)
{
    for (int k = 0; k < 8; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];

        while (xx >= 0 and xx < n and yy >= 0 and yy < n)
        {
            if (board[xx][yy] == 'Q')
                return false;

            xx += dx[k];
            yy += dy[k];
        }
    }

    return true;
}

void queens(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }

    for (int column = 0; column < n; ++column)
        if (check(row, column))
        {
            board[row][column] = 'Q';
            queens(row + 1);
            board[row][column] = '.';
        }
}

void Solve()
{
    ans = 0;
    cin >> n;
    board.assign(n, vector<char> (n, '.'));

    queens(0);
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
