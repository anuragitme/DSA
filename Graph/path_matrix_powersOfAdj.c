#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n;
int gt;

void create_graph();
void initialize_with_adj(int arr[n][n]);
void make_pathMatrix(int x[n][n],int adjp[n][n]);
void display(int arr[n][n]);

int main(){
    
    create_graph();
    int x[n][n];
    int adjp[n][n];
    initialize_with_adj(x);
    initialize_with_adj(adjp);
    make_pathMatrix(x,adjp);
    printf("Adjacency matrix is -->\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Path matrix is -->\n");
    display(x);

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

void initialize_with_adj(int arr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=adj[i][j];
        }
    }
}

void make_pathMatrix(int x[n][n],int adjp[n][n]){
   int sum;
   int temp[n][n];
   for(int t=1;t<n;t++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum=0;
            for(int k=0;k<n;k++){
               sum+=(adjp[i][k]*adj[k][j]);
            }
            temp[i][j]=sum;
            x[i][j]+=sum;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adjp[i][j]=temp[i][j];
        }
    }
   }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j]!=0){
                x[i][j]=1;
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