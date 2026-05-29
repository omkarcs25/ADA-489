
#include <stdio.h>

#define INF 999

int main()
{
    int n, cost[10][10];
    int visited[10] = {0};
    int ne = 1, mincost = 0;
    int a, b, u, v, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while(ne < n)
    {
        min = INF;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", a, b, min);

        visited[b] = 1;
        mincost += min;
        ne++;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}
