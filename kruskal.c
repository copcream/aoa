#include <stdio.h>

int parent[20];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void uni(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, cost[20][20], i, j, a, b, u, v, min, mincost = 0, edges = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");
    while (edges < n) {
        min = 999;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        uni(u, v);
        printf("%d edge (%d,%d) = %d\n", edges++, a, b, min);
        mincost += min;
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMin cost = %d\n", mincost);
    return 0;
}
