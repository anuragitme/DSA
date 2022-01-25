#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int dataz){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=dataz;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int main(){
    struct node* root=NULL;
    root=newNode(1);
    /*       1
            / \
         NULL  NULL
    */

   root->left=newNode(2);
   root->right=newNode(3);
    /*        1
            /   \
           2     3
         /  \   /  \
      NULL NULL NULL NULL
    */

   root->left->left=newNode(4);
   root->left->right=newNode(5);
   root->right->right=newNode(6);
    /*        1
            /   \
           2     3
         /  \   /  \
        4   5   n   6
      / \  / \     / \
      n n  n  n    n  n

      here,n==NULL
    */


    return 0;
}