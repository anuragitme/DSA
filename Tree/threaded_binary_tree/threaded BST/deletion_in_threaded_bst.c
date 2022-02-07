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

struct node* case_a(struct node* root,struct node* par,struct node* ptr){//leaf node
    if(par==NULL){
        root=NULL;
    }
    else if(ptr==par->left){
        par->lthread=true;
        par->left=ptr->left;
    }
    else{
        par->rthread=true;
        par->right=ptr->right;
    }
    free(ptr);
    return root;

}
struct node* case_b(struct node* root,struct node* par,struct node* ptr){//has one child
    struct node* child,*s,*p;
    if(ptr->lthread==false){
        child=ptr->left;
    }
    else{
        child=ptr->right;
    }
    if(par==NULL){
        root=child;
    }
    else if(par->left==ptr){
        par->left=child;
    }
    else{
        par->right=child;
    }
    s=in_succ(ptr);
    p=in_pred(ptr);
    if(ptr->lthread==false){
        p->right=s;
    }
    else{
        s->left=p;
    }
    free(ptr);
    return root;
}
struct node* case_c(struct node* root,struct node* par,struct node* ptr){//2 child
    struct node* succ,*parsucc;
    parsucc=ptr;
    succ=ptr->right;
    while(succ->left!=NULL){
        parsucc=succ;
        succ=succ->left;
    }
    ptr->data=succ->data;
    if(succ->lthread==true && succ->rthread==true){
        root=case_a(root,parsucc,succ);
    }
    else{
        root=case_b(root,parsucc,succ);
    }
    return root;
}
struct node* delete(struct node *root,int dkey){
    struct node* ptr=root,*par=NULL;
    int found=0;
    while(ptr!=NULL){
        if(ptr->data==dkey){
            found=1;
            break;
        }
        par=ptr;
        if(dkey<ptr->data){
            if(ptr->lthread==false){
                ptr=ptr->left;
            }
            else{
                break;
            }
        }
        else{
            if(ptr->rthread==false){
                ptr=ptr->right;
            }
            else{
                break;
            }
        }
    }
    
    if(found==0){
        printf("node not found in the tree\n");
    }
    else if(ptr->lthread==false && ptr->rthread==false){
        root=case_c(root,par,ptr);
    }
    else if(ptr->lthread==false){
        root=case_b(root,par,ptr);
    }
    else if(ptr->rthread==false){
        root=case_b(root,par,ptr);
    }
    else{
        root=case_a(root,par,ptr);
    }

    return root;
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
    root=delete(root,4);
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    return 0;
}