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


string s1, s2;

int bruteForce(int i, int j){
    if(i==s1.size() || j==s2.size()) return 0;
    if(s1[i] == s2[j]) return 1+bruteForce(i+1, j+1);
    return max(bruteForce(i+1, j), bruteForce(i, j+1));
}

VVi DP;
int dpTopDown(int i, int j){
    if(i==s1.size() || j==s2.size()) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    if(s1[i] == s2[j]) return DP[i][j] = 1+dpTopDown(i+1, j+1);
    return DP[i][j] = max(dpTopDown(i+1, j), dpTopDown(i, j+1));
}

int dpBottomUp(){

    for (int i = 0; i < s1.size(); i++) DP[i][0] = (int)(s1[i] == s2[0]);
    for (int j = 0; j < s2.size(); j++) DP[0][j] = (int)(s1[0] == s2[j]);
    

    for (int i = 1; i < s1.size(); i++)
    {
        for (int j = 1; j < s2.size(); j++)
        {
            int val = 0;
            if(s1[i] == s2[j]) val = 1;
            DP[i][j] = max(DP[i-1][j-1]+val, max(DP[i-1][j], DP[i][j-1]));
        }
    }
    
    return DP[s1.size()-1][s2.size()-1];
}

void print() {
    std::for_each(std::begin(DP), std::end(DP), [](Vi v) {std::for_each(std::begin(v), std::end(v), [](int a) {cout << a << ' ';});cout << endl;   });cout << endl;
}
int main (int argc, char const *argv[]) {
    s1 = "Hello";
    s2 = "World is Hell but hey Hello";

    cout << bruteForce(0,0) << endl;

    DP = VVi(s1.size(), Vi(s2.size(), -1));
    cout << dpTopDown(0,0) << endl;
    
    print();
    
    DP = VVi(s1.size(), Vi(s2.size(), 0));
    cout << dpBottomUp() << endl;

    print();

    return EXIT_SUCCESS;    
}
