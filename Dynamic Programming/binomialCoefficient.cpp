// Created on 08-09-2019 00:22:11 by necronomicon
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

int N, R; // for nCr
VVi DP;

/* 
    To compute nCr using DP.
    We have a recursive formula as follows
    1. C(n, k) = C(n-1, k-1) + C(n-1, k) is recursive
    2. C(n, 0) = C(n, n) = 1 is the base case
 */

int bruteForce(int n, int r) {
    if(r == 0 || n == r) return 1;
    else return bruteForce(n-1, r-1) + bruteForce(n-1, r); // from recursive formula
}

int dpTopDown(int n, int r) {
    if(r == 0 || n == r) return 1;
    if(DP[n][r] != -1) return DP[n][r];
    else return DP[n][r] = (dpTopDown(n-1, r-1) + dpTopDown(n-1, r));
}

int main (int argc, char const *argv[]) {
	
    N = 64;
    R = 8;

    // cout << "Brute-Force: " << bruteForce(N, R) << endl;

    DP = VVi(N+1, Vi(R+1, -1));
    cout << "Top-Down: " << dpTopDown(N, R) << endl;

    return EXIT_SUCCESS;
}
