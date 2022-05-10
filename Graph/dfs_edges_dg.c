#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define initial 1
#define visited 2
#define finished 3

int adj[MAX][MAX];
int state[MAX];
int d[MAX];
int f[MAX];
int time=0;
int n;

void create_graph();
void df_traversal();
void dfs(int v);
void display_time();

int main(){

    create_graph();
    df_traversal();
    //display_time();
    return 0;
}

void create_graph(){
        int max_edges, i, origin, destin;
        printf("Enter the number of vertices in graph : ");
        scanf("%d",&n);
        max_edges = n * (n - 1);

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
    dfs(v);
    printf("\n");
    for(int i=0;i<n;i++){
        if(state[i]==initial){
            dfs(i);
            printf("\n");
        }
    }
}

void dfs(int v){
    time++;
    d[v]=time;
    state[v]=visited;
   
    for(int i=0;i<n;i++){
        if(adj[v][i]==1){
            if(state[i]==initial){
                printf("Tree Edge : %d --> %d\n",v,i);
                dfs(i);
            }
            else if(state[i]==visited){
                printf("Back Edge : %d --> %d\n",v,i);
            }
            else if(d[v]<d[i]){
                printf("Forward Edge : %d --> %d\n",v,i);
            }
            else{
                printf("Cross Edge : %d --> %d\n",v,i);
            }
        }
    }
    time++;
    f[v]=time;
    state[v]=finished;
}

void display_time(){
    printf("Vertex : Discovery Time --> Finished Time\n");
    for(int i=0;i<n;i++){
        if(state[i]==finished){
            printf("%d : %d --> %d\n",i,d[i],f[i]);
        }
    }
    printf("\n");
}
