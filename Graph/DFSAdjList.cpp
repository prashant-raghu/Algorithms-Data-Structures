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
void dfs(ll cur)
{
	vis[cur]=1;
    for(auto i:graph[cur])
	{
        if(!vis[i.first])
		{
            dist[i.first]=dist[cur]+i.second;
        	dfs(i.first);
		}
	}
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));  //comment if directed graph
	}
	dfs(0);
	for(int i=0;i<v;i++)
	cout<<dist[i]<<" ";
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