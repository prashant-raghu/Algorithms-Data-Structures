#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int f(int a,int b){
    return min(a,b);
}
void SparseTable(vector<int> & v,int n){

    int MAXN = 1000,K = 25;
    vector<vector<int>> st;
    vector<int> te(MAXN,0);
    //creating MAXN*(K+1) grid of st
    for(int i=0;i<K;i++)st.push_back(te);
    //filling first row of st with vector values as min in ranger R to R is element itself
    for (int i = 0; i < n; i++)
    st[i][0] = v[i];
    // populating whole grid using grid as sub problems are precomputed.
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = f(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    //precomputing log2 array for values from 1 to 
    int log[MAXN+1];
    log[1] = 0;
    for (int i = 2; i <= MAXN; i++)
        log[i] = log[i/2] + 1;
    //Answering range query in O(1) as min is indempotent ie, min(a,a) = a so repetition doesnt affect the result of RMQ
    int L,R;
    cin>>L>>R;
    int j = log[R - L + 1];
    cout<<min(st[L][j], st[R - (1 << j) + 1][j]);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    // idea of min stack is to store data in pairs where second element represents the min
    // element so far
    vector<int> v;
    stack<pair<int,int>> minstack;
    int n;
    cin>>n;
    //populating vector with values
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    SparseTable(v,n);
}
