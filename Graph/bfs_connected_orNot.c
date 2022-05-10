#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int state[MAX];
int gt;
int n;

int cqueue[MAX];
int rear=-1,front=-1;

void create_graph();
void bf_traversal();
void bfs(int v);
void insert_queue(int v);
int delete_queue();
int isEmpty_queue();
int isfull_queue();

int main(){

    create_graph();
    bf_traversal();

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
    }

    if(gt==2){
        bfs(0);
        int disconnected=0;
        for(int i=0;i<n;i++){
            if(state[i]==initial){
                disconnected=1;
                break;
            }
        }
        if(disconnected){
            printf("Graph is disconnected\n");
        }
        else{
            printf("Graph is connected\n");
        }
    }
    else{
        int disconnected=0;
        for(int v=0;v<n;v++){
            bfs(v);
            for(int i=0;i<n;i++){
                if(state[i]==initial){
                    disconnected=1;
                    break;
                }
            }
            if(disconnected){
                break;
            }

            for(int i=0;i<n;i++){
                state[i]=initial;
            }
            
        } 
        if(disconnected){
                printf("Graph is disconnected\n");
            }
            else{
                printf("Graph is connected\n");
            }   
    }
    
}
void bfs(int v){
    insert_queue(v);
    state[v]=waiting;
    while(!isEmpty_queue()){
        v=delete_queue();
        state[v]=visited;
        for(int i=0;i<n;i++){
            if(state[i]==initial && adj[v][i]==1){
                state[i]=waiting;
                insert_queue(i);
            }
        }
    }
    printf("\n");
}

void insert_queue(int v){
   if(isfull_queue()){
       printf("Queue overflow\n");
       exit(0);
   }
   if(front==-1){
       front++;
   }
   if(rear==MAX-1){
       rear=-1;
   }
   rear++;
   cqueue[rear]=v;
}

int delete_queue(){
    if(isEmpty_queue()){
        printf("Queue underflow\n");
        exit(0);
    }
    int del_elm=cqueue[front];

    if(rear==front){
        rear=-1;
        front=-1;
        return del_elm;
    }
    if(front==MAX-1){
        front=-1;
    }
    front++;
    return del_elm;
}

int isEmpty_queue(){
   if(front==-1){
       return 1;
   }
   return 0;
}

int isfull_queue(){
    if(rear==front-1 || rear==MAX-1 && front==0){
        return 1;
    }
    return 0;
}