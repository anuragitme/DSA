#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int info;
    struct node* next;
};

struct node * Create(struct node* start);
void Display(struct node* start);
void Search(struct node* start,int item);
struct node * AddToStart(struct node* start,int data);
struct node * AddToEnd(struct node* start,int data);
struct node * AddAfter(struct node* start,int data,int item);
struct node * AddBefore(struct node* start,int data,int item);
struct node * AddAtPos(struct node* start,int data,int pos);
struct node * DeleteFromStart(struct node* start);
struct node * DeleteFromEnd(struct node* start);
struct node * DeleteAfter(struct node* start,int data);
struct node * DeleteBefore(struct node* start,int data);
struct node * DeleteFromPos(struct node* start,int pos);
struct node * DeleteTheData(struct node* start,int item);
void Count(struct node* start);
struct node * Reverse(struct node* start);

int main(){
    int choice,item,data;
    struct node* start=NULL;

    while(1){
        printf("--- Doubly Linked List ---\n1.Create nexted list\n2.Display\n3.Search\n4.Add element at start\n5.Add element at end\n6.Add an element after a number\n7.Add an element before a number\n8.Add at a particular postion\n9.Delete element from start\n10.Delete an element from end\n11.Delete an element after a number\n12.Delete an element before a number\n13.Delete a number from any particular index\n14.Delete a particular data member\n15.Count\n16.Reverse\n17.Exit\n");
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
            printf("Enter the number that you want to search : ");
            scanf("%d",&item);
            Search(start,item);
            break;
        case 4:
            printf("Enter the number that you want to insert at starting : ");
            scanf("%d",&data);
            start=AddToStart(start,data);
            break;
        case 5:
            printf("Enter the number that you want to insert at end : ");
            scanf("%d",&data);
            start=AddToEnd(start,data);
            break;
        case 6:
            printf("Enter the number after which you want to insert : ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            start=AddAfter(start,data,item);
            break;    
        case 7:
            printf("Enter the number before which you want to insert : ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            start=AddBefore(start,data,item);
            break;
        case 8:
            printf("Enter the position where you want to insert a number: ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            start=AddAtPos(start,data,item);
            break;
        case 9:
            start=DeleteFromStart(start);
            break;
        case 10:
            start=DeleteFromEnd(start);
            break;
        case 11:
            printf("Enter the number after which you want to delete an element : ");
            scanf("%d",&data);
            start=DeleteAfter(start,data);
            break;
        case 12:
            printf("Enter the number before which you want to delete an element : ");
            scanf("%d",&data);
            start=DeleteBefore(start,data);
            break;
        case 13:
            printf("Enter the index from where you want to delete an element : ");
            scanf("%d",&item);
            start=DeleteFromPos(start,item);
            break;
        case 14:
            printf("Enter the data that you want to delete : ");
            scanf("%d",&item);
            start=DeleteTheData(start,item);
            break;
        case 15:
            Count(start);
            break;    
        case 16:
            start=Reverse(start);
            break;
        case 17:
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
        p=p->next;
    }
    printf("\n\n");

}

void Search(struct node* start,int item){
    struct node *p=start;
    int pos=1;
    int flag=0;
    while(p!=NULL){
        if(item==p->info){
            printf("%d is found at index = %d\n",item,pos);
            flag=1;
        }
        pos++;
        p=p->next;
    }
    if(flag==0){
        printf("%d is not found in list\n",item);
    }
    printf("\n");

}

struct node * AddToStart(struct node* start,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    temp->next=start;
    temp->prev=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }
    start->prev=temp;
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
        temp->prev=NULL;
        return start;
    }
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=temp;
    temp->prev=p;
    return start;

}

struct node * AddAfter(struct node* start,int data,int item){
    struct node* p=start;
    while(p!=NULL){
        if(p->info==item){
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=p->next;
            if(temp->next!=NULL){
                temp->next->prev=temp;
            }
            temp->prev=p;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    printf("%d is not found in List so %d can't be added\n\n",item,data);
    return start;

}

struct node * AddBefore(struct node* start,int data,int item){
    struct node* p=start;
    if(start==NULL){
        printf("List is empty\n\n");
        return start;
    }
    else if(start->info==item){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=start;
            temp->prev=NULL;
            temp->next->prev=temp;
            start=temp;
            return start;
    }
    while(p->next!=NULL){
        if(p->next->info==item){
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=p->next;
            temp->prev=p;
            temp->next->prev=temp;
            p->next=temp;
            return start;
        }
        p=p->next;
    }
    printf("%d not found in the list\n\n");
    return start;

}

struct node * AddAtPos(struct node* start,int data,int pos){
    int i=1;
    struct node* p=start;
    if (pos==1){
       start= AddToStart(start,data);
       return start;
    }
    for(;p!=NULL && i<pos-1;i++){
        p=p->next;
    }
    if(p==NULL){
        printf("List has less than %d elements\n",pos);
    }
    else{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->next=p->next;
        temp->prev=p;
        if(temp->next!=NULL){
            temp->next->prev=temp;
        }
        p->next=temp;
    }
    printf("\n");
    return start;

}

struct node * DeleteFromStart(struct node* start){
        if(start==NULL){
            printf("List is already empty");
            return start;
        }
        struct node *del=start;
        start=start->next;
        if(start!=NULL){
        start->prev=NULL;
        }
        free(del);
        return start;

}

struct node * DeleteFromEnd(struct node* start){
        struct node *p=start;
        struct node *del=NULL;
        if(start==NULL){
            printf("List is already empty\n\n");
            return start;
        }
        else if(start->next==NULL){
            del=start;
            start=start->next;
            free(del);
            return start;   
        }
        while(p->next->next!=NULL){
            p=p->next;
        }
        del=p->next;
        p->next=NULL;
        free(del);
        return start;
        
}

struct node * DeleteAfter(struct node* start,int data){
        struct node *p=start;
        while(p!=NULL){
            if(p->info==data){
                struct node* del=p->next;
                if(del==NULL){
                    p->next=NULL;
                }
                else{
                    p->next=del->next;
                    if(p->next!=NULL){
                        p->next->prev=p;
                    }
                }
                free(del);
                return start;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n",data);
        return start;

}

struct node * DeleteBefore(struct node* start,int data){
        struct node *p=start;
        if(start==NULL || start->next==NULL || start->info==data ){
            return start;
        }
        else if(start->next->info==data){
            struct node *del=start;
            start=del->next;
            start->prev=NULL;
            free(del);
            return start;
        }
        while(p->next->next!=NULL){
            if(p->next->next->info==data){
                struct node *del=p->next;
                p->next=del->next;
                p->next->prev=p;
                free(del);
                return start;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n",data);
        return start;

}

struct node * DeleteFromPos(struct node* start,int pos){
        struct node *p=start;
        int i=1;
        if(start==NULL){
            printf("List is empty\n");
            return start;
        }
       else if(pos==1){
            struct node * del=start;
            start=del->next;
            if(start!=NULL){
                start->prev=NULL;
            }
            free(del);
            return start;
        }
        for(;i<pos-1 && p!=NULL;i++){
            p=p->next;
        }
        if(p==NULL){
            printf("List has less than %d elements\n",pos);
        }
        else{
            struct node* del=p->next;
            p->next=del->next;
            if(p->next!=NULL){
                p->next->prev=p;
            }
            free(del);
        }
        return start;

}
struct node * DeleteTheData(struct node* start,int item){
        struct node *p=start;
        if(start==NULL){
            printf("List is empty\n");
            return start;
        }
        else if(start->info==item){
            struct node * del=start;
            start=del->next;
            if(start!=NULL){
                start->prev=NULL;
            }
            free(del);
            return start;
        }
        while(p->next!=NULL){
            if(p->next->info==item){
                struct node * del=p->next;
                p->next=del->next;
                if(p->next!=NULL){
                    p->next->prev=p;
                }
                free(del);
                return start;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n");
        return start;
}

void Count(struct node* start){
    struct node * p=start;
    int i=0;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    printf("No. of elemnts in List = %d\n\n",i);

}

struct node * Reverse(struct node* start){
        struct node *pre,*pnt,*next;
        pre=NULL;
        pnt=start;
        while(pnt!=NULL){
            next=pnt->next;
            pnt->prev=next;
            pnt->next=pre;
            pre=pnt;
            pnt=next;
        }
        start=pre;
        return start;
}


