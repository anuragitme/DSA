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

void sumReplace(node* root){
    if(root==NULL){
        return;
    }
    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
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
   cout<<"Initially : ";
   preorder(root);
   cout<<endl;
   sumReplace(root);
   cout<<"Finally : ";
   preorder(root);
   cout<<endl;
    

    return 0;
}