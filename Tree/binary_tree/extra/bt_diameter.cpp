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

int height(node* root){//O(n)
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}
int diameter(node* root){//O(n*n)
    if(root==NULL){
        return 0;
    }
    int left_dia=diameter(root->left);
    int right_dia=diameter(root->right);
    int curr_dia=height(root->left)+height(root->right)+1;
    return max(curr_dia,max(left_dia,right_dia));
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
   cout<< "Diameter of binary tree : "<<diameter(root)<<endl;
    

    return 0;
}