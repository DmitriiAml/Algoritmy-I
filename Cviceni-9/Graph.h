#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node();
    ~Node();

    int GetValue();
    void SetValue(int value);
    int GetInDegree();
    void SetInDegree(int value);
    vector<Node*>& GetNeighbours();
    void Reset();

private:
    int _value;
    vector<Node*> _neighbours;
    int _inDegree;
};

class Graph {
public:
    Graph();
    ~Graph();

    bool LoadData(string inputPath);
    void UpdateInDegrees();
    void ReportInDegrees();
    vector<Node*> ComputeTopologicalSorting(bool& success);
    vector<Node*>& GetNodes();
    void Reset();

private:
    vector<Node*> _nodes;
    void FreeMemory();
};