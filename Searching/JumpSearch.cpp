#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void test(vi sorted, vi totest){
    if(sorted != totest)
    for(auto x:totest)
    cout<<x<<" ";
    cout<<endl;
}
int JumpSearch(vi v,ll k){
    int n = sz(v);
    int step = 0,inc = sqrt(n);
    while(v[step] < k){
        step += inc;
        if(step >= n)break;
        }
    int pre = max(step - inc,0);
    while(v[pre] <= k){
        if(v[pre] == k)return pre;
        pre++;
        if(pre == n)return -1;
        }
    return -1;
}
int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int n,k;
    cin>>n>>k;
    vi v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<JumpSearch(v,k)<<endl;
}
