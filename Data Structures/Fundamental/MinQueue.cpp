#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void add(int new_elem,stack<pair<int,int>> &s1){
  int minimum = s1.empty() ? new_elem : min(new_elem, s1.top().second);
    s1.push({new_elem, minimum});
}
int remove(stack<pair<int,int>> &s1, stack<pair<int,int>> &s2){
    if (s2.empty()) {
        while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
            }
    }
    int remove_element = s2.top().first;
    s2.pop();
    return remove_element;
}
int find_min(stack<pair<int,int>> s1, stack<pair<int,int>> s2){
    int minimum;
    if (s1.empty() || s2.empty()) 
        minimum = s1.empty() ? s2.top().second : s1.top().second;
    else
        minimum = min(s1.top().second, s2.top().second);
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	cin.exceptions(cin.failbit); // Logical error on i/o operation
    //There are multiple possible ways to implement MinQueue, in this implementation I'll be using 2 min stacks 
    vector<int> duplicate;
    stack<pair<int,int>> MS1,MS2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        duplicate.push_back(temp);
        add(temp,MS1);
    }
    for(int i=0;i<n;i++){
        cout<<find_min(MS1,MS2)<<" ";
        int removed = remove(MS1,MS2);
    }
    // boilerplate for min queue ends here, below is sample tests checker
    cout<<endl;
    for(auto x:duplicate)cout<<x<<" ";
}
