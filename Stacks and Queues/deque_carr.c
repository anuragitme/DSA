#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int deque[MAX];
int front=-1;
int rear=-1;

void insertFront(int data);//push
void insertRear(int data);//inject
void deleteFront();//eject
void deleteRear();//pop
int isEmpty();
int isFull();
void display();

int main(){
    int data,choice;
    while(1){
        printf("--- deque ---\n");
        printf("1.Insert at Front\n2.Insert at Rear\n3.Delete from Front\n4.Delete from Rear\n5.Display\n6.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element that you want to insert at front : ");
                scanf("%d",&data);
                insertFront(data);
                break;
            case 2:
                printf("Enter the element that you want to insert at rear : ");
                scanf("%d",&data);
                insertRear(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default :
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
void insertFront(int data){
    if(isFull()){
        printf("deque overflow\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front=MAX-1;
    }
    else{
        front--;
    }
    deque[front]=data;
}

void insertRear(int data){
    if(isFull()){
        printf("deque overflow\n");
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear==MAX-1){
        rear=0;
    }
    else{
        rear++;
    }
    deque[rear]=data;
}

void deleteFront(){
    if(isEmpty()){
        printf("deque underflow\n");
        return;
    }
    printf("%d is deleted\n",deque[front]);

    //reset
    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    if(front==MAX-1){
        front=0;
    }
    else{
    front++;
    }
}

void deleteRear(){
    if(isEmpty()){
        printf("deque underflow\n");
        return;
    }printf("%d is deleted\n",deque[rear]);

    if(front==rear){
        front=-1;
        rear=-1;
        return;
    }
    if(rear==0){
        rear==MAX-1;
    }
    else{
        rear--;
    }
}

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

void display(){
    if(isEmpty()){
        printf("deque is empty\n");
        return;
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",deque[i]);
        }
    }
    else{
        for(int i=front;i<MAX;i++){
            printf("%d ",deque[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",deque[i]);  
        }
    }
    
    printf("\n");
}
