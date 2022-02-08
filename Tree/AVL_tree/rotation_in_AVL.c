#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int balance;
};
struct node* newnode(int d){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    root->balance=0;
}
struct node* leftRotation(struct node* pivot){
    struct node* aptr;
    aptr=pivot->right;
    pivot->right=aptr->left;
    aptr->left=pivot;
    return aptr;
}
struct node* rightRotation(struct node* pivot){
    struct node* aptr;
    aptr=pivot->left;
    pivot->left=aptr->right;
    aptr->right=pivot;
    return aptr;

}
int main(){
    struct node* root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(12);
    root->left->left=newnode(2);
    root->left->balance=0;
    root->balance=1;

    /*
           12                 10                       5
           /                 /  \                     / \
          10         lR<--  5    12   -->rR          2   10
         /                 / \                          /  \
        5                 2   7                        7    12
       / \
      2   7  
    */


    return 0;
}