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
bool checkBST(node* root,node* min,node* max){
    if(root==NULL){
        return true;
    }
    if(root->data<max->data && root->data>min->data){
        if(checkBST(root->left,min,root)){
            return checkBST(root->right,root,max);
        }
    }
    return false;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node *root=new node(5);
    root->left=new node(3);
    root->right=new node(7);
    root->left->left=new node(1);
    root->left->right=new node(4);
    root->right->left=new node(6);
    root->left->left->right=new node(2);
    /*
                    5
                  /   \
                 3     7
               /  \   / 
              1   4   6
               \
                2
    */
    node *root2=new node(5);
    root2->left=new node(3);
    root2->right=new node(9);
    root2->left->left=new node(1);
    root2->left->right=new node(7);
    root2->right->left=new node(6);
    root2->left->left->right=new node(2);
    /*
                    5
                  /   \
                 3     9
               /  \   / 
              1   7   6
               \
                2
    */

   node* min=new node(INT_MIN);
   node* max=new node(INT_MAX);
    if(checkBST(root,min,max)){
        cout<<"Tree one is BST\n";
    }
    else{
        cout<<"Tree one is not BST\n";
    }
    if(checkBST(root2,min,max)){
        cout<<"Tree two is BST\n";
    }
    else{
        cout<<"Tree two is not BST\n";
    }

    return 0;
}