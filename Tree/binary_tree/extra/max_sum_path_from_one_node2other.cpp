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

int maxutilfunc(node* root,int &ans){
    if(root==NULL){
        return 0;
    }
    int left=maxutilfunc(root->left,ans);
    int right=maxutilfunc(root->right,ans);

    int nodemax=max(max(root->data,root->data+left+right),max(left+root->data,right+root->data));
    ans=max(nodemax,ans);
    int singlepathsum=max(root->data,max(left+root->data,right+root->data));
    
    return singlepathsum;

}
int maxpathSum(node* root){
    int ans=INT_MIN;
    maxutilfunc(root,ans);
    return ans;
}

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(-5);
    root->right->right=new node(-6);
    root->right->right->left=new node(7);

    /*              1
                  /   \
                2       3
               / \     / \
              4   -5   n -6
                         / \
                        7   n
    here,n==NULL
    */  
   
   cout<<maxpathSum(root)<<endl;
    

    return 0;
}