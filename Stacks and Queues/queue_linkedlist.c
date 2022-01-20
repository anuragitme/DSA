#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};
struct node* front=NULL,*rear=NULL;
void enqueue(int data);
void dequeue();
void peek();
int isEmpty();
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
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL){
            printf("Queue overflow\n");
            return;
        }
        temp->info=data;
        temp->next=NULL;
        if(rear==NULL){
            front=temp;
        }
        else{
            rear->next=temp;
        }
        rear=temp;
}

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    struct node* del=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("%d is deleted\n",del->info);
    free(del);

}

void peek(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    printf("front element = %d\n",front->info);

}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    return 0;
}


void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    struct node* p=front;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n");
}
