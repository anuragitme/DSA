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

void printSTNatK(node* root,int k){
    if(root==NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSTNatK(root->left,k-1);
    printSTNatK(root->right,k-1);

}
int printNatK(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSTNatK(root,k);
        return 0;
    }
    int dl=printNatK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSTNatK(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr=printNatK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printSTNatK(root->left,k-dl-2);
        }
        return dr+1;
    }

    return -1;

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
   int res=printNatK(root,root->right,2);
   cout<<endl;
    

    return 0;
}