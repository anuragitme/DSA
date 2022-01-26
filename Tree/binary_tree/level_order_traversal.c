#include<stdio.h>
#include<stdlib.h>
#define MAX 30

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

//using circular queue
struct node * queue[MAX];
int front=-1;
int rear=-1;

int isEmpty(){
    if(front == -1){
        return 1;
    }
    return 0;
}

int isFull(){
    if((rear==MAX-1 && front==0) || (front-rear==1)){
        return 1;
    }
    return 0;
}

void enqueue(struct node* data){
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
    }
    queue[rear]=data;
}

struct node* dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        exit(1);
    }
    struct node* item=queue[front];

    //reset
    if(front==rear){
        front=-1;
        rear=-1;
        return item;
    }
    if(front==MAX-1){
        front=0;
    }
    else{
    front++;
    }
    return item;
}

void levelTraversal(struct node* root){
    if(root==NULL){
        printf("Tree is empty\n");
    }
    struct node* ptr=root;
    enqueue(ptr);
    while(!isEmpty()){
        ptr=dequeue();
        printf("%d ",ptr->data);
        if(ptr->left!=NULL){
            enqueue(ptr->left);
        }
        if(ptr->right!=NULL){
            enqueue(ptr->right);
        }

    }
    printf("\n");
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
    printf("Level order traversal : ");
    levelTraversal(root);

    return 0;
}