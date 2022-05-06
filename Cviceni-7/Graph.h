#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <sstream>

#pragma once
class Edge
{
public:
    Edge();
    Edge(int from, int to);
    int GetFrom();
    int GetTo();
    float GetWeight();
    void SetFrom(int from);
    void SetTo(int to);
    void SetWeight(float weight);
private:
    int _from;
    int _to;
    float _weight;
};

class Graph
{
public:
    Graph();
    ~Graph();
    bool LoadData(std::string inputPath);
    int* ComputeNodeDegrees();
    void PrintAllNeighbours();
    void PrintNodeNeighbours(int node);
    float ComputeAverageNodeDegree();
    int GetNodeCount();
    int GetNodeWithMaxDegree();
private:
    std::vector<Edge> _edges;
    int _nodeCount;
    int* _adjacencyMatrix;
};