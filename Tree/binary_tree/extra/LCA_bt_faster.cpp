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

node* LCA(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    node *left_lca=LCA(root->left,n1,n2);
    node *right_lca=LCA(root->right,n1,n2);

    if(left_lca!=NULL && right_lca!=NULL){
        return root;
    }
    if(left_lca!=NULL){ // i.e. right is null
        return left_lca;
    }
    return right_lca; // else left is null

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
    
    cout<<"Lowest Common Ancestor of 69 and 7 in first tree is : "<<LCA(root,69,7)->data<<endl;
    cout<<"Lowest Common Ancestor of 6 and 4 in second tree is : "<<LCA(root2,6,4)->data<<endl;
    

    return 0;
} 