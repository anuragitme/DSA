#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
};

struct node* insert(struct node* start,int data);
void display(struct node* start);
struct node * Create(struct node* start);
struct node * AddToStart(struct node* start,int data);
struct node * AddToEnd(struct node* start,int data);
struct node * Merge(struct node* start1,struct node* start2);
struct node *insertz(struct node* start,int data);
struct node *mergez(struct node* start1,struct node* start2);

int main(){

    struct node* start1=NULL,*start2=NULL;
    printf("Enter the value for 1st list(sorted)\n");
    start1=Create(start1);
    printf("Enter the value for 2nd list(sorted)\n");
    start2=Create(start2);
    printf("List 1 is => ");
    display(start1);
    printf("List 2 is => ");
    display(start2);
    /*
    start1=Merge(start1,start2);
    printf("Merged list is => ");
    display(start1);
    */
    struct node* newStart=mergez(start1,start2);
    printf("Merged list is => ");
    display(newStart);
    return 0;
}

//Merging methods->
    //1. insert one list to another in sorted way(by creating new or my changing nodes)
    //2. create 3rd list and compare one by one in both list,then add to end
struct node * Merge(struct node* start1,struct node* start2){
    struct node* p=start2,*temp;
    while(p!=NULL){
        start1=insert(start1,p->info);
        temp=p;
        p=p->next;
        free(temp);
    }
    return start1;
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
struct node *mergez(struct node* start1,struct node * start2){
    struct node* p,*temp,*q,*z;
    if(start1==NULL){
        return start2;
    }
    if(start2==NULL){
        return start1;
    }
    if(start1->info<start2->info){
        p=start1;
        q=start2;
    }
    else{
        p=start2;
        q=start1;
    }
    z=p;
    while(q!=NULL){
        temp=q;
        p=insertz(p,q->info);
        q=q->next;
        free(temp);
    }
    return z;
}
struct node *insertz(struct node* start,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;

    struct node* p=start;
    while(p->next!=NULL && p->next->info<data  ){
        p=p->next;
    }
    temp->next=p->next;
    p->next=temp;
    return p;
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
struct node * AddToStart(struct node* start,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    start=temp;
    return start;
}

struct node * AddToEnd(struct node* start,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=NULL;
    struct node *p=start;
    if(start ==NULL){
        start=temp;
        return start;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
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


