#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int data);
void dequeue();
void peek();
int isEmpty();
int isFull();
void display();

int main(){
    int data,choice;
    while(1){
        printf("--- Queue ---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element that you want to insert : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default :
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}
void enqueue(int data){
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

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    printf("%d is deleted\n",queue[front]);

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

void peek(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    printf("Front element = %d\n",queue[front]);
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
        printf("Queue is empty\n");
        return;
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i=front;i<MAX;i++){
            printf("%d ",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",queue[i]);  
        }
    }
    
    printf("\n");
}
