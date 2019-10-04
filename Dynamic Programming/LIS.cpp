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


int N;
Vi numbers;
Vi DP;

int bruteForce(int k){
    Vi res;
    for (int i = 0; i < k; i++)
    {
        if(numbers[i] < numbers[k]) res.push_back(bruteForce(i));
    }
    if(res.size() == 0) return 1;
    return 1+(*max_element(res.begin(), res.end()));
}

int dpTopDown(int k){
    if(k>=0 && DP[k]!=0) return DP[k];
    Vi res;
    for (int i = 0; i < k; i++)
    {
        if(numbers[i] < numbers[k]) res.push_back(dpTopDown(i));
    }
    if(res.size() == 0) return 1;
    return DP[k] = 1+(*max_element(res.begin(), res.end()));
}

int dpBottomUp(){
    for (int i = 0; i < N+1; i++)
    {
        int m = 0;
        for (int j = 0; j < i; j++)
        {
            if(numbers[j] < numbers[i]) m = max(m, DP[j]);
        }
        m++;
        DP[i] = m;
    }
    return (*DP.rbegin())-1;
}

int main (int argc, char const *argv[]) {
	N = 9;
    numbers = {-7, 10, 9, 2, 3, 8, 8, 1, 10};
    numbers.push_back(INF); // adding extra element cuz otherwise we have to run func for every pos 0->N
    cout << "Brute-Force: " << bruteForce(N)-1 << endl;

    // Top Down
    DP.clear();
    DP = Vi(N+1, 0);
    cout << "Top-Down: " << dpTopDown(N)-1 << endl;
    for(int x: DP) cout << x << ' ';
    cout << endl;

    // Bottom Up
    DP.clear();
    DP = Vi(N+1, 0);
    cout << "Bottom-Up: " << dpBottomUp() << endl;
    for(int x: DP) cout << x << ' ';
    cout << endl;

    return EXIT_SUCCESS;    
}
