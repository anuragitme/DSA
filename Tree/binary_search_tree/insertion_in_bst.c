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

struct node* insert(struct node* root,int key){//O(h)
    if(root==NULL){
        struct node* temp=newnode(key);
        root==temp;
        return root;
    }
    struct node* ptr=root,*par=NULL;
    while(ptr!=NULL){
        if(ptr->data==key){
            printf("Dublicate\n");
            return root;
        }
        par=ptr;
        if(key<ptr->data){
           ptr=ptr->left; 
        }
        else{
            ptr=ptr->right;
        }
    }
    if(key<par->data){
        par->left=newnode(key);
    }
    else{
        par->right=newnode(key);
    }
    return root;
}

struct node* rec_insert(struct node* root,int key){//O(h)
       if(root==NULL){
           return newnode(key);
       }
       if(root->data==key){
           printf("Dublicate\n");
           return root;
       }
       if(key<root->data){
           root->left= rec_insert(root->left,key);
       }
       else{
           root->right=rec_insert(root->right,key);
       }
    
    return root;
       
}

void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
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

//    root=insert(root,6);
//    root=insert(root,18);
//    root=insert(root,0);
//    root=insert(root,25);
   root=rec_insert(root,6);
   root=rec_insert(root,18);
   root=rec_insert(root,0);
   root=rec_insert(root,25);
   /*
                    10
                   /  \
                  4    15
                 / \  / \ 
                1   5 12 17
               /     \     \
              0       6     20
                           /  \
                          18  25

    all newly inserted nodes are leaf nodes 
    */
   inorder(root);
   printf("\n");

   

    return 0;
}