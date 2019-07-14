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

void InsertionSort(vi &v){
    int val,n = sz(v);
    for (int i = 1; i < n; i++) 
    {  
        val = v[i];
        int j = i - 1; 
        while (j >= 0 && v[j] > val) 
        {  
            v[j + 1] = v[j];  
            j--; 
        }
        v[j + 1] = val;
    }
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
    InsertionSort(v);
    vi s = v;
    sort(s.begin(),s.end());
    test(s,v);
}
