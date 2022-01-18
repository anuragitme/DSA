#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;
};

struct node * Create(struct node* start);
void Display(struct node* start);
struct node * AddToStart(struct node* start,int data);
struct node * AddToEnd(struct node* start,int data);
void SelectionSort(struct node* start);
void BubbleSort(struct node* start);


int main(){
    int choice,item,data;
    struct node* start=NULL;

    while(1){
        printf("--- Linked List ---\n1.Create linked list\n2.Display\n3.Selection Sort\n4.Bubble Sort\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice){ 
        case 1:
            start=Create(start);
            break;
        case 2:
            Display(start);
            break;
        case 3:
           SelectionSort(start);
           break;
        case 4:
           BubbleSort(start); 
           break;    
        case 5:
            exit(0);
            break;
        default: 
            break;
        }
    }

    return 0;
}

struct node * Create(struct node* start){
    int n,data;
    start=NULL;
    printf("Enter the no. of elements you want to put in List : ");
    scanf("%d",&n);
    if(n==0){
        printf("Created empty list\n\n");
        return start;
    }
    for(int i=0;i<n;i++){
        printf("Enter the %d element : ",i+1);
        scanf("%d",&data);
        start=AddToEnd(start,data);
    }
    return start;

}

void Display(struct node* start){
    struct node *p=start;
    if(start==NULL){
        printf("List is Empty\n\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n\n");

}

struct node * AddToStart(struct node* start,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}

struct node * AddToEnd(struct node* start,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    struct node *p=start;
    if(start ==NULL){
        start=temp;
        return start;
    }
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=temp;
    return start;

}

void SelectionSort(struct node* start){
        struct node *i,*j;
        int tmp;
        for(i=start;i->link!=NULL;i=i->link){
            for(j=i->link;j!=NULL;j=j->link){
                if(i->info>j->info){
                    tmp=i->info;
                    i->info=j->info;
                    j->info=tmp;
                }
            }
        }
}

void BubbleSort(struct node* start){
    struct node *i,*j,*end;
    int tmp;
    for(end=NULL;end!=start->link;end=j){
        int flag=1;
        for(i=start;i->link!=end;i=i->link){
            j=i->link;
            if(i->info>j->info){
                tmp=i->info;
                i->info=j->info;
                j->info=tmp;
                flag=0;
            }
        }
        if(flag==1){
            break;
        }
    }
}

