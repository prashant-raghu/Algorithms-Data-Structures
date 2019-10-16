// Created on 05-10-2019 19:54:30 by necronomicon
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
NQueen: place n queend in n*n board without conflicts.

Most effecient solution
Data: 3 arrays of bools:
    col: to checl if col[i] has element
    diag1: to check if col[i+j] has element (backDiag \)
    diag2: to check if col[i-j+n-1] has element (FwrdDiag /)
Function called from y=0 whihc means it places element on row y from 0 to n
for each call it places queen on every possible col x from 0 to n which is valid.
*/

int n;
Vi col, diag1, diag2;

int nQueen(int y=0) {
    if(y == n) return 1;
    int r = 0;
    for (int x = 0; x < n; x++)
    {
        if(!(col[x] || diag1[x+y] || diag2[x-y+n-1])) {
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
            r += nQueen(y+1);
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
        }
    }
    return r;
}

void nQueenSolution(int y=0, string s ="") {
    if(y == n) {
        cout << s << endl;
        return;
    }
    int r = 0;
    for (int x = 0; x < n; x++)
    {
        if(!(col[x] || diag1[x+y] || diag2[x-y+n-1])) {
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
            string t = "a";
            t[0] = '0'+x;
            nQueenSolution(y+1, s+t);
            col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
        }
    }
    return;
}

int main (int argc, char const *argv[]) {
	n = 8;
    col= Vi(n, 0);
    diag1 = diag2 = Vi(2*n, 0);
    cout << nQueen() << endl << endl;
    nQueenSolution();
    return EXIT_SUCCESS;
}
