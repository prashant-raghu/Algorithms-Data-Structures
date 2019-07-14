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
int LowerBound(vi v,ll k){
    int m,l = 0,r = sz(v);
    while(l<r){
         m = l + (l+r)/2;
         if(v[m] < k)l = m + 1;
         else r = m;
    }
    return m;
}
int UpperBound(vi v,ll k){
    int m,l = 0,r = sz(v);
    while(l<r){
        m = (l + r)/2;
        if (k >= v[m])
            l = m + 1;
        else
            r = m;
    }
    return m;
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
    cout<<LowerBound(v,k)<<endl;
    cout<<UpperBound(v,k)<<endl;
}
