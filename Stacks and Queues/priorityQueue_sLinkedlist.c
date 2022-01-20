#include<stdio.h>
#include<stdlib.h>

struct node{
    int priority;//key
    int info;
    struct node* next;
};
struct node* front=NULL;

void insert(int data,int key);
void del();
void display();
int isEmpty();

int main(){
    struct node* start=NULL;
    int data,key,choice;
    while(1){
        printf("--- Priority Queue---\n");
        printf("1.Insert an Element\n2.Delete\n3.Display\n4.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value that you want to insert in list : ");
                scanf("%d",&data);
                printf("Enter the priority(key) of data : ");
                scanf("%d",&key);
                insert(data,key);
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default :
                printf("Enter a valid choice\n");
                break;
        }
    }

    return 0;
}

void insert(int data,int key){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Priority Queue Overflow\n");
        return;
    }
    temp->info=data;
    temp->priority=key;
    if(isEmpty() || front->priority>key){
        temp->next=front;
        front=temp;
        return ;
    }
    struct node* p=front;
    while(p->next!=NULL && p->next->priority<=key ){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    
}
void del(){
    if(isEmpty()){
        printf("Priority Queue underflow\n");
        return;
    }
    struct node* del=front;
    printf("%d is deleted having priority %d\n",del->info,del->priority);
    front=del->next;
    free(del);
}

void display(){
    struct node *p=front;
    if(isEmpty()){
        printf("List is Empty\n\n");
        return;
    }
    printf("Priority : Queue => |");
    while(p!=NULL){
        printf(" %d : %d |",p->priority,p->info);
        p=p->next;
    }
    printf("\n\n");
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }
    return 0;
}


