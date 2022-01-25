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
void preorder(struct node * root){
    //root-left-right
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node * root){
    //left-root-right
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void postorder(struct node * root){
    //left-right-root
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
   
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
   printf("Preorder : ");
   preorder(root);
   printf("\n");
   printf("Inorder : ");
   inorder(root);
   printf("\n");
   printf("Postorder : ");
   postorder(root);
   printf("\n");

    return 0;
}