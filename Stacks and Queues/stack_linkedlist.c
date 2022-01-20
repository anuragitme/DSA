#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};
struct node* top=NULL;

void push(int data);
void pop();
void peek();
int isEmpty();
void display();

int main(){

    int choice,data;
    while(1){
        printf("--- Stack ---\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display all elements in stack\n5.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data that you want to push in stack : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
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
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}

void push(int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Stack Overflow\n");
    }
    temp->info=data;
    temp->link=top;
    top=temp;
}

void pop(){
     if(isEmpty()){
            printf("Stack Underflow\n");
            return;
        }
        struct node *del=top;
        top=top->link;
        printf("%d is popped out of stack\n",del->info);
        free(del);
}

void peek(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("Element at top of stack is = %d\n",top->info);
}

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}


void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    struct node *p =top;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n");

}




