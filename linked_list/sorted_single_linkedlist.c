#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};

struct node* insert(struct node* start,int data);
struct node* removez(struct node* start,int data);
void display(struct node* start);
void search(struct node* start,int data);

int main(){
    struct node* start=NULL;
    int data,choice;
    while(1){
        printf("--- Sorted Single LINKED LIST ---\n");
        printf("1.Insert an Element\n2.Delete an element\n3.Display\n4.Search\n5.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value that you want to insert in list : ");
                scanf("%d",&data);
                start=insert(start,data);
                break;
            case 2:
                printf("Enter the value that you want to remove form the list : ");
                scanf("%d",&data);
                start=removez(start,data);
                break;
            case 3:
                display(start);
                break;
            case 4:
                printf("Enter the value that you want to search : ");
                scanf("%d",&data);
                search(start,data);
                break;
            case 5:
                exit(0);
                break;
            default :
                printf("Enter a valid choice\n");
                break;
        }
    }

    return 0;
}

struct node* insert(struct node* start,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(start==NULL || start->info>=data){
        temp->next=start;
        start=temp;
        return start;
    }
    struct node* p=start;
    while(p->next!=NULL && p->next->info<data  ){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    return start;
}

void search(struct node* start,int data){
        struct node* p=start;
        int i=1;
        while(p!=NULL && p->info<=data){
            if(p->info==data){
                printf("%d found at index = %d\n\n",data,i);
                return;
            }
            i++;
            p=p->next;
        }
        printf("%d not found in the list\n\n",data);
        return;
}

struct node* removez(struct node* start,int data){
    struct node *p=start;
        if(start==NULL){
            printf("List is empty\n");
            return start;
        }
        else if(start->info==data){
            struct node * del=start;
            start=del->next;
            free(del);
            return start;
        }
        while(p->next!=NULL){
            if(p->next->info==data){
                struct node * del=p->next;
                p->next=del->next;
                free(del);
                return start;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n");
        return start;
}

void display(struct node* start){
    struct node *p=start;
    if(start==NULL){
        printf("List is Empty\n\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
    printf("\n\n");
}


