#include<stdio.h>
#include<stdlib.h>

struct listNode{
    int data;
    struct listNode* next;
};

struct listNode* newlistNode(int data){
    struct listNode * temp=(struct listNode*)malloc(sizeof(struct listNode));
    temp->data=data;
    temp->next=NULL;
    return temp;
}

struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

struct treeNode* newtreeNode(int data){
    struct treeNode * root=(struct treeNode*)malloc(sizeof(struct treeNode));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

struct listNode* createList(struct listNode* start,int n){
    int localdata;
    if(n==0) return NULL;
    
    scanf("%d",&localdata);
    struct listNode* ptr=newlistNode(localdata);
    start=ptr;
    struct listNode* q;
    for(int i=2;i<=n;i++){
        scanf("%d",&localdata);
        struct listNode* q=newlistNode(localdata);
        ptr->next=q;
        ptr=q;
    }
    return start;

}
struct treeNode* buildTree(struct listNode* inorder,struct listNode* postorder,int n){ 
    struct listNode* ptr=postorder,*ktr=inorder;
    if(n==0) return NULL;
    for(int i=0;i<n-1;i++){
        ptr=ptr->next;
    }
    //now ptr points to current root of this subtree
    int curr=ptr->data;
    struct treeNode * root=newtreeNode(curr);
    if(n==1) return root;
    int i=0;
    for(;ktr->data!=curr;i++){
        ktr=ktr->next;
    }
    //ktr ponts to current root in inorder
    // i is no. of nodes in left sub-tree
    root->left=buildTree(inorder,postorder,i);

    ptr=postorder;
    for(int j=0;j<i;j++){
        ptr=ptr->next;
    }
    //now ptr points to postorder for right subtree
    root->right=buildTree(ktr->next,ptr,n-i-1);

    return root;

}
void inorderTraversal(struct treeNode * root){
   
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

int main(){
    int n;
    printf("Enter the number of nodes in tree : ");
    scanf("%d",&n);

    struct listNode* inorder=NULL;
    struct listNode* postorder=NULL;
    printf("Enter the postorder traversal sequence\n");
    postorder=createList(postorder,n);
    printf("Enter the inorder traversal sequence\n");
    inorder=createList(inorder,n);
    
    struct treeNode * root=buildTree(inorder,postorder,n);
    
   // inorderTraversal(root);


    return 0;
}