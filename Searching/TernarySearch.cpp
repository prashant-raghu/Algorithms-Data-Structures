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
int TernarySearch(vi v,ll k){
    int l = 0,r = sz(v) - 1;
    while(l<=r){
        ll m1 = l + (r-l)/3;
        ll m2 = l - (r-l)/3;
        //m--; Enable lower Bound
        //m++; Enable upper Bound
        if(v[m1] == k)return m1;
        else if(v[m2] == k)return m2;
        else if(v[m1] > k)r = m1;
        else if(v[m2] > k)r = m2;
        else if(v[m2] < k)l = m2;
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
    cout<<TernarySearch(v,k);
}
