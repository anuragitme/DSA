#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define nil -1
#define infinity 99999

int adj[MAX][MAX];
int state[MAX];
int predecessor[MAX];
int distance[MAX];
int gt;
int n;

int queue[MAX];
int rear=-1,front=-1;

void create_graph();
void bf_traversal();
void bfs(int v);
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();

int main(){

    create_graph();
    bf_traversal();
    int x,path[n],p=-1;
    while(1){
        printf("Enter the destination vertex (-1 to quit): ");
        scanf("%d",&x);
        if(x==-1){
            break;
        }
        if(x<-1 || x>=n){
            printf("INvalid vertex\n");
            continue;
        }
        printf("Shortest distance form starting to destination vertex is --> %d\n",distance[x]);
        printf("The shorest path is -->\n");
        while(predecessor[x]!=nil){
            p++;
            path[p]=x;
            x=predecessor[x];
        }
        printf("%d ",x);
        for(int i=p;i>=0;i--){
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    return 0;
}

void create_graph(){
        int max_edges, i, origin, destin;
        int graph_type;
        printf("Choose graph type\n1.Directed Graph\n2.Undirected Graph\n--> ");
        scanf("%d",&graph_type);
        gt=graph_type;
        printf("Enter the number of vertices in graph : ");
        scanf("%d",&n);
        while (1){
                int flag=0;
                switch (graph_type){
                case 1:
                        max_edges = n * (n - 1);
                        flag=1;
                        break;
                case 2:
                        max_edges = n * (n - 1) / 2;
                        flag=1;
                        break;
                default:
                        printf("Invalid Graph type\n");
                        exit(0);
                }
                if(flag==1) break;
        }

        for (i = 0; i < max_edges; i++){

                printf("Enter edge ( %d %d to quit) :", -1, -1);
                scanf("%d %d", &origin, &destin);

                if (origin == -1 && destin == -1){
                        break;
                }
                else if (origin < 0 || origin >= n || destin < 0 || destin >= n){
                        i--;
                        printf("Invalid edge\n");
                        continue;
                }
                else{
                        adj[origin][destin] = 1;
                        if (graph_type == 2)
                        {
                                adj[destin][origin] = 1;
                        }
                }
        }
}

void bf_traversal(){
    int v;
    //making every vetex as initial state
    for(int i=0;i<n;i++){
        state[i]=initial;
        predecessor[i]=nil;
        distance[i]=infinity;
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&v);
    if(v<0 || v>=n){
        printf("Invalid vertex\n");
        return;
    }
    bfs(v);
}
void bfs(int v){
    insert_queue(v);
    state[v]=waiting;
    distance[v]=0;
    while(!isEmpty_queue()){
        v=delete_queue();
        state[v]=visited;
        //printf("%d ",v);
        for(int i=0;i<n;i++){
            if(state[i]==initial && adj[v][i]==1){
                state[i]=waiting;
                insert_queue(i);
                distance[i]=distance[v]+1;
                predecessor[i]=v;
                
            }
        }
    }
    printf("\n");
}

void insert_queue(int v){
    if(rear==MAX-1){
        printf("Queue overflow\n");
        exit(0);
    }
    rear++;
    queue[rear]=v;
    if(front==-1){
        front++;
    }
}

int delete_queue(){
    if(isEmpty_queue()){
        printf("Queue underflow\n");
        exit(0);
    }
    int del_elm=queue[front];
    front++;
    return del_elm;
}

int isEmpty_queue(){
    if(front==-1 || rear<front){
        return 1;
    }
    return 0;
}