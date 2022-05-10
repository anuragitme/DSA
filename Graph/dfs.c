#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define visited 2

int adj[MAX][MAX];
int state[MAX];
int gt;
int n;

int stack[MAX];
int top=-1;


void create_graph();
void df_traversal();
void dfs(int v);
void push_stack(int v);
int pop_stack();
int isFull_stack();
int isEmpty_stack();

int main(){

    create_graph();
    df_traversal();

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

void df_traversal(){
    for(int i=0;i<n;i++){
        state[i]=initial;
    }
    int v;
    printf("Enter the starting vertex for dfs : ");
    scanf("%d",&v);
    if(v<0 || v>=n){
        printf("Invalid vertex\n");
        return;
    }
    printf("DFS traversal -->\n");
    dfs(v);
}

void dfs(int v){
    push_stack(v);
    while(!isEmpty_stack()){
        v=pop_stack();
        if(state[v]==initial){
            printf("%d ",v);
        }
        state[v]=visited;
        
        for(int i=0;i<n;i++){
            if(state[i]==initial && adj[v][i]){
                push_stack(i);
            }
        }
    }
    printf("\n");
}

void push_stack(int v){
    if(isFull_stack()){
        printf("Stack overflow\n");
        exit(0);
    }
    top++;
    stack[top]=v;
}

int pop_stack(){
    if(isEmpty_stack()){
        printf("Stack underflow\n");
        exit(0);
    }
    int del_val=stack[top];
    top--;
    return del_val;
}

int isFull_stack(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty_stack(){
    if(top==-1){
        return 1;
    }
    return 0;
}



