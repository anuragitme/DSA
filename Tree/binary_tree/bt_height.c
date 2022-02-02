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
int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    int left_h=height(root->left);
    int right_h=height(root->right);
    if(left_h>right_h){
        return 1+left_h;
    }
    return 1+right_h; //else
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
   root->right->right->left=newNode(7);
    /*        1
            /   \
           2     3
         /  \   /  \
        4   5   n   6
      / \  / \     / \
      n n  n  n    7  n

      here,n==NULL
      height=4
    */

   printf("Height of this tree is %d\n",height(root));


    return 0;
}