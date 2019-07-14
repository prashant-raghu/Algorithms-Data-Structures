#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
bool isEqual(vi &v1, vi &v2){
    return (v1.size() == v2.size() && std::equal(v1.begin(), v1.end(), v2.begin()));
}
void test(vi sorted, vi totest){
    if(isEqual(sorted,totest))
        cout<<"Correct\n";
    else
        for(auto x:totest)
            cout<<x<<" ";
    cout<<endl;
}

void Merge(vi &v, int l,int m,int r){
    int i1 = l,i2 = m+1;
    for(int i=l;i<=r;i++){
        if(v[i1] < v[i2]){
            v[i] = v[i1];
            i1++;
        }
        else {
            v[i] = v[i2];
            i2++;    
        }
    }
}
void MergeSort(vi &v,int l,int r){
    if(l>=r)return;
    int m = (l+r)/2;
    MergeSort(v,l,m);
    MergeSort(v,m+1,r);
    Merge(v,l,m,r);
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
    MergeSort(v,0,sz(v) - 1);
    vi s = v;
    sort(s.begin(),s.end());
    test(s,v);
}
