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

struct node* delete(struct node* root,int dkey){
    struct node* ptr=root,*par=NULL;
    
    while(ptr!=NULL){
        if(ptr->data==dkey){
            break;
        }
        par=ptr;
        if(dkey<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    if(ptr==NULL){
        printf("dkey not found in list\n");
        return root;
    }
    
    if(ptr->left!=NULL && ptr->right!=NULL){
        struct node* in_succ=ptr->right,*par_succ=ptr;;
        while(in_succ->left!=NULL){
            par_succ=in_succ;
            in_succ=in_succ->left;
        }
        ptr->data=in_succ->data;

        //now deletion of inorder successor
        if(par_succ==ptr){
            par_succ->right=NULL;
        }
        else{
            par_succ->left=in_succ->right;
        }
        ptr=in_succ;

    }
    else if(ptr->left!=NULL){
        if(par==NULL){
            root=ptr->left;
        }
        else if(ptr==par->left){
            par->left=ptr->left;
        }
        else{
            par->right=ptr->left;
        }
    }
    else{
        if(par==NULL){
            root=ptr->right;
        }
        else if(ptr==par->left){
            par->left=ptr->right;
        }
        else{
            par->right=ptr->right;
        }
    }
    free(ptr);
    return root;
}

//same as above just simplified version(i.e. few cases are clubed together)
struct node* deletez(struct node* root,int dkey){
    struct node* ptr=root,*par=NULL;
    
    while(ptr!=NULL){
        if(ptr->data==dkey){
            break;
        }
        par=ptr;
        if(dkey<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    if(ptr==NULL){
        printf("dkey not found in list\n");
        return root;
    }
    
    if(ptr->left!=NULL && ptr->right!=NULL){
        struct node* in_succ=ptr->right,*par_succ=ptr;;
        while(in_succ->left!=NULL){
            par_succ=in_succ;
            in_succ=in_succ->left;
        }
        ptr->data=in_succ->data;
        ptr=in_succ;
        par=par_succ;

    }
    struct node* child;
    if(ptr->left!=NULL){
        child=ptr->left;
    }
    else{
        child=ptr->right;
    }
    
    if(par==NULL){
        root=child;
    }
    else if(ptr==par->left){
        par->left=child;
    }
    else{
        par->right=child;
    }

    free(ptr);
    return root;
}

struct node* rec_delete(struct node* root,int dkey){
    if(root==NULL){
        printf("dkey not found\n");
        return root;
    }
    
    if(dkey<root->data){
        root->left=rec_delete(root->left,dkey);
    }
    else if(dkey>root->data){
        root->right=rec_delete(root->right,dkey);
    }
    else{
        struct node* del=root;
        if(root->right!=NULL && root->left!=NULL){
            struct node* in_succ=root->right,*par_succ=root;
            while(in_succ->left!=NULL){
                par_succ=in_succ;
                in_succ=in_succ->left;
            }
            root->data=in_succ->data;

            //delete this in_succ
            del=in_succ;
            if(par_succ==root){
                par_succ->right=in_succ->right;
            }
            else{
                par_succ->left=in_succ->right;
            }

            //or instead of doing this we can do a recursive call here
            //root->right=rec_delete(root->right,in_succ->data);
            // then we have to bring free under both condition which are below
            
        }
        else if(del->left!=NULL){
            root=del->left;
        }
        else{
            root=del->right;
        }
        
        free(del);
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
//    root=delete(root,10);
//    root=deletez(root,10);
   root=rec_delete(root,10);
   
   /*After deletion,
                    12
                   /  \
                  4    15
                 / \    \ 
                1   5    17
                          \
                           20                 
    
    */
   inorder(root);
   printf("\n");

   

    return 0;
}