#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,INF = 10000000;
vector<vector<int>> capacity;
vector<vector<int>> adj(20000);

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int v,e;
	cin>>v>>e;
    n = v;
    vector<int> temp(v+1,0);
    for(int i=0;i<v;i++)
        capacity.push_back(temp);
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		capacity[a][b] = c;
	}
	cout<<maxflow(0,5);
}

// Test Case From cp-algorithm flow ford-fulkerson article
// 6 9
// 0 1 7
// 1 2 5
// 2 5 8
// 0 4 4
// 4 3 2
// 3 5 5
// 3 2 3
// 1 3 3
// 4 1 3