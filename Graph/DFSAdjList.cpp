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
