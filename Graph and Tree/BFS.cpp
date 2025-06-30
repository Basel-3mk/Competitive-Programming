// You are given an undirected, unweighted, and connected graph consisting of n nodes and m edges. The nodes are numbered from 1 to n.
// Your task is to compute the shortest distance (in number of edges) from node 1 to every other node in the graph.

// The Messenger of Allah (Peace and blessings be upon him) said: "Whoever is humble for the sake of Allah, Allah will raise him".

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define ll long long

template<typename data_type>
using ordered_set = tree<data_type, null_type, less<data_type>, rb_tree_tag, tree_order_statistics_node_update>;

int dx[16] = { +0, +0, -1, +1, -1, -1, +1, +1, -1, -2, -1, -2, +1, +2, +1, +2 }; 
int dy[16] = { +1, -1, +0, +0, +1, -1, +1, -1, +2, +1, -2, -1, +2, +1, -2, -1 };

void Solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adjList(n + 1);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	vector<int> ans(n + 1, -1);
	ans[1] = 0;

	queue<int> bfsQueue;
	bfsQueue.push(1);

	while(bfsQueue.size()) {
		int curNode = bfsQueue.front();
		bfsQueue.pop();

		for(auto neighbour : adjList[curNode]) {
			if(ans[neighbour] == -1) {
				ans[neighbour] = ans[curNode] + 1;
				bfsQueue.push(neighbour);
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}

	cout << endl;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Solve();

	return 0;
}

