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

Vi P; // dimensions
int N; // total matrices
VVi DP, DPans;


int bruteForce(int i, int j) {
    if(i == j) return 0;
    int cost = numeric_limits<int>::max();
    for (int k = i; k < j; k++)
    {
        cost = min(cost, bruteForce(i,k) + bruteForce(k+1, j) + (P[i-1]*P[k]*P[j]));
    }
    return cost;
}

int dpTopDown(int i, int j) {
    if(i == j) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    int cost = numeric_limits<int>::max();
    for (int k = i; k < j; k++)
    {
        cost = min(cost, dpTopDown(i,k) + dpTopDown(k+1, j) + (P[i-1]*P[k]*P[j]));
    }
    return DP[i][j] = cost;
}

int dpBottomUp() {

    for (int i = 0; i <= N; i++) DP[i][i] = 0;

    for (int l = 1; l <= N; l++)
    {
        for (int i = 0; i+l <= N; i++)
        {
            int j = i+l;
            int min_cost = numeric_limits<int>::max();
            for (int k = i; k < j; k++)
            {
                int cost = DP[i][k] + DP[k+1][j] + (P[i-1]*P[k]*P[j]);
                if(min_cost > cost) {
                    min_cost = cost;
                    DPans[i][j] = k;
                }
            }
            DP[i][j] = min_cost;
        }
    }
    for(Vi v: DP) {
        for(int x: v) cout << x << ' ';
        cout << endl;
    }
    cout << endl;
    for(Vi v: DPans) {
        for(int x: v) cout << x << ' ';
        cout << endl;
    }
    return DP[1][N];
}

int main (int argc, char const *argv[]) {
	
    P = {40, 20, 30, 10, 30};
    N = P.size()-1;

    cout << "Brute-Force: " << bruteForce(1, N) << endl;

    DP = VVi(P.size(), Vi(P.size(), -1));
    cout << "Top-Down: " << dpTopDown(1, N) << endl;

    DP = VVi(P.size(), Vi(P.size(), 0));
    DPans = VVi(P.size(), Vi(P.size(), 0));
    cout << "Bottom-Up: " << dpBottomUp() << endl;

    return EXIT_SUCCESS;
}
