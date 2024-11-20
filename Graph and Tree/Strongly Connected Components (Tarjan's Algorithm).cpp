// قال رسول الله صلى الله عليه وسلم: "مَن تواضَعَ للهِ رَفَعَهُ".

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

vector<vector<int>> g, scc;
vector<bool> v;
vector<int> lt, dt, sccn;
stack<int> st;
int t, cnt;

void dfs(int node, int par)
{
        v[node] = true;
        lt[node] = dt[node] = t++;
        st.push(node);
        for(auto c : g[node])
        {
            if(!v[c])
            {
                dfs(c);
                lt[node] = min(lt[node], lt[c]);
            }
            
            else if(c != par)
                lt[node] = min(lt[node], dt[c]);
        }
    
        if(lt[node] == dt[node])
        {
            scc.push_back({});
            int cur;
            do
            {
                cur = st.top();
                st.pop();
                
                sccn[cur] = cnt;
                scc[cnt].push_back(cur);
            } while(cur != node);
            
            cnt++;
        }
}

void Solve()
{
        int n, m;
        cin >> n >> m;

        // 1-base index.
        g.assign(n + 1, {});
        v.assign(n + 1, false);
        dt.assign(n + 1, 0); // Distance Time.
        lt.assign(n + 1, 0); // Lowest Time.
        scc.clear(); // Strongly Connected Components.
        sccn.assign(n + 1, -1); // Strongly Connected Components Number.
        t = 0;
        cnt = 0;

        for (int i = 0; i < m; ++i)
        {
                int x, y;
                cin >> x >> y;
                g[x].push_back(y);
        }
    
        for(int i = 1; i <= n; ++i)
            if(!v[i])
                dfs(i, 0);
    
        for(auto d1 : scc)
        {
            for(auto d2 : d1)
                cout << d2 << ' ';
            cout << endl;
        }

        for(int i = 1; i <= n; ++i)
                cout << i << ' ' << sccn[i] << endl;
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
