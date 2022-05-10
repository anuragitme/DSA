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
int predecessor[MAX];
int time=0;
int gt;
int n;
int cycle=0;

void create_graph();
void dfs_directed(int v);
void dfs_undirected(int v);
void display_time();
void detect_cycle();

int main(){

    create_graph();
    detect_cycle();
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

void detect_cycle(){
    for(int i=0;i<n;i++){
        state[i]=initial;
    }
    
    if(gt==1){
        dfs_directed(0);
        for(int i=0;i<n;i++){
            if(cycle==1){
                break;
            }
            if(state[i]==initial){
                dfs_directed(i);
            }
        }
    }
    else{
        dfs_undirected(0);
        for(int i=0;i<n;i++){
            if(cycle==1){
                break;
            }
            if(state[i]==initial){
                dfs_undirected(i);
            }
        }
    }
    if(cycle){
        printf("The graph is Cyclic\n");
    }
    else{
        printf("The graph is Acyclic\n");
    }

}

void dfs_directed(int v){
    time++;
    d[v]=time;
    state[v]=visited;
   
    for(int i=0;i<n;i++){
        if(adj[v][i]==1){
            if(state[i]==initial){
                dfs_directed(i);
            }
            else if(state[i]==visited){
                cycle=1;
                return;
            }
        }
        if(cycle==1){
            return;
        }
    }
    time++;
    f[v]=time;
    state[v]=finished;
}

void dfs_undirected(int v){
    time++;
    d[v]=time;
    state[v]=visited;
   
    for(int i=0;i<n;i++){
       if(adj[v][i]==1){
           if(state[i]==initial){
               predecessor[i]=v;
               dfs_undirected(i);
           }
           else if(state[i]==visited && predecessor[v]!=i){
               cycle=1;
               return;
           }
       }
       if(cycle==1){
           return;
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

