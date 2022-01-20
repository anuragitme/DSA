#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
char stack[MAX];
int top=-1;

void push(char data);
int pop();
int peek();
int isEmpty();
int isFull();
void display();

int main(){
    char str[20]="";
    printf("Enter your string : ");
   // gets(str);
    fgets(str, 20, stdin);
    int length=strlen(str)-1;
    for(int i=0;i<length;i++){
        push(str[i]);
    }
    for(int i=0;i<length;i++){
        str[i]=pop();
    }
    printf("Reverse string is : %s",str);
    //puts(str);
   // fputs(str,stdout);

    return 0;
}

void push(char data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=data;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(0);
    }

    return stack[top--];
}

int peek(){
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