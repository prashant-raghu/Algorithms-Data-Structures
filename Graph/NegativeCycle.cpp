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

void solve()
{
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (edge e : graph) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "No negative cycle found.";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v << ' ';
        cout << endl;
    }
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
       // swap(temp.a,temp.b);
       // graph.push_back(temp);
    }
	solve();
}
// Test Case for -ve cycle detection
// 5 6
// 0 1 -10
// 1 2 1
// 2 3 1
// 3 0 1
// 1 4 1
// 4 0 1