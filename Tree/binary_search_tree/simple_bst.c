#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int d){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    // in bst all the keys in left subtree are less than the key of root and in right subtree they are greater than root
    //and left and right subtrees are also bst

    struct node* root=newnode(10);
    root->left=newnode(4);
    root->right=newnode(15);
    root->left->left=newnode(1);
    root->left->right=newnode(5);
    root->right->left=newnode(12);
    root->right->right=newnode(17);
    root->right->right->right=newnode(20);
    /*
                    10
                   /  \
                  4    15
                 / \  / \ 
                1   5 12 17
                          \
                           20
    */
   inorder(root);//inorder traversal of bst gives all keys in ascending order
   printf("\n");
    return 0;
}