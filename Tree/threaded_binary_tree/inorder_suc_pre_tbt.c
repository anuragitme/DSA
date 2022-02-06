#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    bool lthread;
    bool rthread;
};
struct node* newnode(int d){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=d;
    root->left=NULL;
    root->right=NULL;
    root->lthread=false;
    root->rthread=false;
}

struct node* in_succ(struct node* root){
    if(root->rthread==true){
        return root->right;
    }
    
    root=root->right;
    while(root->lthread==false){
        root=root->left;
    }
    return root;
}

struct node* in_pred(struct node* root){
    if(root->lthread==true){
        return root->left;
    }
    root=root->left;
    while(root->rthread==false){
       root=root->right;
    }
    return root;
}
int main(){
    struct node* root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->right->left=newnode(5);
    root->right->right=newnode(6);
    /*
                1
              /   \
            2       3 
          /        / \
         4        5   6
         here, right child of 2,4,5,6 will act as threads
         and left child of 4,5,6 threads
         left threads points to their inorder predecessor
         right threads pointts to thein inorder successor
    */
   //for 2
   root->left->right=root;
   root->left->rthread=true;
    //for 4
   root->left->left->left=NULL;
   root->left->left->lthread=true;
   root->left->left->right=root->left;
   root->left->left->rthread=true;
    //for 5
   root->right->left->left=root;
   root->right->left->lthread=true;
   root->right->left->right=root->right;
   root->right->left->rthread=true;
   // for 6
   root->right->right->left=root->right;
   root->right->right->lthread=true;
   root->right->right->right=NULL;
   root->right->right->rthread=true;

    struct node* val=root->right;
    struct node* in_s=in_succ(val);
    struct node* in_p=in_pred(val);
    if(in_s==NULL){
        printf("Inorder successor does not exist for %d\n",val->data);
    }
    else{
         printf("Inorder successor of %d = %d\n",val->data,in_s->data);
    }
    if(in_p==NULL){
        printf("Inorder predecessor does not exist for %d\n",val->data);
    }
    else{
         printf("Inorder predecessor of %d = %d\n",val->data,in_p->data);
    }
  
    return 0;
}