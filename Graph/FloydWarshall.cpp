#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
vector<bool>vis(200001,0);
vector<int>par(200001,0);
vector<int>dist(200001,0);          // distance of the index from the source
const int INF = 10000000;
vector<vector<int>> graph;
//a cubic algorithm in which for each node we select all possible pairs of node and set
// distance [i][j] as min(already computed distance for [i][j] or distance from i to k plus k to j )

void FloydWarshall(){
    for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][k] < INF && graph[k][j] < INF)
                graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]); 
        }
    }
    }
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int v,e;
	cin>>v>>e;
	n = v;
    vector<int> empty(n,INF);
    for(int i=0;i<v;i++)graph.push_back(empty);
	for(int j=0;j<v;j++){
    graph[j][j] = 0;
    }
    for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
	}
    FloydWarshall();
    for(int i=0;i<v;i++){
	for(int j=0;j<v;j++){
	cout<<graph[i][j]<<" ";
    }
    cout<<endl;}
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