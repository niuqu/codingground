//https://www.hackerrank.com/challenges/swap-nodes-algo


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
public:
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
public:    
    int data;
    node *left;
    node *right;
};

int correntLevel;
bool printLevel(node * root, int level=0)
{
  if (root==NULL) return false;
  if (correntLevel==level){
      std::cout << root->data << ' ';
      return true;
  }
  bool l = printLevel(root->left, level+1);
  bool r = printLevel(root->right, level+1);
  return l||r;
}

void LevelOrder(node * root)
{
  correntLevel = 0;    
  while (printLevel(root, 0))
    correntLevel++;
}

node *ensertleaves(node *root, int a, int b){
    if (root==NULL)
        root = new node(1);
    int level = 1;
    
    if (a!=-1) root->left = new node(a);
    if (b!=-1) root->right = new node(b);
    return root;
}

node *swaplevels(node* root, int k){
    return root;
}

void inorder(node* root){
    if (root==NULL) return;
    inorder(root->left);
    std::cout << root->data << ' ';
    inorder(root->right);
}

int buildlevel;
node *buildtree(int n)
{    
    node *root = new node(1);
    node *curr = root;
    int i;
    int a, b;
    
    buildlevel = 2; 
    for (i=0; i<n; i++){
        std::cin >> a >> b;
        root = ensertleaves(root, a, b);
        //inorder(root); std::cout << endl;
    }
    //inorder(root); std::cout << endl;
    return root;
}

int main() {
    node *root = NULL;
    int N, T, i;
    int k;
    
    std::cin >> N;
    root = buildtree(N);
    inorder(root); std::cout << endl;

    std::cin >> T;
    for (i=0; i<T; i++){
        std::cin >> k;
        root = swaplevels(root, k);
        //inorder(root); std::cout << endl;
    }
    
    return 0;
}
