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

void inorder(struct node* root){
   if(root==NULL){
       printf("TREE IS EMPTY\n");
       return;
   }
    while(root->lthread==false){
        root=root->left;
    }
    
    while(root!=NULL){
        printf("%d ",root->data);
        root=in_succ(root);
    }

}
void preorder(struct node* root){
    if(root==NULL){
       printf("TREE IS EMPTY\n");
       return;
    }
    while(root!=NULL){
        printf("%d ",root->data);
        if(root->lthread==false){
            root=root->left;
        }
        else if(root->rthread==false){
            root=root->right;
        }
        else{
            while(root!=NULL && root->rthread==true){
                root=root->right;
            }
            if(root!=NULL){
                root=root->right;
            }
        }
    }
}

struct node* insert(struct node* root,int key){
   if(root==NULL){
       root=newnode(key);
       root->lthread=true;
       root->rthread=true;
       return root;
   }
   if(root->data==key){
       printf("Dublicate\n");
       return root;
   }
   if(key<root->data){
       if(root->lthread==false){
           root->left=insert(root->left,key);
       }
       else{
           struct node* temp=root->left;
           root->lthread=false;
           root->left=newnode(key);
           root->left->lthread=true;
           root->left->rthread=true;
           root->left->left=temp;
           root->left->right=root;
       }
   }
   else{
       if(root->rthread==false){
           root->right=insert(root->right,key);
       }
       else{
           struct node* temp=root->right;
           root->rthread=false;
           root->right=newnode(key);
           root->right->lthread=true;
           root->right->rthread=true;
           root->right->left=root;
           root->right->right=temp;
       }
   }
   return root;
         
}

struct node* nonrec_insert(struct node* mroot,int key){
    struct node* root=mroot;
    if(root==NULL){
       root=newnode(key);
       root->lthread=true;
       root->rthread=true;
       return root;
    }
    while(1){
        if(root->data==key){
           printf("Dublicate\n");
           return root;
        }
        if(key<root->data){
            if(root->lthread==false){
                root=root->left;                                     
            }
            else{
               break;
            }
        }
        else{
            if(root->rthread==false){
                root=root->right;                                                                                                                              
            }
            else{
               break;
            }
        }
    }
    struct node* temp=newnode(key);
    temp->lthread=true;
    temp->rthread=true;
    if(key<root->data){
        temp->left=root->left;
        temp->right=root;
        root->left=temp;
        root->lthread=false;
    }
    else{
        temp->right=root->right;
        temp->left=root;
        root->right=temp;
        root->rthread=false;
    }

    return mroot;
}
int main(){
    struct node* root=newnode(4);
    root->left=newnode(2);
    root->right=newnode(7);
    root->left->left=newnode(1);
    root->right->left=newnode(5);
    root->right->right=newnode(9);
    /*
                4
              /   \
            2       7 
          /        / \
         1        5   9
         here, right child of 1,2,5,9 will act as threads
         and left child of 1,5,9 threads
         left threads points to their inorder predecessor
         right threads pointts to thein inorder successor
    */
   //for 2
   root->left->right=root;
   root->left->rthread=true;
    //for 1
   root->left->left->left=NULL;
   root->left->left->lthread=true;
   root->left->left->right=root->left;
   root->left->left->rthread=true;
    //for 5
   root->right->left->left=root;
   root->right->left->lthread=true;
   root->right->left->right=root->right;
   root->right->left->rthread=true;
   // for 9
   root->right->right->left=root->right;
   root->right->right->lthread=true;
   root->right->right->right=NULL;
   root->right->right->rthread=true;

    inorder(root);
    printf("\n");
    //root=insert(root,6);//recursive
    root=nonrec_insert(root,6);//non_recursive
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    return 0;
}