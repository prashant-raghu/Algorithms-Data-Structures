#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void add(int new_elem,stack<pair<int,int>> &st){
    int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
    st.push({new_elem, new_min});
}
int remove(stack<pair<int,int>> &st){
    int removed_element = st.top().first;
    st.pop();
    return removed_element;
}
int top(stack<pair<int,int>> st){
    int minimum = st.top().second;
    return minimum;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    // idea of min stack is to store data in pairs where second element represents the min
    // lement so far
    vector<int> duplicate;
    stack<pair<int,int>> minstack;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        duplicate.push_back(temp);
        add(temp,minstack);
    }
    for(int i=0;i<n;i++){
        cout<<top(minstack)<<" ";
        int removed = remove(minstack);
    }
    // boilerplate for min stack end here, below is sample tests checker
    cout<<endl;
    reverse(duplicate.begin(),duplicate.end());
    for(auto x:duplicate)cout<<x<<" ";
}
