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
VVi AdjMat;
string alpha = "ABCD";
int start;

int bruteForce(int s, Si visited){
    Vi res;
    for (int i = 0; i < N; i++){
        if(!visited.count(i) && s != i){
            visited.insert(i);
            if(visited.size() == N) return (AdjMat[s][i] + AdjMat[i][start]);
            else res.push_back( AdjMat[s][i] + bruteForce(i, visited));
            visited.erase(i);
        }
    }
    return *min_element(res.begin(), res.end());
}
int dp(int s, int mask){
    int m = mask;
    while(m){
        cout << m%2;
        m>>=1;
    }
    cout << ' ';
    Vi res;
    for (int i = 0; i < N; i++){
        if(!(mask & (1<<i)) && s != i){
            mask |= (1<<i);
            if(mask == (1<<N)-1) return (AdjMat[s][i] + AdjMat[i][start]);
            else res.push_back( AdjMat[s][i] + dp(i, mask));
            mask &= (!(1<<i));
        }
    }
    return *min_element(res.begin(), res.end());
}

int main (int argc, char const *argv[]) {
	N = 4;
    AdjMat = {
        {0, 20, 42, 35},
        {20, 0, 30, 34},
        {42, 30, 0, 12},
        {35, 34, 12, 0}
    };

    for (int i = 0; i < N; i++)
    {
        Si s;
        s.insert(i);
        start = i;
        // cout << "Brute-Force: " << bruteForce(i, s) << endl;
    }
    // cout << endl;
    for (int i = 0; i < N; i++)
    {
        start = i;
        int mask = 0;
        mask |= (1<<i);
        // cout << mask << endl;
        cout << "Top-Down: " << dp(i, mask) << endl;
    }

    return EXIT_SUCCESS;
}