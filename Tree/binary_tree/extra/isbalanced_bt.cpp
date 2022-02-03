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

bool isbalanced(node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(!isbalanced(root->left,&lh)){
        return false;
    }
    if(!isbalanced(root->right,&rh)){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    return false; //else
}


int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    root->right->left=new node(69);
    root->right->right->left=new node(7);

    /*              1
                  /   \
                2       3
               / \     / \
              4   5   69   6
                         / \
                        7   n
    here,n==NULL
    */  
    node* root2=new node(1);
    root2->left=new node(2);
    root2->right=new node(3);
    root2->left->left=new node(4);
    root2->left->right=new node(5);
    root2->left->left->left=new node(6);
    /*              1                               1
                  /   \                            / \
                2       3                         2   3
               / \     / \     --->              / \
              4   5   n   n                     4  5
            /  \ / \                           /
           6   n n n                          6

    here,n==NULL
    */ 
    int h1=0,h2=0;
    if(isbalanced(root,&h1)){
        cout<<"First tree is balanced\n";
    }
    else{
        cout<<"First tree is unbalanced\n";
    }
     if(isbalanced(root2,&h2)){
        cout<<"Second tree is balanced\n";
    }
    else{
        cout<<"Second tree is unbalanced\n";
    }

    return 0;
}