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
vector<int>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source
void bfs(ll cur)
{
	queue<int> q;
	vis[cur] = 1;
	dist[cur] = 0;
	q.push(cur);
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(auto x:graph[u]){
			if(vis[x.first] == 0){
				vis[x.first] = 1;
				dist[x.first] = dist[u] + x.second;
				q.push(x.first);
			}
		}
		vis[u] = 2;
	}
}
//vis 0: white, 1: gray, 2: black
//BFS yields shortest distance from one node to another in terms of lesser vertices travelled through to reach sink

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
	bfs(0);
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