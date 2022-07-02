// Program to implement linear search recursively
#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n, int startNode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX], visited[MAX], count, minDistance, nextNode,i,j;
    // pred stores the predecessor of each  node
    // count gives the number of nodes seen so far
    // create the cost matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(G[i][j] == 0)
            {
                cost[i][j] = INFINITY;
            }   
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }
    // initialize pred[], distance[] and visited[]
    for (int i = 0; i < n; i++)
    {
        distance[i]=cost[startNode][i];
        pred[i] = startNode;
        visited[i] = 0;
    }
    distance[startNode] = 0;
    visited[startNode] = 1;
    count = 1;
    while (count < n-1)
    {
        minDistance =  INFINITY;
        // nextNode gives the node at minimum distance
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < minDistance &&! visited[i])
                {
                    minDistance = distance[i];
                    nextNode = i;
                }
        }
        // check if a better path exists through nextNode
        visited[nextNode] = 1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (minDistance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = minDistance + cost[nextNode][i];
                    pred[i] = nextNode;
                }     
            }
        }
        count++;
    }
    // print the path and distance of each 
    for (int i = 0; i < n; i++)
    {
        if (i != startNode)
        {
            printf("Distance of node %d = %d \n",i ,distance[i]);
            printf("Path = %d",i);
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d",j);
            }
            while (j != startNode);
        }
    } 
}

int main()
{
    int G[MAX][MAX], n, u;
    printf("Enter the no. vertices \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    printf("Enter the starting node\n");
    scanf("%d",&u);
    dijkstra(G, n, u);
    return 0;
}
