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
vi path,height,fir;

void heightcalc(int u,int h){
	height[u] = h;
	vis[u] = true;
	//cout<<u<<" ";
	if(sz(graph[u]) != 0)
	for(auto x:graph[u]){
		if(vis[x] == false)
		heightcalc(x,h+1);
	}
}
void euler(){
	stack<int> s;
	s.push(1); // push source(lca root)
	int it=0;
	while(!s.empty()){
		int v = s.top();
		if(sz(graph[v]) == 0){
			if(fir[v] == -1)fir[v] = it;
			path.push_back(v);
			s.pop();
			it++;
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
	fir.assign(v+1,-1);
 	height.assign(v+1,0);
	for(int i=0;i<e;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back(b);
		graph[b].push_back(a);  //comment if directed graph
	}
	heightcalc(1,1);
	euler();
	int q1,q2;
	cin>>q1>>q2;
	if(fir[q1]>fir[q2])swap(q1,q2);
	int ans,mh = INT_MAX;
	for(int i=fir[q1];i<=fir[q2];i++){
		if(mh > height[path[i]]){
			mh = height[path[i]];
			ans = path[i];
		}
	}
	cout<<ans<<endl;
// 	cout<<endl;
// 	for(int i=0;i<sz(path);i++)
// 	cout<<path[i]<<" ";
// 	cout<<endl;
// //	for(auto x:first)cout<<x<<" ";
// 	for(int i=0;i<sz(path);i++)
// 	cout<<height[path[i]]<<" ";
// 	cout<<endl;
// 	for(int i=0;i<sz(path);i++)
// 	cout<<fir[path[i]]<<" ";
// 	cout<<endl;
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