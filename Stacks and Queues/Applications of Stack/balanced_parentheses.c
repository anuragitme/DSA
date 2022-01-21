#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40
char stack[MAX];
int top=-1;

int balancedP(char[],int);
int check(char,char);
void printAns(int);
void push(char);
char pop();
int peek();
int isEmpty();
int isFull();
void display();


int main(){
    char str[40]="";
    printf("Enter your string : ");
    fgets(str, 40, stdin);
    int length=strlen(str)-1;
    printAns(balancedP(str,length));

    return 0;
}
int balancedP(char str[],int len){
    for(int i=0;i<len;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(str[i]);
            
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(isEmpty()){
                return 0;
            }
            
            char val=pop();
            
            if(check(val,str[i])==0){
                return 0;
            }
        }
    }
    if(isEmpty()){
        return 1;
    }
    else{
        return 0;
    }
}
void printAns(int t){
    if(t==1){
        printf("Balance parrntheses\n");
    }
    else{
       printf("Unbalance parrntheses\n");
    }
}
int check(char a,char b){
    if(a=='(' && b==')') return 1;
    if(a=='{' && b=='}') return 1;
    if(a=='[' && b==']') return 1;
    return 0;
}
void push(char data){
    if(isFull()){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=data;
}

char pop(){
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