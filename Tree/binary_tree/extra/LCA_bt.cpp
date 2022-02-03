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

bool getPath(node* root,int key,vector<int> &path){

    if(root==NULL){
        return false;
    } 

    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }

    //now we now that we are at wrong path so we will pop
    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;
    
    if(getPath(root,n1,path1)==false || getPath(root,n2,path2)==false){
        return -1; //for n1 or n2 ,or both not found in tree
    }
    //now both will have path so we will find path changed at which point
    int pc;
    for(pc=0;pc<path1.size()&& pc<path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }

    return path1[pc-1];

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
    
    cout<<"Lowest Common Ancestor of 69 and 7 in first tree is : "<<LCA(root,69,7)<<endl;
    cout<<"Lowest Common Ancestor of 6 and 4 in second tree is : "<<LCA(root2,6,4)<<endl;
    

    return 0;
} 