#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
int search(int in[],int st,int end,int curr){
    for(int i=st;i<=end;i++){
        if(in[i]==curr){
            return i;
        }
    }
    return -1;
}
node * buildTree(int in[],int pos[],int st,int end){
    if(st>end){
        return NULL;
    }
   static int i=end;
   int curr=pos[i];
   i--;
   int r=search(in,st,end,curr);

   node* root=new node(curr);
   root->right=buildTree(in,pos,r+1,end);
   root->left=buildTree(in,pos,st,r-1);

   return root;


}
void inorderTra(node* root){
    if(root==NULL){
        return;
    }
    inorderTra(root->left);
    cout<<root->data<<" ";
    inorderTra(root->right);
    return;
    
}
int main(){
    int in[]={3,2,5,4,6,1,8,7,10,9};
    int pos[]={3,5,6,4,2,8,10,9,7,1};
    
    node* root=buildTree(in,pos,0,9);

    inorderTra(root);
    cout<<endl;
    return 0;
}