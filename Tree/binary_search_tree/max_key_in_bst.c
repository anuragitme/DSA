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

struct node* maxKey(struct node* root){//O(h)
    if(root==NULL){
        return root; //tree not exists
    }
    struct node* ptr=root;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    }
    return ptr;
}

struct node* rec_maxKey(struct node * root){//O(h)
    if(root==NULL){
        return NULL;//tree not exists
    }
    if(root->right==NULL){
        return root;
    }
    return rec_maxKey(root->right);
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
   struct node* max=maxKey(root);
   //struct node* max=rec_maxKey(root);
   if(max==NULL){
       printf("Tree not exists");
   }
   else{
        printf("Maximum key in tree is %d",max->data);
   }
   printf("\n");
    return 0;
}