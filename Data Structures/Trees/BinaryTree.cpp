#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct node 
{ 
    node(){};
    int val; 
    struct node *left;
    struct node *right; 
}; 

node* newNode(int val)
{ 
    node *n = new node();
    n->val = val; 
    n->left = NULL; 
    n->right = NULL; 
    return(n);
}

int main()
{ 
    struct node *root = newNode(1); 
    root->left	 = newNode(2); 
    root->right	 = newNode(3); 
    root->left->left = newNode(4); 
    /* 4 becomes left child of 2 
            1 
        /	 \ 
        2		 3 
        / \	 / \ 
    4 NULL NULL NULL
    / \ 
    NULL NULL 
    */
    return 0; 
}
