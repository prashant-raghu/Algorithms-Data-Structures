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
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
void make_set(int v) {
    parent[v] = v;
	siz[v] = 1;
}
int find_set(int v) {
  if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int n,m;
    vector<Edge> edges;	
    cin>>n>>m;
	int cost = 0;
    vector<Edge> result;
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
        edges.push_back(temp);
        swap(temp.u,temp.v);
        edges.push_back(temp);
    }
    for (int i = 1; i <= n; i++)
        make_set(i);
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    ll sum = 0;
   // for(auto x:result)cout<<(x.u)<<" "<<(x.v)<<" "<<x.weight<<endl;
     for(auto x:result)sum += x.weight;
     cout<<sum<<endl;
}
