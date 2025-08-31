// https://leetcode.com/problems/sudoku-solver/description/

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

int n;
vector<vector<char>> board;

bool check(int x, int y, char val)
{
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k];
        int yy = y + dy[k];

        while (xx >= 0 and xx < n and yy >= 0 and yy < n)
        {
            if (board[xx][yy] == val)
                return false;

            xx += dx[k];
            yy += dy[k];
        }
    }

    int startrow = x / 3 * 3, startcolumn = y / 3 * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startrow + i][startcolumn + j] == val)
                return false;

    return true;
}

void sudoku(int row, int column)
{
    if (row == n)
    {
        for (auto d1 : board)
        {
            for (auto d2 : d1)
                cout << d2 << ' ';
            cout << endl;
        }

        return;
    }

    if (column == n)
    {
        sudoku(row + 1, 0);
        return;
    }

    if (board[row][column] != '.')
    {
        sudoku(row, column + 1);
        return;
    }


    for (int i = 1; i <= 9; ++i)
    {
        char c = i + 48;
        if (check(row, column, c))
        {
            board[row][column] = c;
            sudoku(row, column + 1);
            board[row][column] = '.';
        }
    }
}

void Solve()
{
    cin >> n;
    n *= 3;

    board.assign(n, vector<char> (n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    sudoku(0, 0);
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
