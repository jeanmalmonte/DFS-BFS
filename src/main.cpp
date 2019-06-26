// File: main.cpp
// Author: Jean Michael Almonte
// Instructor: Ajinkya Kulkarni
// CS317 - Analysis of Algorithms 

#include "Graph.h"
#pragma once

// Function prototypes
void instructions();

int main()
{
	instructions();
	Graph *graph = new Graph();
	
	//Menu variables
	char choice;
	int node    	 = 0;
	int edge1   	 = 0;
	int edge2   	 = 0;
	bool exitProgram = false;

	//Test code
	//graph->addEdge(0, 1);
	//graph->addEdge(0, 4);
	//graph->addEdge(1, 2);
	//graph->addEdge(1, 3);
	//graph->addEdge(4, 5);
	//graph->addEdge(4, 9);

	while (!exitProgram)
	{
		cout << endl;
		cout << "Menu" << endl;
		cout << "1) Add edges" << endl;
		cout << "2) Delete edge" << endl;
		cout << "3) Print Graph" << endl;
		cout << "4) Depth First Search" << endl;
		cout << "5) Breadth First Search" << endl;
		cout << "6) Refresh graph" << endl;
		cout << "7) Instructions" << endl;
		cout << "8) Exit Program" << endl;

		cin >> choice;
		switch (choice)
		{
			case '1':
				cout << "Enter edge v1: ";
				cin >> edge1;
				cout << "\nEnter edge v2: ";
				cin >> edge2;
				graph->addEdge(edge1,edge2);
				break;
			case '2':
				cout << "Enter edge v1: ";
				cin >> edge1;
				cout << "\nEnter edge v2: ";
				cin >> edge2;
				graph->deleteEdge(edge1, edge2);
				break;
			case '3':
				graph->printGraph();
				break;
			case '4':
				cout << "Enter vertex (node) to search: ";
				cin >> node;
				graph->dfs(node);
				break;
			case '5':
				cout << "Enter vertex (node) to search: ";
				cin >> node;
				graph->bfs(node);
				break;
			case '6':
				//Refresh graph
				//TO-DO: Delete pointer prior to constructing new object
				graph = new Graph();
				cout << "Graph refreshed.\n";
				break;
			case '7':
				instructions();
				break;
			case '8':
				exitProgram = true;
				break;
			default:
				cout << "Please enter a valid choice!" << endl;
				break;
		}
	}
	return 0;
}

void instructions()
{
	cout << "Graph Algorithms" << endl;
	cout << "The graph is represented as an adjacency matrix.\n";
	cout << "Traversal works by supplying BFS and DFS the starting node to begin graph traversal.\n";
	cout << "This algorithm implementation will work for graphs with NO cycles.\n";
	cout << "When constructing your graph, please use 0 as the starting vertex (node).\n";
	cout << "You have nodes 0-9 available to construct a graph.\n"; 
	cout << endl;
}
