//same as done with c
#include<bits/stdc++.h>

using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int dataz){
        data=dataz;
        left=NULL;
        right=NULL;
    }
};

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    /*
            1
           / \
          2   3
         / \ / \
         n n n n

        here, n==NULL
    */

    return 0;
}