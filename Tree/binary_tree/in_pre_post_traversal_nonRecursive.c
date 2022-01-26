#include<stdio.h>
#include<stdlib.h>
#define MAX 40

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int dataz){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=dataz;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* stack[MAX];
int top=-1;
void push(struct node *item){
    if(top==MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=item;
    
}
struct node* pop(){
    if(top==-1){
        printf("Stack underflow\n");
        exit(0);
    }
    return stack[top--];
}
int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void preorder(struct node * root){
    //root-left-right
    struct node* ptr=root;
    if(ptr==NULL){
        printf("Tree is empty\n");
        return;
    }
    push(root);
    while(!isempty()){
        ptr=pop();
        printf("%d ",ptr->data);
        if(ptr->right!=NULL){
            push(ptr->right);
        }
        if(ptr->left!=NULL){
            push(ptr->left);
        }

    }
    
}

void inorder(struct node * root){
    //left-root-right
    if(root==NULL){
        printf("Tree is empty\n");
        return;
    }
    struct node*ptr=root;
    while(1){
        while(ptr->left!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL){
            printf("%d ",ptr->data);
            if(isempty()){
                return;
            }
            ptr=pop();
        }
        printf("%d ",ptr->data);
        ptr=ptr->right;
    }
    
}

void postorder(struct node * root){
    //left-right-root
    struct node* ptr=root,*q=root;
    if(ptr==NULL){
        printf("Tree is empty\n");
    }
    while(1){
        while(ptr->left!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL || ptr->right==q){
            printf("%d ",ptr->data);
            q=ptr;
            if(isempty()){
                return;
            }
            ptr=pop();
        }
        push(ptr);
        ptr=ptr->right;
    }
}
int main(){
    struct node* root=NULL;
    root=newNode(1);
    /*       1
            / \
         NULL  NULL
    */

   root->left=newNode(2);
   root->right=newNode(3);
    /*        1
            /   \
           2     3
         /  \   /  \
      NULL NULL NULL NULL
    */

   root->left->left=newNode(4);
   root->left->right=newNode(5);
   root->right->right=newNode(6);
    /*        1
            /   \
           2     3
         /  \   /  \
        4   5   n   6
      / \  / \     / \
      n n  n  n    n  n

      here,n==NULL
    */
   printf("Preorder : ");
   preorder(root);
   printf("\n");
   printf("Inorder : ");
   inorder(root);
   printf("\n");
   printf("Postorder : ");
   postorder(root);
   printf("\n");

    return 0;
}