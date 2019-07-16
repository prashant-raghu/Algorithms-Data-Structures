#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<int> >graph(200001);
vector<bool>vis(200001,0);
vector<ll>dist(200001,0);          // distance of the index from the source
vi path;
//Algorithm
// stack St;
// put start vertex in St;
// until St is empty
//   let V be the value at the top of St;
//   if degree(V) = 0, then
//     add V to the answer;
//     remove V from the top of St;
//   otherwise
//     find any edge coming out of V;
//     remove it from the graph;
//     put the second end of this edge in St;

void euler(){
	stack<int> s;
	s.push(1); // push source(any vertex)
	while(!s.empty()){
		int v = s.top();
		if(sz(graph[v]) == 0){
			path.push_back(v);
			s.pop();
		}
		else {
			s.push(graph[v][sz(graph[v]) - 1]);
			graph[v].pop_back();
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
		graph[b].push_back(a);  //comment if directed graph
	}
	euler();
	for(int i=0;i<sz(path);i++)
	cout<<path[i]<<" ";
}
// Test Case From cp-algorithm lca doc
// 7 6
// 1 2 1
// 1 3 1
// 1 4 1
// 2 5 1
// 2 6 1
// 4 7 1

//expected path: 1 2 5 2 6 2 1 3 1 4 7 4 1