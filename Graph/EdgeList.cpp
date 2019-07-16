#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi parent(20000),siz(20000);	
struct Edge {
    int u, v, weight;
    //overloaded < operator
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
vector<Edge> graph;

int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int n,m;
    cin>>n>>m;
    parent.resize(n);
    siz.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        Edge temp;
        temp.u = a;
        temp.v = b;
        temp.weight = c;
        graph.push_back(temp);
        swap(temp.u,temp.v);
        graph.push_back(temp);
    }
}
