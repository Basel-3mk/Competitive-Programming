// https://codeforces.com/contest/221/problem/D

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

struct query
{
    int l, r, block, index;

    bool operator<(query &a) const
    {
        return make_pair(block, r) < make_pair(a.block, a.r);
    }
};

vector<int> arr;
unordered_map<int, int> hashMap;
int temp;

void add(int index)
{
    int num = arr[index];
    if (hashMap.count(num))
        if (hashMap[num] == num)
            temp--;

    hashMap[num]++;

    if (hashMap[num] == num)
        temp++;
}

void remove(int index)
{
    int num = arr[index];
    if (hashMap.count(num))
        if (hashMap[num] == num)
            temp--;

    hashMap[num]--;

    if (hashMap[num] == num)
        temp++;
}

void Solve()
{
    int n, q;
    cin >> n >> q;

    arr.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int blocks = sqrt(n) + 1;
    vector<query> qarr(q);
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        qarr[i].index = i;
        qarr[i].l = l;
        qarr[i].r = r;
        qarr[i].block = l / blocks;
    }

    sort(qarr.begin(), qarr.end());
    int start = qarr[0].l, end = qarr[0].l;
    temp = 0;
    vector<int> ans(q);
    for (int i = 0; i < q; ++i)
    {
        while (end > qarr[i].r + 1)
            remove(--end);

        while (end <= qarr[i].r)
            add(end++);

        while (start < qarr[i].l)
            remove(start++);

        while (start > qarr[i].l)
            add(--start);

        ans[qarr[i].index] = temp;
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << endl;
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
    // cin >> t;
    while (t--)
        Solve();

    cerr << "Basel Al-Jabari." << endl;

    return 0;
}
