#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define NIL -1 
vector<vector<pair<ll,ll> > >graph(200001);
vector<bool>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source

int n; // number of nodes
vector<vector<int>> adj(20000); // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
//unordered_set<pair<int,int>> s;

void IS_BRIDGE(int v1, int v2){
	cout<<v1<<" "<<v2<<endl;
//	s.insert(make_pair(v1,v2));
}
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]){
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int v,e;
	cin>>v>>e;
	n = v;
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);  //comment if directed graph
	}
	find_bridges();
	//for(auto x:s)cout<<x.first<<" "<<x.second<<endl;
	// for(int i=0;i<v;i++)
	// cout<<dist[i]<<" ";
}

// Test Case From CP3 Bridge Search
// 6 6
// 0 1 1
// 1 2 1
// 3 1 1
// 1 4 1
// 4 5 1
// 1 5 1