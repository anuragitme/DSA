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
int searchMid(int arr[],int st,int end){
    return (st+end)/2;
}
node* buildBalBST(int arr[],int st,int end){
    if(st>end){
        return NULL;
    }
    int midin=(st+end)/2;
    node* root=new node(arr[midin]);
    if(st==end){//there is no need to do this as it is handled already it just saves one extra step aur recursive call
        return root;
    }
    root->left=buildBalBST(arr,st,midin-1);
    root->right=buildBalBST(arr,midin+1,end);
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
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int n;
    cout<<"Enter the size of tree that you want to build : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the nodes :\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    node* root=buildBalBST(arr,0,n-1);
    cout<<"Inorder sequence of built tree: ";
    inorder(root);
    cout<<"\n";
    cout<<"Preorder sequence of built tree: ";
    preorder(root);
    cout<<"\n";
    return 0;
}