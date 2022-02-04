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

struct node* search(struct node* root,int key){//O(h),h is height of tree

    struct node* ptr=root;
    while(ptr!=NULL){
        if(ptr->data==key){
            return ptr;
        }
        else if(key<ptr->data){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    return ptr;
}

struct node* recursive_search(struct node* root,int key){//O(h)
    if(root==NULL || root->data==key){
        return root;
    }
    if(key<root->data){
        return recursive_search(root->left,key);
    }
    return recursive_search(root->right,key);

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
   int key1=12,key2=6;
   struct node* found1=search(root,key1);
   //struct node* found1=recursive_search(root,key1);
   if(found1==NULL){
       printf("%d is not found in tree\n",key1);
   }
   else{
       printf("%d found in the tree\n",found1->data);
   }
   struct node* found2=search(root,key2);
   //struct node* found2=recursive_search(root,key2);
   if(found2==NULL){
       printf("%d is not found in tree\n",key2);
   }
   else{
       printf("%d found in the tree\n",found2->data);
   }
   printf("\n");
    return 0;
}