#include <stdio.h>
#include <stdbool.h>


int a[10][10], n, i, j, source;
int visited[10];
int s[10];
int b[10]; 

void createGraph() {
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs() {
    int q[10], front = 0, rear = -1;
    printf("Enter the source vertex to find other reachable nodes: ");
    scanf("%d", &source);
    q[++rear] = source;
    visited[source] = 1;
    printf("The reachable vertices are: ");
    while (front <= rear) {
        int u = q[front++];
        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && visited[i] == 0) {
                q[++rear] = i;
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

void dfs(int source) {
    int v, top = -1;
    s[++top] = 1;
    b[source] = 1;
    for (v = 1; v <= n; v++) {
        if (a[source][v] == 1 && b[v] == 0) {
            printf("%d -> %d\n", source, v);
            dfs(v);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create Graph\n2. BFS\n3. Check graph connectivity (DFS)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                bfs();
                for (i = 1; i <= n; i++) {
                    if (visited[i] == 0) {
                        printf("\nThe vertex that is not reachable: %d\n", i);
                    }
                }
                break;
            case 3:
                printf("Enter the source vertex to find the connectivity: ");
                scanf("%d", &source);
                dfs(source);
                int flag = 1;
                for (i = 1; i <= n; i++) {
                    if (b[i] == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    printf("\nGraph is Connected\n");
                } else {
                    printf("\nGraph is not Connected\n");
                }
                break;
            default:
                return 0;
        }
    }
    return 0;
}
