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

struct node* minKey(struct node* root){//O(h)
    if(root==NULL){
        return root; //tree not exists
    }
    struct node* ptr=root;
    while(ptr->left!=NULL){
        ptr=ptr->left;
    }
    return ptr;
}

struct node* rec_minKey(struct node * root){//O(h)
    if(root==NULL){
        return NULL;//tree not exists
    }
    if(root->left==NULL){
        return root;
    }
    return rec_minKey(root->left);
}


int main(){
    
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
   //struct node* min=minKey(root);
   struct node* min=rec_minKey(root);
   if(min==NULL){
       printf("Tree not exists");
   }
   else{
        printf("Minmum key in tree is %d",min->data);
   }
   printf("\n");
    return 0;
}