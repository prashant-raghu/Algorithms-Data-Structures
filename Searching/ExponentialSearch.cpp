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
int ExponentialSearch(vi v,ll k){
    int l = 0,r = sz(v) - 1,i=1;
    while (i < r && v[i] <= k) 
        i = i*2;
    l = i/2;
    r = min(i, r);
    while(l<=r){
        ll m = l+r;
        m /= 2;
        //m--;// Enable lower Bound
        //m++;// Enable upper Bound
        if(v[m] == k)return m;
        else if(v[m] < k)l = m;
        else if(v[m] > k)r = m;
    }
    return -1;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int n,k;
    cin>>n>>k;
    vi v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<ExponentialSearch(v,k);
}
