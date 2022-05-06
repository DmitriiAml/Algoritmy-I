#include "Graph.h"

Edge::Edge() : Edge(0, 0)
{
}

Edge::Edge(int from, int to)
{
    this->_from = from;
    this->_to = to;
    this->_weight = 1.0;
}

int Edge::GetFrom()
{
    return this->_from;
}

int Edge::GetTo()
{
    return this->_to;
}

float Edge::GetWeight()
{
    return this->_weight;
}

void Edge::SetFrom(int from)
{
    this->_from = from;
}

void Edge::SetTo(int to)
{
    this->_to = to;
}

void Edge::SetWeight(float weight)
{
    this->_weight = weight;
}

Graph::Graph()
{
    this->_nodeCount = 0;
    this->_adjacencyMatrix = nullptr;
}

Graph::~Graph()
{
    delete[] this->_adjacencyMatrix;
}

bool Graph::LoadData(std::string inputPath)
{
    std::ifstream file(inputPath);

    if (!file.is_open())
    {
        printf("File not found\n");
        return false;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream tokenStream(line);
        std::string token;
        int from, to;
        std::getline(tokenStream, token, ',');
        from = std::stoi(token);
        std::getline(tokenStream, token, ',');
        to = std::stoi(token);
        this->_edges.push_back(Edge(from, to));
    }

    std::set<int> uniqueNodes;

    for (Edge& e : this->_edges)
    {
        //printf("%d -> %d\n", e.GetFrom(), e.GetTo());
        uniqueNodes.insert(e.GetFrom());
        uniqueNodes.insert(e.GetTo());
    }

    this->_nodeCount = uniqueNodes.size();
    printf("Nodes %d; Edges: %d\n", this->_nodeCount, this->_edges.size());

    this->_adjacencyMatrix = new int[this->_nodeCount * this->_nodeCount];
    for (size_t i = 0; i < this->_nodeCount * this->_nodeCount; i++)
    {
        this->_adjacencyMatrix[i] = 0;
    }

    for (Edge& e : this->_edges)
    {
        int from = e.GetFrom();
        int to = e.GetTo();
        this->_adjacencyMatrix[from * this->_nodeCount + to] = 1;
        this->_adjacencyMatrix[to * this->_nodeCount + from] = 1;
    }

    for (size_t i = 0; i < this->_nodeCount; i++)
    {
        for (size_t j = 0; j < this->_nodeCount; j++)
        {
            printf("%d ", this->_adjacencyMatrix[i * this->_nodeCount + j]);
        }
        printf("\n");
    }


    file.close();
    return true;
}

int* Graph::ComputeNodeDegrees()
{
    int* tmp = new int[this->_nodeCount];
    int count = 0;
    for (int i = 0; i < this->_nodeCount; i++)
    {
        for (int j = 0; j < this->_nodeCount; j++)
        {
            if (this->_adjacencyMatrix[i * this->_nodeCount + j] == 1)
            {
                count++;
            }
        }
        tmp[i] = count;
        count = 0;
    }
    return tmp;
}

void Graph::PrintAllNeighbours()
{
    for (int i = 0; i < this->_nodeCount; i++)
    {
        printf("Current node: %d -> ", i);
        for (int j = 0; j < this->_nodeCount; j++)
        {
            if (this->_adjacencyMatrix[i * this->_nodeCount + j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

float Graph::ComputeAverageNodeDegree()
{
    int* tmp = this->ComputeNodeDegrees();
    float count = 0;
    for (int i = 0; i < this->_nodeCount; i++)
    {
        count = count + tmp[i];
    }
    delete[] tmp;
    return (count / (float)this->_nodeCount);
}

int Graph::GetNodeWithMaxDegree()
{
    int* tmp = this->ComputeNodeDegrees();
    int max = 0;
    int res = 0;
    for (int i = 0; i < this->_nodeCount; i++)
    {
        if (max < tmp[i])
        {
            max = tmp[i];
            res = i;
        }
    }
    delete[] tmp;
    return res;
}

int Graph::GetNodeCount()
{
    return this->_nodeCount;
}