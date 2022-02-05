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
node* insertBST(node* root,int key){
    if(root==NULL){
        return (new node(key));
    }
    if(key==root->data){
        cout<<"Dublicate data\n";
        return root;
    }
    if(key<root->data){
        root->left=insertBST(root->left,key);
    }
    else{
        root->right=insertBST(root->right,key);
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
    int arr[]={5,7,3,1,6,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    node* root=NULL;
    for(int i=0;i<n;i++){
        root=insertBST(root,arr[i]);
    }
    /*
                    5
                  /   \
                 3     7
               /  \   / 
              1   4   6
               \
                2
    */
    inorder(root);
    cout<<"\n";

    return 0;
}