#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int N;
vector<bool>vis(200001,0);
vector<int>par(200001,0);
vector<int>dist(200001,0);          // distance of the index from the source

const int INF = 10000000;
vector<vector<pair<int, int>>> graph(200001);
void dijkstra(int s, vector<int> & d, vector<int> & p){
    int n = N;
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
		//for loop that finds min dist node from s discovered till now, once that is done
		
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == INF)
            break;
        u[v] = true;
		//relax all adj edges to this newly discovered node
        for (auto edge : graph[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}
vector<int> restore_path(int s, int t, vector<int> const& p) {
    vector<int> path;

    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());
	for(auto x:path)cout<<x<<" ";
    return path;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int v,e;
	cin>>v>>e;
	N = v;
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));  //comment if directed graph
	}
	vector<int> d,p;
	dijkstra(0,d,p);
	// for(auto x:dist)cout<<x<<" ";
	//cout<<v;
	// for(int i=0;i<v;i++)
	// cout<<d[i]<<" ";
	vector<int> path = restore_path(0,5,p);
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