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
stack<int> topo;
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
		topo.push(u);
		vis[u] = 2;
	}
}
void TopologicalSort(int v){
	for(int i=0;i<v;i++){
		if(vis[i] == 0)
		bfs(i);
	}
	while(!topo.empty()){
		cout<<topo.top()<<" ";
		topo.pop();
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
		//graph[b].push_back(make_pair(a,c));  //comment if directed graph
	}
	TopologicalSort(v);
}