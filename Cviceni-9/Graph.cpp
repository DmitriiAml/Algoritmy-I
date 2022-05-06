#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

#include "Graph.h"

using namespace std;

Graph::Graph() {}

Graph::~Graph() {
    FreeMemory();
}

bool Graph::LoadData(string inputPath) {

    ifstream path(inputPath);
    if (!path.is_open()) {
        return false;
    }

    string line;
    getline(path, line);
    int n_vertexes = stoi(line);

    for (int i = 0; i < n_vertexes; i++) {
        Node* node = new Node();
        node->SetValue(i);
        _nodes.push_back(node);
    }

    while (getline(path, line)) {
        istringstream tokenStream(line);
        string token;
        int from, to;
        getline(tokenStream, token, ',');
        from = stoi(token);
        getline(tokenStream, token, ',');
        to = stoi(token);

        _nodes.at(from)->GetNeighbours().push_back(_nodes.at(to));
    }

    path.close();

    return true;
}

void Graph::UpdateInDegrees() {
    for (Node* node : _nodes) {
        for (Node* neighbour : node->GetNeighbours()) {
            neighbour->SetInDegree(neighbour->GetInDegree() + 1);
        }
    }
}

void Graph::ReportInDegrees() {
    for (Node* node : _nodes) {
        cout << node->GetValue() << ": " << node->GetInDegree() << endl;
    }
    cout << endl;
}

std::vector<Node*> Graph::ComputeTopologicalSorting(bool& success) {

    success = true;

    UpdateInDegrees();

    queue<Node*> queue;

    for (Node* node : _nodes) {
        if (node->GetInDegree() == 0) {
            queue.push(node);
        }
    }

    vector<Node*> res;

    while (!queue.empty()) {
        Node* node = queue.front();
        res.push_back(node);

        queue.pop();

        for (Node* neighbour : node->GetNeighbours()) {

            neighbour->SetInDegree(neighbour->GetInDegree() - 1);


            if (neighbour->GetInDegree() == 0) {
                queue.push(neighbour);
            }
        }
    }

    int total = 0;

    for (Node* node : _nodes) {
        total += node->GetInDegree();
    }

    if (total != 0)
        success = false;

    Reset();

    return res;
}

std::vector<Node*>& Graph::GetNodes() {
    return _nodes;
}

void Graph::FreeMemory() {
    for (Node* node : this->_nodes) {
        delete node;
    }
}

void Graph::Reset() {
    for (Node* node : this->_nodes) {
        node->Reset();
    }
}

Node::Node() {
    _value = 0;
    _inDegree = 0;
}

Node::~Node() {}

int Node::GetValue() {
    return _value;
}

void Node::SetValue(int value) {
    _value = value;
}

int Node::GetInDegree() {
    return _inDegree;
}

void Node::SetInDegree(int value) {
    _inDegree = value;
}

std::vector<Node*>& Node::GetNeighbours() {
    return _neighbours;
}

void Node::Reset() {
    _inDegree = 0;
}