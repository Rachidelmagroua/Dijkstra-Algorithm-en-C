#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define V 5
typedef struct houses{
    int numb;
    int dist;
    int prev;
}houses;
int minDistance(houses allhouses[], bool visited[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && allhouses[v].dist <= min)
        {
            for (int j = v+1; j < V; j++)
            {
                if (allhouses[v].dist > allhouses[j].dist && visited[j] == false)
                {
                    v = j;
                }
            }
            min = allhouses[v].dist; min_index = v;
        }
    }
    return min_index;
}
void printSol(houses allhouses[]){
    printf("Vertex \t\t Distance from Source \t\t Previous house\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d \t\t %d\n", allhouses[i].numb, allhouses[i].dist, allhouses[i].prev);
}
void dijkstra(int graph[V][V], int src){
    houses allhouses[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        allhouses[i].numb = i;
        allhouses[i].dist = INT_MAX;
        allhouses[i].prev = 0;
        visited[i] = false;
    }
    allhouses[src].dist = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minDistance(allhouses,visited);
        visited[u] = true;
        for (int j = 0; j < V; j++)
        {
            if (visited[j] == false && graph[u][j] != 0 && allhouses[u].dist != INT_MAX && allhouses[u].dist + graph[u][j] < allhouses[j].dist)
            {
                allhouses[j].dist = allhouses[u].dist + graph[u][j];
                allhouses[j].prev = u;
            }

        }
    }
    printSol(allhouses);
}
void main(){
    int graph[V][V] = { { 0, 1, 4, 0, 0},
						{ 1, 0, 2, 7, 5},
						{ 4, 2, 0, 0, 2},
						{ 0, 7, 0, 0, 3},
						{ 0, 5, 2, 3, 0}};
    int src;
    printf("entrez source: ");
    scanf("%d",&src);
    printf("\n");
    dijkstra(graph,src);
}