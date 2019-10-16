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

Vi K, F; // keys and frequencies
int N; // total nodes
VVi DP;

int calc(int l, int r) {
    int res=0;
    for (int i = l; i <= r; i++)
    {
        res += F[i];
    }
    return res;
}

int bruteForce(int i, int j) {
    if(i < 0 || j >= F.size() || i > j) return 0;
    if(i == j) return F[i];
    int min_cost = numeric_limits<int>::max();
    for (int k = i; k <= j; k++)
    {
        int cost = bruteForce(i, k-1) + bruteForce(k+1, j) + calc(i,j);
        min_cost = min(min_cost, cost);
    }
    return min_cost;
}

int dpTopDown(int i, int j) {
    if(i < 0 || j >= F.size() || i > j) return 0;
    if(i == j) return F[i];
    if(DP[i][j] != -1) return DP[i][j];
    int min_cost = numeric_limits<int>::max();
    for (int k = i; k <= j; k++)
    {
        int cost = bruteForce(i, k-1) + bruteForce(k+1, j) + calc(i,j);
        min_cost = min(min_cost, cost);
    }
    return DP[i][j] = min_cost;
}

int main (int argc, char const *argv[]) {

	K = {10, 12, 20};
    F = {34, 8, 50};
    N = F.size();

    cout << "Brute-Force: " << bruteForce(0, N-1) << endl;

    DP = VVi(N, Vi(N, -1));
    cout << "Top-Down: " << dpTopDown(0, N-1) << endl;

    return EXIT_SUCCESS;
}
