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

void rightview(node * root){
    if(root==NULL){
        return;
    }
    queue<node*> quack;
    quack.push(root);
    while(!quack.empty()){
        int n=quack.size();
        node* curr=NULL;
        for(int i=0;i<n;i++){
            curr=quack.front();
            quack.pop();
            if(curr->left!=NULL){
                quack.push(curr->left);
            }
            if(curr->right!=NULL){
                quack.push(curr->right);
            }
        }
        cout<<curr->data<<" ";
    }
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
    cout<<"Right view of first tree :";
    rightview(root);
    cout<<endl;
    cout<<"Right view of second tree :";
    rightview(root2);
    cout<<endl;

    return 0;
}