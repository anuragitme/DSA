#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int countNodes(node* root){
    if(root==NULL){
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
    //1 for current node;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    root->right->right->left=new node(7);

    /*              1
                  /   \
                2       3
               / \     / \
              4   5   n   6
                         / \
                        7   n
    here,n==NULL
    */  
   cout<<"No. of nodes in binary tree : "<<countNodes(root)<<endl;
    

    return 0;
}