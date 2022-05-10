#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int gt;
int n;

void create_graph();
void warshall(int path[n][n]);
void display();

int main(){
    create_graph();
    int path[n][n];
    warshall(path);
    printf("The path matrix is -->\n");
    display(path);

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

void warshall(int path[n][n]){
    //P(-1)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            path[i][j]=adj[i][j];
        }
    }
    //P(k) where k varied from 0 to n-1
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                path[i][j]=(path[i][j] || (path[i][k] && path[k][j]));
            }
        }
    }
}

void display(int arr[n][n]){
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
