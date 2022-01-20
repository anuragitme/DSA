#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX];
int top=-1;

void push(int data);
void pop();
int peek();
int isEmpty();
int isFull();
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
                if(isEmpty()){
                    printf("Stack underflow\n");
                }
                else{
                    printf("Element at top of stack is %d\n",peek());
                }
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
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=data;
}

void pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    printf("%d is popped out from stack\n",stack[top]);
    --top;

}

int peek(){
    // if(isEmpty){
    //     printf("Stack underflow\n");
    //     exit(0);
    // }
    return stack[top];
    
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFull(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}

void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }

    for(int i=0;i<=top;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
