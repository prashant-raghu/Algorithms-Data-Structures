#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector< ll > >graph(200001);
vector<int>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source
stack<int> topo;
void kahn(vector<vector<ll>> adj, vi &inDegree, vi &result){
    queue<int> Q;
    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }
    for(int i=0; i<inDegree.size(); i++) if(inDegree[i] == 0) Q.push(i);
    while(!Q.empty()){
        int top = Q.front(); Q.pop();
        result.push_back(top);
        for(int i=0; i<adj[top].size(); i++){
            inDegree[adj[top][i]]--;
            if(inDegree[adj[top][i]] == 0) Q.push(adj[top][i]);
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
		graph[a].push_back(b);
		//graph[b].push_back(make_pair(a,c));  //comment if directed graph
	} 
	vi inDegree(v, 0);
    vi result;
    kahn(graph, inDegree, result);
    for(int i=0; i<result.size(); i++) cout << result[i] << ' '; cout << endl;
}