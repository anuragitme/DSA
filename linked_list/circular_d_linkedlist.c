#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* next;
    struct node* prev;
};

struct node * Create(struct node* last);
void Display(struct node* last);
void Search(struct node* last,int item);
struct node * AddToStart(struct node* last,int data);
struct node * AddToEnd(struct node* last,int data);
struct node * AddAfter(struct node* last,int data,int item);
struct node * AddBefore(struct node* last,int data,int item);
struct node * AddAtPos(struct node* last,int data,int pos);
struct node * DeleteFromStart(struct node* last);
struct node * DeleteFromEnd(struct node* last);
struct node * DeleteAfter(struct node* last,int data);
struct node * DeleteBefore(struct node* last,int data);
struct node * DeleteFromPos(struct node* last,int pos);
struct node * DeleteTheData(struct node* last,int item);
void Count(struct node* last);
struct node * Reverse(struct node* last);

int main(){
    int choice,item,data;
    struct node* last=NULL;

    while(1){
        printf("--- Doubly-Circular Linked List ---\n1.Create linked list\n2.Display\n3.Search\n4.Add element at Start\n5.Add element at end\n6.Add an element after a number\n7.Add an element before a number\n8.Add at a particular postion\n9.Delete element from Start\n10.Delete an element from end\n11.Delete an element after a number\n12.Delete an element before a number\n13.Delete a number from any particular index\n14.Delete a particular data member\n15.Count\n16.Reverse\n17.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch (choice){ 
        case 1:
            last=Create(last);
            break;
        case 2:
            Display(last);
            break;
        case 3:
            printf("Enter the number that you want to search : ");
            scanf("%d",&item);
            Search(last,item);
            break;
        case 4:
            printf("Enter the number that you want to insert at starting : ");
            scanf("%d",&data);
            last=AddToStart(last,data);
            break;
        case 5:
            printf("Enter the number that you want to insert at end : ");
            scanf("%d",&data);
            last=AddToEnd(last,data);
            break;
        case 6:
            printf("Enter the number after which you want to insert : ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            last=AddAfter(last,data,item);
            break;    
        case 7:
            printf("Enter the number before which you want to insert : ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            last=AddBefore(last,data,item);
            break;
        case 8:
            printf("Enter the position where you want to insert a number: ");
            scanf("%d",&item);
            printf("Enter the number that you want to insert : ");
            scanf("%d",&data);
            last=AddAtPos(last,data,item);
            break;
        case 9:
            last=DeleteFromStart(last);
            break;
        case 10:
            last=DeleteFromEnd(last);
            break;
        case 11:
            printf("Enter the number after which you want to delete an element : ");
            scanf("%d",&data);
            last=DeleteAfter(last,data);
            break;
        case 12:
            printf("Enter the number before which you want to delete an element : ");
            scanf("%d",&data);
            last=DeleteBefore(last,data);
            break;
        case 13:
            printf("Enter the index from where you want to delete an element : ");
            scanf("%d",&item);
            last=DeleteFromPos(last,item);
            break;
        case 14:
            printf("Enter the data that you want to delete : ");
            scanf("%d",&item);
            last=DeleteTheData(last,item);
            break;
        case 15:
            Count(last);
            break;    
        case 16:
            last=Reverse(last);
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

struct node * Create(struct node* last){
    int n,data;
    last=NULL;
    printf("Enter the no. of elements you want to put in List : ");
    scanf("%d",&n);
    if(n==0){
        printf("Created empty list\n\n");
        return last;
    }
    for(int i=0;i<n;i++){
        printf("Enter the %d element : ",i+1);
        scanf("%d",&data);
        last=AddToEnd(last,data);
    }
    return last;

}

void Display(struct node* last){
    
    if(last==NULL){
        printf("List is Empty\n\n");
        return;
    }
    struct node *p=last->next;
    do{
        printf("%d ",p->info);
        p=p->next;
    }while(p!=last->next);
    printf("\n\n");

}

void Search(struct node* last,int item){
    struct node *p=last->next;
    int pos=1;
    int flag=0;
    if(last==NULL){
        printf("List is empty\n\n");
        return;
    }
    do{
        if(item==p->info){
            printf("%d is found at index = %d\n",item,pos);
            flag=1;
        }
        pos++;
        p=p->next;
    }while(p!= last->next);
    if(flag==0){
        printf("%d is not found in list\n",item);
    }
    printf("\n");

}

struct node * AddToStart(struct node* last,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    if(last==NULL){
        last=temp;
        last->next=temp;
        last->prev=temp;
        return last;
    }
    temp->next=last->next;
    temp->prev=last;
    temp->next->prev=temp;
    last->next=temp;
    return last;
}

struct node * AddToEnd(struct node* last,int data){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->info=data;
    struct node *p=last;
    if(last ==NULL){
        last=temp;
        last->next=temp;
        last->prev=temp;
        return last;
    }
    temp->next=last->next;
    temp->prev=last;
    last->next=temp;
    temp->next->prev=temp;
    last=temp;
    return last;

}

struct node * AddAfter(struct node* last,int data,int item){
    struct node* p=last;
    if(last==NULL){
        printf("List is empty\n\n");
        return last;
    }
    do{
        if(p->info==item){
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
            temp->next->prev=temp;
            if(p==last){
                last=temp;
            }
            return last;
        }
        p=p->next;
    }while(p!=last);

    printf("%d is not found in List so %d can't be added\n\n",item,data);
    return last;

}

struct node * AddBefore(struct node* last,int data,int item){
    if(last==NULL){
        printf("List is empty\n\n");
        return last;
    }
    struct node* p=last->next;
    if(last->next->info==item){
        struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=last->next;
            temp->next->prev=temp;
            temp->prev=last;
            last->next=temp;
            return last;
    }
    while(p->next!=last->next){
        if(p->next->info==item){
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=data;
            temp->next=p->next;
            temp->prev=p;
            temp->next->prev=temp;
            p->next=temp;
            return last;
        }
        p=p->next;
    }
    printf("%d not found in the list\n\n");
    return last;

}

struct node * AddAtPos(struct node* last,int data,int pos){
    int i=1;
    if (pos==1){
       last= AddToStart(last,data);
       return last;
    }
    if(last==NULL){
        printf("List has less than %d elements\n",pos);
        return last;
    }
    struct node* p=last->next;
    for(;p->next!=last->next && i<pos-1;i++){
        p=p->next;
    }
    if(i==pos-1 && p->next==last->next){
        last=AddToEnd(last,data);
    }
    else if(p->next==last->next){
        printf("List has less than %d elements\n",pos);
    }
    else{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->info=data;
        temp->next=p->next;
        temp->prev=p;
        temp->next->prev=temp;
        p->next=temp;
    }
    printf("\n");
    return last;

}

struct node * DeleteFromStart(struct node* last){
        if(last==NULL){
            printf("List is already empty");
            return last;
        }
        struct node *del=last->next;
        if(last==last->next){
            free(del);
            last=NULL;
            return last;
        }
        last->next=del->next;
        last->next->prev=last;
        free(del);
        return last;
}

struct node * DeleteFromEnd(struct node* last){
        if(last==NULL){
            printf("List is already empty\n\n");
            return last;
        }
        struct node *del=last;
        struct node *p=last->prev;
        if(p==del){
            free(del);
            return NULL;
        }
        p->next=del->next;
        last=p;
        p->next->prev=p;
        free(del);
        
        return last;
        
}

struct node * DeleteAfter(struct node* last,int data){
        if(last==NULL || last->next==last){
            printf("Nothing to delete\n");
            return last;
        }
        struct node* p=last->next;
        if(data==last->info){
            last=DeleteFromStart(last);
            return last;
        }
        while(p->next!=last->next){
            if(p->info==data){
                struct node* del=p->next;
                p->next=del->next;
                p->next->prev=p;
                if(del==last){
                    last=p;
                } 
                free(del);
                return last;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n",data);
        return last;

}

struct node * DeleteBefore(struct node* last,int data){
        if(last==NULL || last->next==last){
            printf("Nothing to delete\n");
            return last;
        }
        struct node *p=last->next;
        if(p->next->info==data){
            last=DeleteFromStart(last);
            return last;
        }
        
        while(p->next->next!=last->next->next){
            if(p->next->next->info==data){
                struct node* del=p->next;
                p->next=del->next;
                p->next->prev=p;
                if(del==last){
                    last=p;
                }
                free(del);
                return last;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n",data);
        return last;

}

struct node * DeleteFromPos(struct node* last,int pos){
        struct node *p=last;
        int i=1;
        if(last==NULL){
            printf("List is empty\n");
            return last;
        }
       else if(pos==1){
            struct node * del=last->next;
            last->next=del->next;
            last->next->prev=last;
            if(del==del->next){
                last=NULL;
            }
            free(del);
            return last;
        }
        p=p->next;
        for(;i<pos-1 && p->next!=last->next;i++){
            p=p->next;
        }
        if(p->next==last->next){
            printf("List has less than %d elements\n",pos);
        }
        else{
            struct node* del=p->next;
            p->next=del->next;
            p->next->prev=p;
            if(del==last){
                last=p;
            }
            free(del);
        }
        return last;

}
struct node * DeleteTheData(struct node* last,int item){
        struct node *p=last;
        if(last==NULL){
            printf("List is empty\n");
            return last;
        }
        p=p->next;
        if(p->info==item){
            last=DeleteFromStart(last);
            return last;
        }
        while(p->next!=last->next){
            if(p->next->info==item){
                struct node * del=p->next;
                p->next=del->next;
                p->next->prev=p;
                if(del==last){
                    last=p;
                }
                free(del);
                return last;
            }
            p=p->next;
        }
        printf("%d not found in the list\n\n");
        return last;
}

void Count(struct node* last){
    struct node * p=last;
    int i=1;
    if(p==NULL){
        printf("0\n\n");
        return;
    }
    while(p->next!=last){
        p=p->next;
        i++;
    }
    printf("No. of elemnts in List = %d\n\n",i);

}

struct node * Reverse(struct node* last){
        struct node *p=last->next,*temp;
        if(last==NULL || last->next==last){
            return last;
        }
        while(p!=last){
            temp=p->next;
            p->next=p->prev;
            p->prev=temp;
            p=temp;
        }
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        last=last->prev;
        return last;
}


