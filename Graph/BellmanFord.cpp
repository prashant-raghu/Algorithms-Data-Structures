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
struct edge
{
    int a, b, cost;
};
int n, m, v;
vector<edge> graph;
const int INF = 1000000000;
void BellmanFord()
{
    vector<int> d (n, INF);
    d[v] = 0;
    while(true)
    {
        bool any = false;
        for (int j=0; j<2*m; ++j)
            if (d[graph[j].a] < INF)
                if (d[graph[j].b] > d[graph[j].a] + graph[j].cost)
                {
                    d[graph[j].b] = d[graph[j].a] + graph[j].cost;
                    any = true;
                }
        if (!any) break;
    }
    // display d, for example, on the screen
    for(int i=0;i<n;i++)
    cout<<d[i]<<" ";
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
	cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge temp;
        temp.a = a;
        temp.b = b;
        temp.cost = c;
        graph.push_back(temp);
        // undirected grpah
        swap(temp.a,temp.b);
        graph.push_back(temp);
    }
	BellmanFord();
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