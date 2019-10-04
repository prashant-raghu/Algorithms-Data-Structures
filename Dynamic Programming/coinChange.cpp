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


int N, targetSum;
Vi coinValue;
Vi DP;

int bruteForce(int s){
    if(s == 0) return 0;
    Vi res;
    for(int coin: coinValue){
        if(s >= coin) res.push_back(1+bruteForce(s-coin));
    }
    return *min_element(res.begin(), res.end());
}

int dpTopDown(int s){
    if(s == 0) return 0;
    if(DP[s] != -1) return DP[s];
    Vi res;
    for(int coin: coinValue){
        if(s >= coin) res.push_back(1+dpTopDown(s-coin));
    }
    return DP[s] = *min_element(res.begin(), res.end());
}

int dpBottomUp(){
    DP[0] = 0;
    for (int i = 0; i <= targetSum; i++)
    {
        for(int coin: coinValue){
            if(i >= coin){
                DP[i] = 1 + min(DP[i], DP[i-coin]);
            }
        }
    }
    return DP[targetSum];
}

int main (int argc, char const *argv[]) {
	N = 2;
    targetSum = 10;
    coinValue = {1, 5};

    cout << "Brute-Force: " << bruteForce(targetSum) << endl;

    // Top Down
    DP.clear();
    DP = Vi(targetSum+1, -1);
    cout << "Top-Down: " << dpTopDown(targetSum) << endl;
    for(int x: DP) cout << x << ' ';
    cout << endl;

    // Bottom Up
    DP.clear();
    DP = Vi(targetSum+1, INF);
    cout << "Bottom-Up: " << dpBottomUp() << endl;
    for(int x: DP) cout << x << ' ';
    cout << endl;
    
    return EXIT_SUCCESS;
}
