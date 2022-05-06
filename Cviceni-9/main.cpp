#include "Graph.h"
#include <iostream>

using namespace std;

int main() 
{
	Graph graph;
	graph.LoadData("input_bad.txt");

	bool success;
	auto v = graph.ComputeTopologicalSorting(success);

	if (success) 
	{
		for (auto node : v) {
			cout << node->GetValue() << " ";
		}
		cout << endl;
	}
	else 
	{
		cout << "Incorrect graph for making topological sorting!" << endl;
	}



	Graph graphg;
	graphg.LoadData("input_good.txt");

	bool successg;
	auto g = graphg.ComputeTopologicalSorting(successg);

	if (successg) 
	{
		for (auto node : g) {
			cout << node->GetValue() << " ";
		}
		cout << endl;
	}
	else 
	{
		cout << "Incorrect graph for making topological sorting!" << endl;
	}

	getchar();
	return 0;
}
