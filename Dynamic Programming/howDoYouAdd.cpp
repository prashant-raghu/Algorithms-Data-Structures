// Created on 30-07-2019 08:24:32 by necronomicon
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

/* 
Given an integer n, how many ways can K non-negative
integers less than or equal to n add up to n? Constraints: 1 ≤ n,K ≤ 100. Example: For
n = 20 and K = 2, there are 21 ways: 0+20, 1+19, 2+18, 3+17, . . . , 20+0.
*/

int N, K;

VVi DP;

int bruteForce(int n, int k){
    if(k == 1) return 1;
    int total = 0;
    for (int i = 0; i <= n; i++)
    {
        total += bruteForce(n-i, k-1);
    }
    return total;
}

int dpTopDown(int n, int k){
    if(k == 1) return 1;
    if(DP[n][k] != 0) return DP[n][k];
    int total = 0;
    for (int i = 0; i <= n; i++)
    {
        total += dpTopDown(n-i, k-1);
    }
    return DP[n][k] = total;
}

int dpBottomUp(){
    for (int i = 0; i <= N; i++) DP[i][1] = 1;
    for (int i = 2; i <= K; i++)
    {
        for (int i = 0; i <= N; i++)
        {
            
        }
    }
    
}

int main (int argc, char const *argv[]) {
	N = 20;
    K = 3;

    cout << "Brute-Force: " << bruteForce(N, K) << endl;

    // Top Down
    DP.clear();
    for (int i = 0; i <= N; i++) DP.push_back(Vi(K+1, 0));
    cout << "Top-Down: " << dpTopDown(N, K) << endl;
    for (int i = 0; i <= N; i++){for(int x: DP[i]) {cout << x << ' ';} cout << endl;}
    cout << endl;

    // Top Down
    DP.clear();
    for (int i = 0; i <= N; i++) DP.push_back(Vi(K+1, 0));
    cout << "Bottom-Up: " << dpBottomUp() << endl;
    for (int i = 0; i <= N; i++){for(int x: DP[i]) {cout << x << ' ';} cout << endl;}
    cout << endl;

    return EXIT_SUCCESS;
}
