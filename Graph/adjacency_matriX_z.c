#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int adj[MAX][MAX];
int n;
int gt;

void create_graph();
void display();
void insert_edge();
void del_edge();


int main(){
    int choice;
    create_graph();
    while(1){
        printf("Enter your choice\n");
        printf("1.Insert an edge\n2.Delete an edge\n3.Display\n4.Quit\n-->");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_edge();
                    break;
            case 2: del_edge();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default : printf("Invalid choice\n");
                   
        }
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

void display(){
    printf("\n");
        printf("The adjacency matrix : \n");
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++)
                {
                        printf("%4d",adj[i][j]);
                }
                printf("\n");
        }
}

void insert_edge(){
    int origin,destin;
    printf("Enter origin vertex and destination vertex : ");
    scanf("%d %d",&origin,&destin);
    if(origin < 0 || origin >= n || destin < 0 || destin >= n){
        printf("There is no such vertex/vertices\n");
        return;
    }
    adj[origin][destin]=1;
    if(gt==2){
        adj[destin][origin]=1;
    }
    
}

void del_edge(){
    int origin,destin;
    printf("Enter origin vertex and destination vertex : ");
    scanf("%d %d",&origin,&destin);
    if(origin < 0 || origin >= n || destin < 0 || destin >= n){
        printf("This edge does not exist\n");
        return;
    }
    adj[origin][destin]=0;
    if(gt==2){
        adj[destin][origin]=0;
    }
}
