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

node* constructBSTpre(int preorder[],int *preIndex,int key,int min,int max,int n){
    if(*preIndex>=n){
        return NULL;
    }
    node* root=NULL;
    if(key<max && key>min){
        root=new node(key);
        *preIndex=*preIndex+1;
        if(*preIndex<n){
            root->left=constructBSTpre(preorder,preIndex,preorder[*preIndex],min,key,n);
        }
        if(*preIndex<n){
            root->right=constructBSTpre(preorder,preIndex,preorder[*preIndex],key,max,n);
        }
        
    }
    return root;
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
    int preorder[]={10,2,1,13,11};
    int n=sizeof(preorder)/sizeof(preorder[0]);
    int preindex=0;
    node* root=constructBSTpre(preorder,&preindex,preorder[preindex],INT_MIN,INT_MAX,n);
    inorder(root);
    cout<<"\n";

    return 0;
}