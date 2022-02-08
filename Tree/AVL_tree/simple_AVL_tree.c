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
int main(){
    struct node* root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(12);
    root->left->left=newnode(2);
    root->left->balance=1;
    root->balance=1;

    /*
                    10
                   /  \
                  5    12
                 /
                2 
    */

    return 0;
}