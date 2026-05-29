#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX], dist[MAX];
    int visited[MAX];
    int n, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(int i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int count = 1; count < n - 1; count++)
    {
        int min = INF, nextnode;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i] &&
               min + cost[nextnode][i] < dist[i])
            {
                dist[i] = min + cost[nextnode][i];
            }
        }
    }

    printf("\nShortest Distances:\n");

    for(int i = 0; i < n; i++)
    {
        if(i != source)
            printf("%d -> %d = %d\n",
                   source, i, dist[i]);
    }

    return 0;
}
