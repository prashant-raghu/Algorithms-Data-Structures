#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<pair<ll,ll> > >graph(200001);
vector<bool>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source

int n;
vector<vector<int>> adj(20000);
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            parent[u] = v;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        if (dfs(u))
            return true;
    }
    color[v] = 2;
    return false;
}
void find_cycle_with_path() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (int v = 0; v < n; v++) {
        if (dfs(v))
            {
				break;
			}
    }
    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        cout << "Cycle found: ";
        for (int x : cycle)
            cout << x << " ";
        cout << endl;
    }
}
bool ret = false;
void find_cycle(int cur) //dfs //run for each node and observe value of ret//
{
	vis[cur] = 1;
    for(auto i:graph[cur])
	{   
        if(vis[i.first] == 1)ret = true;
        if(vis[i.first] == 0)
		{
        	find_cycle(i.first);
		}
	}
    vis[cur] = 2;
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
		//adj[b].push_back(a);  //comment if directed graph
	}
	find_cycle_with_path();
}
// Test Case From COmputerphile Dijkstra Video
// 13 18
// 0 1 7
// 0 2 2
// 0 3 3
// 3 12 2
// 12 10 4
// 12 9 4
// 10 9 6
// 11 9 4
// 11 10 4
// 11 5 5
// 5 7 2
// 7 8 2
// 6 8 3
// 6 4 5
// 1 4 4
// 4 2 4
// 1 2 3
// 8 2 1