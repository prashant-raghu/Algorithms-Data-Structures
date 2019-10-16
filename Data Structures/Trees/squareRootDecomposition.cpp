// Created on 20-07-2019 20:13:23 by necronomicon
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
RSQ tree
doesnt use mo algo
*/


// global variables
int N, blocks;
Vi V, SQ;

void preProcess(){
    N = V.size();
    blocks = (int) sqrt(N + 0.0) + 1; // number of blocks
    SQ = Vi(blocks, 0);
    for (int i = 0; i < N; i++)
    {
        SQ[i/blocks] += V[i];
    }
}

void update(int idx, int val){
    int block = idx/blocks;
    int diff = val - V[idx];
    V[idx] += diff;
    SQ[block] += diff;
}

int query(int l, int r){
    int blockL = l/blocks, blockR = r/blocks;
    int sum = 0;
    if(blockL == blockR){
        for (int i = l; i <= r; i++) sum += V[i]; // when both lie inside a block just add them in O(r-l)
    }
    else{
        for (int i = l; i <= (blockL+1)*(blocks-1); i++) sum += V[i]; // left block
        for (int i =  (blockR)*(blocks); i <= r; i++) sum += V[i]; // right block
        for (int i = blockL+1; i < blockR; i++) sum += SQ[i]; // add complete block in between
    }
    return sum;
}

int main (int argc, char const *argv[]) {
	V = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    preProcess();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    
    return EXIT_SUCCESS;
}
