//same as done with c
#include<bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
queue<node*> queuez;
void levelTra(node*root){
    if(root==NULL){
        cout<<"Tree is empty\n";
        return;
    }
    node* ptr=root;
    queuez.push(ptr);
    while(!queuez.empty()){
        ptr=queuez.front();
        cout<<ptr->data<<" ";
        queuez.pop();

        if(ptr->left!=NULL){
            queuez.push(ptr->left);
        }
        if(ptr->right!=NULL){
            queuez.push(ptr->right);
        }
    }
}
int main(){
    node*root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);
    root->right->left->right = new node(8);
    /*
                     1
                   /   \
                  2     3
                 / \   / \
                n   4  5  n
                   /\  /\
                  6 7  n 8
    */
    
   levelTra(root);
   cout<<endl;
    

    return 0;
}