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

void flatten(node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return; //this sub tree is flatten already
    }
    node* curr_r=root;
    if(root->left!=NULL){
        flatten(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        //till now root's prev right has cut and its left after flatten is attached to right
        //now we have to attach the cut part to tail
        node* tail=root->right;
        while(tail->right!=NULL){
            tail=tail->right;
        }
        tail->right=temp;
        curr_r=tail;
    }

    flatten(curr_r->right);

}
void preorder(node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void modifiedpre(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->right);
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

    /*              1                      1
                  /   \                     \
                2       3                    2
               / \     / \      --->          \
              4   5   69   6                   4
                         / \                    \
                        7   n                    5
    here,n==NULL                                  \
                                                   3
                                                    \
                                                     69
                                                      \
                                                       6
                                                        \
                                                         7
    */  
    node* root2=new node(1);
    root2->left=new node(2);
    root2->right=new node(3);
    root2->left->left=new node(4);
    root2->left->right=new node(5);
    root2->left->left->left=new node(6);
    /*              1                              1
                  /   \                             \
                2       3                            2
               / \     / \                            \
              4   5   n   n         --->               4
            /  \ / \                                    \
           6   n n n                                     6
                                                          \
    here,n==NULL                                           5 
                                                            \
                                                             3
    */ 
    flatten(root);
    flatten(root2);
    cout<<"Flatten tree(first) : ";
    preorder(root);
    cout<<endl;
    cout<<"Flatten tree(second): ";
    modifiedpre(root2);
    cout<<endl;
    
    return 0;
} 