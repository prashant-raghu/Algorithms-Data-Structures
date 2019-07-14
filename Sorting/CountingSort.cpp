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

void CountingSort(vi &v){ 
	int range = *max_element(begin(v), end(v));
    vector<int> cnt(range + 1, 0);
    for (int i = 0; i < (int)v.size(); ++i) {
        ++cnt[v[i]];
    }
    for (int i = 0, j = -1; i <= range; ++i) {
        for (int k = 0; k < cnt[i]; ++k) {
            v[++j] = i;
        }
    }
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    int n,k;
    cin>>n;
    vi v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    CountingSort(v);
    vi s = v;
    sort(s.begin(),s.end());
    test(s,v);
}
