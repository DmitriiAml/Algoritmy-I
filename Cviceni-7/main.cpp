#include <stdio.h>
#include "Graph.h"

int main()
{
    Graph g;
    std::string filePath = "input.txt";
    g.LoadData(filePath);
    printf("\n");
    g.PrintAllNeighbours();
    int* tmp = g.ComputeNodeDegrees();
    printf("\n");
    for (int i = 0; i < g.GetNodeCount(); i++)
    {
        printf("Uzel = %d a jeho stupen je =  %d\n", i, tmp[i]);
    }
    printf("\nNejvyssi stupen ma uzel: %d\n", g.GetNodeWithMaxDegree());
    printf("\nPrumerny stupen je: %.3f\n", g.ComputeAverageNodeDegree());
    
    getchar();
    return 0;
}
