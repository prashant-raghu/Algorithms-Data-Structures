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
	int key; 
	struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
	node *temp = new node(); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void preorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		cout<<root->key<<" ";
		preorder(root->left); 
		preorder(root->right); 
	} 
}
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		cout<<root->key<<" ";
		inorder(root->right); 
	}
}

void postorder(struct node *root) 
{ 
	if (root != NULL) 
	{
		postorder(root->left); 
		postorder(root->right); 
	    cout<<root->key<<" ";
	} 
} 

struct node* insert(struct node* node, int key) 
{ 
	//pass same node to function and write over it whatever the function return 
    // so NUll = f(Null, k) = new Node(k)
    if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key)
		node->right = insert(node->right, key); 
	return node; 
} 

int main() 
{ 

	struct node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 
	/* Let us create following BST 
		  50 
		/	 \ 
	   30 	 70 
	   / \   / \ 
	  20 40 60 80 
    */
	inorder(root); cout<<endl;
	preorder(root); cout<<endl;
	postorder(root); cout<<endl;

	return 0; 
} 
