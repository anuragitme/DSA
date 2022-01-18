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
struct node* SelectionSort(struct node* start);
struct node* BubbleSort(struct node* start);


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
            start= SelectionSort(start);
            break;
        case 4:
          start= BubbleSort(start); 
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

struct node* SelectionSort(struct node* start){
        if(start==NULL){
            return start;
        }
        struct node *i,*a=NULL,*j,*b,*temp;
        for(i=start;i->link!=NULL;i=i->link){
            for(j=i->link,b=i;j!=NULL;j=j->link){
                if(i->info>j->info){
                    if(a!=NULL){
                        a->link=j;
                    }
                    else{
                        start=j;
                    }
                    b->link=i;
                    temp=j->link;
                    j->link=i->link;
                    i->link=temp;
                    temp=i;
                    i=j;
                    j=temp;
                }
            }
            a=i;
            b=j;
        }
        return start;
}

struct node* BubbleSort(struct node* start){
    struct node *i,*a,*j,*end,*temp;
    if(start==NULL){
        return start;
    }
    for(end=NULL;end!=start->link;end=j){
        int flag=1;
        a=NULL;
        for(i=start;i->link!=end;i=i->link){
            j=i->link;
            if(i->info>j->info){
                if(a!=NULL){
                    a->link=j;
                }
                else{
                    start=j;
                }
                i->link=j->link;
                j->link=i;
                temp=i;
                i=j;
                j=temp;
                flag=0;
            }
            a=i;
        }
        if(flag==1){
            break;
        }
    }
    return start;
}

