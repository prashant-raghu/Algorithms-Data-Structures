#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dr[] = {1,0,-1, 0}; // {1,1,0,-1,-1,-1, 0, 1}; // for diagonals
int dc[] = {0,1, 0,-1}; // {0,1,1, 1, 0,-1,-1,-1}; 
int rx,ry;
vector<string> S;
void dfs(int x,int y){
    S[x][y] = 'O';
    for (int d = 0; d < 8; d++){
        if(x+dr[d]>=0 && x+dr[d]<rx && y+dc[d]>=0 && y+dc[d]<ry)
        if(S[x+dr[d]][y+dc[d]] == 'X'){
            dfs(x+dr[d], y+dc[d]);
        }
    }
}

int black(vector<string> &A) {
	int ret = 0;
	S = A;
	rx = A.size();
	if(rx == 0)return 0;
	ry = A[0].size();
	for(int i=0;i<rx;i++){
		for(int j=0;j<ry;j++){
			if(S[i][j] == 'X'){
				ret++;
				dfs(i,j);
			}
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); //Comment while performing interactive IO
	//cin.exceptions(cin.failbit); // Logical error on i/o operation
    vector<string> v;
	string s;
	while(cin>>s){
		v.push_back(s);
	}
	cout<<black(v);
	//for(auto x:v)cout<<x<<endl;


}

// Test Case From Interviewbit Black Shapes
// OOOXOOO
// OOXXOXO
// OXOOOXO