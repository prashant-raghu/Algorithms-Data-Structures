// Created on 29-07-2019 16:21:24 by necronomicon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define EPS 1e-9 //10^-9
#define MOD 1000000007 //10^9+7
#define PI 3.1415926535897932384626433832795
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef map<int,int> Mii;
typedef set<int> Si;
typedef multimap<int,int> MMii;
typedef multiset<int> MSi;
typedef unordered_map<int,int> UMii;
typedef unordered_set<int> USi;
typedef unordered_multimap<int,int> UMMii;
typedef unordered_multiset<int> UMSi;
typedef priority_queue<int> PQi;
typedef queue<int> Qi;
typedef deque<int> DQi;


int N, capacity;
Vi weights, price;
VVi DP;

int bruteForce(int k, int s){
    if(k == N) return 0;
    if(s<weights[k]) return bruteForce(k+1, s);
    return max(price[k]+bruteForce(k+1, s-weights[k]), bruteForce(k+1, s));
}

int dpTopDown(int k, int s){
    if(k == N) return 0;
    if(DP[k][s] != -1) return DP[k][s];
    if(s<weights[k]) return DP[k][s] = dpTopDown(k+1, s);
    return DP[k][s] = max(price[k]+dpTopDown(k+1, s-weights[k]), dpTopDown(k+1, s));
}

int dpBottomUp(){
    int ans = 0;
    for(int i=weights[0]; i<= capacity; i++){
        DP[0][i-weights[0]] = price[0];
        ans = max(ans, DP[0][i-weights[0]]);
    }
    for(int i=1; i<N; i++){
        for(int j=weights[i]; j<=capacity; j++){
            DP[i][j-weights[i]] = DP[i-1][j] + price[i];
            ans = max(ans, DP[i][j-weights[i]]);
        }
    }
    return ans;
}

int main (int argc, char const *argv[]) {
	N = 4;
    price = {100, 70, 50, 10};
    weights = {10, 4, 6, 12};
    capacity = 12;

    // Top Down
    DP.clear();
    for(int i=0; i<N; i++) DP.push_back(Vi(capacity+1, -1));
    cout << "Top-Down: " << dpTopDown(0, capacity) << endl;
    // for(int i=0; i<N; i++) {for(int j=0; j<=capacity; j++) {cout << DP[i][j] << ' ';} cout << endl;}

    // Bottom Up
    DP.clear();
    for(int i=0; i<N; i++) DP.push_back(Vi(capacity+1, 0));
    cout << "Bottom-Up: " << dpBottomUp() << endl;
    // for(int i=0; i<N; i++) {for(int j=0; j<=capacity; j++) {cout << DP[i][j] << ' ';} cout << endl;}
    return EXIT_SUCCESS;
}
