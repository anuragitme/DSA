#include<stdio.h>
#include<stdlib.h>

struct node{
    int exp;
    float coef;
    struct node* next;
};

struct node * Create(struct node* start);
struct node * insert(struct node* start,int iexp,float icoef);
void Display(struct node* start);
void polynomialADD(struct node* poly1,struct node* poly2);
void polynomialMULTIPLY(struct node* poly1,struct node* poly2);


int main(){
    struct node* poly1=NULL,*poly2=NULL;
    printf("Enter the first polynomial\n");
    poly1= Create(poly1);
    printf("Enter the second polynomial\n");
    poly2= Create(poly2);
    printf("Polynomial 1 is = ");
    Display(poly1);
    printf("Polynomial 2 is = ");
    Display(poly2);
    polynomialADD(poly1,poly2);
    polynomialMULTIPLY(poly1,poly2);
    return 0;
}

struct node * Create(struct node* start){
    int n;
    int e;
    float c;
    printf("Enter the no. of terms that you want to add : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the exponent(%d term) = ",i+1);
        scanf("%d",&e);
        printf("Enter the coeficient(%d term) = ",i+1);
        scanf("%f",&c);
        start= insert(start,e,c);
    }
    return start;
}
struct node * insert(struct node* start,int iexp,float icoef){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->exp=iexp;
    temp->coef=icoef;
    if(start==NULL || start->exp<iexp){
        temp->next=start;
        start=temp;
        return start;
    }
    if(start->exp==iexp){
        start->coef=start->coef+icoef;
        return start;
    }
    struct node*p=start;
    while(p->next!=NULL && p->next->exp>iexp ){
        p=p->next;
    }
    if(p->next!=NULL && p->next->exp==iexp){
        p->next->coef=p->next->coef+icoef;
        free(temp);
        return start;
    }
    temp->next=p->next;
    p->next=temp;

    return start;
}

void Display(struct node* start){
    if(start==NULL){
        printf("Zero Polynomial\n");
        return;
    }
    struct node* p=start;
    while(p!=NULL){
        if(!(p==start) && p->coef>=0){
            printf(" +");
        }
        printf(" %0.1fx^%d",p->coef,p->exp);
        p=p->next;
    }
    printf("\n");
}

void polynomialADD(struct node* poly1,struct node* poly2){
    struct node* poly3=NULL,*p=poly1,*q=poly2;
    while(p!=NULL && q!=NULL){
        if(p->exp>q->exp){
           poly3= insert(poly3,p->exp,p->coef);
           p=p->next;
        }
        else if(p->exp<q->exp){
           poly3= insert(poly3,q->exp,q->coef);
           q=q->next;
        }
        else{
            poly3=insert(poly3,p->exp,p->coef+q->coef);
            p=p->next;
            q=q->next;
        }
    }
    while(p!=NULL){
        poly3= insert(poly3,p->exp,p->coef);
        p=p->next;
    }
    while(q!=NULL){
        poly3= insert(poly3,q->exp,q->coef);
        q=q->next;
    }
    printf("Added polynomial => ");
    Display(poly3);

}

void polynomialMULTIPLY(struct node* poly1,struct node* poly2){
    struct node* poly4=NULL,*p=poly1,*q=poly2;
    if(p==NULL || q==NULL){
        Display(poly4);
        return;
    }
    while(p!=NULL){
        q=poly2;
        while(q!=NULL){
            poly4=insert(poly4,p->exp+q->exp,p->coef*q->coef);
            q=q->next;
        }
        p=p->next;
    }
    printf("Multipied Polynomial is => ");
    Display(poly4);
}
