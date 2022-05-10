//Adjacency list for directed graph
#include <stdio.h>
#include <stdlib.h>

struct Edge;
struct Vertex{
    int info;
    struct Vertex *nextVertex;
    struct Edge *firstEdge;
};

struct Edge{
    struct Vertex *destVertex;
    struct Edge *nextEdge;
};

struct Vertex *start = NULL;

void insertVertex(int u);
void insertEdge(int u,int v);
void delVertex(int u);
void delEdge(int u,int v);
void delIncomingEdges(int u);
struct Vertex* findVertex(int u);
void display();

int main(){
    int choice,u,v;

    while (1)
    {
        printf("Enter your choice\n");
        printf("1.Insert a vertex\n2.Insert an edge\n3.Delete a vertex\n4.Delete an edge\n5.Display\n6.Exit\n-->");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: printf("Enter a vertex to be inserted\n");
                scanf("%d",&u);
                insertVertex(u);
                break;
        case 2: printf("Enter an edge to be inserted (origin vertex and destination vertex)\n");
                scanf("%d %d",&u,&v);
                insertEdge(u,v);
                break;
        case 3: printf("Enter a vertex to be deleted\n");
                scanf("%d",&u);
                delIncomingEdges(u);
                delVertex(u);
                break;
        case 4: printf("Enter a an edge to be deleted (origin vertex and destination vertex)\n");
                scanf("%d %d",&u,&v);
                delEdge(u,v);
                break;
        case 5: display();
                break;
        case 6: exit(0);
                break;
        default: printf("Invalid choice\n");
            break;
        }

    }

    return 0;
}

void insertVertex(int u){
    struct Vertex* check=findVertex(u);
    if(check!=NULL){
        printf("This vertex is already present\n");
        return;
    }

    struct Vertex* temp=(struct Vertex*)malloc(sizeof(struct Vertex));
    temp->info=u;
    temp->nextVertex=NULL;
    temp->firstEdge=NULL;

    if(start==NULL){
        //it is the first vertex
        start=temp;
    }
    else{
        //insert the new vertex in the end
        struct Vertex* ptr=start;
        while(ptr->nextVertex!=NULL){
            ptr=ptr->nextVertex;
        }
        ptr->nextVertex=temp;
    }

}

void insertEdge(int u,int v){
    struct Vertex* origin=findVertex(u);
    struct Vertex* destin=findVertex(v);
    if(origin==NULL){
        printf("There is no such vertex as %d\n",u);
        return;
    }
    if(destin==NULL){
        printf("There is no such vertex as %d\n",v);
        return;
    }
    int flag=0;
    struct Edge* ptr=origin->firstEdge;

    if(origin->firstEdge==NULL){
       flag=1;
    }
    else{
        while(ptr->nextEdge!=NULL){
            if(ptr->destVertex==destin){
                //if this edge is already present
               return;
            }
            ptr=ptr->nextEdge;
        }
        ptr->nextEdge;
    }

    struct Edge* temp=(struct Edge*)malloc(sizeof(struct Edge));
    temp->destVertex=destin;
    temp->nextEdge=NULL;

    if(flag==1){
        origin->firstEdge=temp;
        return;
    }

    ptr->nextEdge=temp;

}

void delVertex(int u){
    struct Vertex* rVtr=start;
    struct Vertex* delV;
    if(start==NULL){
        printf("There is no vertex as %d",u);
        return;
    }
    if(start->info==u){
        //first vertex is the vertex to be deleted
        start=rVtr->nextVertex;
    }
    else{
        while(rVtr->nextVertex!=NULL){
            if(rVtr->nextVertex->info==u){
                delV=rVtr->nextVertex;
                rVtr->nextVertex=rVtr->nextVertex->nextVertex;
                break;
            }
            rVtr=rVtr->nextVertex;
        }
    }

    if(rVtr->nextVertex==NULL){
        printf("There is no vertex as %d",u);
        return;
    }
    struct Edge* ptr=delV->firstEdge;
    struct Edge* temp;
    // deleting all the edges for this vertex
    while(ptr!=NULL){
        temp=ptr;
        ptr=ptr->nextEdge;
        free(temp);
    }

    free(delV);
}

void delEdge(int u,int v){
    struct Vertex* origin=findVertex(u);
    if(origin==NULL){
        printf("There is such edge\n");
        return;
    }
    struct Edge* ptr=origin->firstEdge;
    if(origin->firstEdge==NULL){
        //there is no edge originated from this vertex
        printf("There is such edge\n");
        return;
    }
    if(origin->firstEdge->destVertex->info==v){
        //if first edge is the edge to be deleted
        origin->firstEdge=ptr->nextEdge;
        free(ptr);
        return;
    }
    while(ptr->nextEdge!=NULL){
        if(ptr->nextEdge->destVertex->info==v){
            struct Edge* del=ptr->nextEdge;
            ptr->nextEdge=del->nextEdge;
            free(del);
            return;
        }
        ptr=ptr->nextEdge;
    }

    printf("There is no such edge\n");
}

void delIncomingEdges(int u){
    struct Vertex* remv=findVertex(u);
    if(remv==NULL){
        return;
    }
    struct Edge* Etr;
    struct Vertex* Vtr=start;
    while(Vtr!=NULL){
        Etr=Vtr->firstEdge;
        if(Vtr->firstEdge==NULL){
            // there are 0 edges outgoing from this vertex
            Vtr=Vtr->nextVertex;
            continue;
        }
        if(Vtr->firstEdge->destVertex==remv){
            //edge to be deleted is the first edge of this vertex;
            struct Edge* tempz=Vtr->firstEdge;
            Vtr->firstEdge=tempz->nextEdge;
            free(tempz);
            Vtr=Vtr->nextVertex;
            continue;
        }
        // edge to be deleted is present after the first position
        while(Etr->nextEdge!=NULL){
            if(Etr->nextEdge->destVertex==remv){
                struct Edge* temp=Etr->nextEdge;
                Etr->nextEdge=temp->nextEdge;
                free(temp);
                break;
            }
            Etr=Etr->nextEdge;
        }
        Vtr=Vtr->nextVertex;
    }
}

struct Vertex* findVertex(int u){
    struct Vertex* ptr=start;
    while(ptr!=NULL){
        if(ptr->info==u){
            return ptr;
        }
        ptr=ptr->nextVertex;
    }
    return NULL;
}

void display(){
    struct Vertex* Vtr=start;
    struct Edge* Etr;
    printf("Graph : --->\n");

    while(Vtr!=NULL){
        Etr=Vtr->firstEdge;
        printf("%d --> ",Vtr->info);
        while(Etr!=NULL){
            printf(" %d ",Etr->destVertex->info);
            Etr=Etr->nextEdge;
        }
        printf("\n");
        Vtr=Vtr->nextVertex;
    }
    printf("\n");
}
