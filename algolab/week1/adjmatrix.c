
#include<stdio.h>
#include<stdlib.h>
#define max 20
int adj[max][max];
int n;
void create_graph() {
    int i, max_edges, origin, destin;

    printf("Enter number of nodes : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);

    for (i = 1; i <= max_edges; i++) {
        printf("Enter edge %d( 0 0 ) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;
        } else
            adj[origin][destin] = 1;
    }
}

void display() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

void insert_node() {
    int i;
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 1; i <= n; i++) {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
}

void main() {
    int choice;
    int node, origin, destin;
    create_graph();
    while (1) {
        printf("1.Insert a node\n");
        printf("2.Dispaly\n");
        printf("3.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insert_node();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }

}
