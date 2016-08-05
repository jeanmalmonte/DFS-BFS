// File: Graph.cpp
// Author: Jean Michael Almonte
// Instructor: Ajinkya Kulkarni
// CS317 - Analysis of Algorithms 

#include "Graph.h"
#pragma once

Graph::Graph()
{
	//Populate the graph with 0s once object is initialized
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			nodes[i][j] = 0;
		}
	}
}

Graph::~Graph(){}

// Checks if the graph is empty
// Returns true if empty and false if there is an element
bool Graph::isEmpty()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			if (nodes[i][j] == 1)
			{
				//Graph is not empty
				return false;
			}
		}
	}
	return true;
}

// addEdge takes the nodes given and connects them
bool Graph::addEdge(int node1, int node2)
{
	//If they are connected, return false as we don't need to add them
	if (is_connected(node1, node2)) {
		return false;
	}
	else {
		//connect the nodes
		nodes[node1][node2] = 1;
		return true;
	}
}

//Deletes an edge from the graph object
bool Graph::deleteEdge(int v1, int v2)
{
	if (is_connected(v1,v2)) {
		nodes[v1][v2] = 0;
		return true;
	}
	else {
		cout << "Could not delete edge " << "(" << v1 << ", " << v2 <<"). Node not found." << endl;
		return false;
	}
}

// Checks to see if the graph already has the nodes connected
bool Graph::is_connected(int node1, int node2)
{
	//Graph only supports 10 nodes starting with 0 and cannot be negative
	if (node1 > 9 || node2 > 9 || node1 < 0 || node2 < 0)
		return false; 
	if (nodes[node1][node2] == 1)
		return true; // graph is connected
	return false;
}

void Graph::printGraph()
{
	//cout << "Printing graph...\n" << endl;
	cout << "Nodes " << " ";
	for (int i = 0; i < vertices; i++)
	{
		cout << setw(2) << i;
	}
	cout << endl;

	for (int i = 0; i < vertices; i++)
	{
		cout << "Node " << i << " ";
		for (int j = 0; j < vertices; j++)
		{
			cout << setw(2) << nodes[i][j];
		}
		cout << endl;
	}
}

// Depth First Search Algorithm
void Graph::dfs(int vertex)
{
	stack<int> deepStack;
	stack<int> traversalOrder;
	vector<int> disc;
	vector<int>::iterator it;
	
	discovered = 0;
	processed = 0;

	if (vertex > 9 || vertex < 0) {
		cout << "Cannot start Depth First Search. Node exceded bounds\n";
		return;
	}

	cout << "Starting Depth First Search...." << endl;
	deepStack.push(vertex);							// Start search at vertex

	while(!deepStack.empty())
	{
		// Pop value off stack
		vertex = deepStack.top();					// Get the value and store it in v
		deepStack.pop();

		//discovered++;
		
		//If v is not discovered
		if (!(find (disc.begin(), disc.end(), vertex) != disc.end())) 
		{
			//Label v as discovered
			disc.push_back(vertex);							 
			traversalOrder.push(vertex);						// stack to print to screen
			//processed++;
			//Push the adjacent edges that are connected to v unto stack
			for (int i = 0; i < vertices; i++) 
			{
				if (nodes[vertex][i] == 1)
					deepStack.push(i);
			}
		}
		//cout << "Processed node: " << traversalOrder.top() << " at iteration " << processed << endl;
	}
	
	cout << "Done Depth First Search!" << endl;
	cout << "Traversal Order: ";
	while (traversalOrder.size()!=0) 
	{
		cout << traversalOrder.top() << " ";
		traversalOrder.pop();
	}
	cout << endl;
	//Set count values to 0 before exiting
	discovered = 0;
	processed = 0;
}

// Breadth First Search
void Graph::bfs(int vertex)
{
	//Queue and two vector sets
	queue<int> bestQue;
	queue<int> traversalOrder;
	vector<int> V;

	// Check if vertex is a correct vertex available
	if (vertex > 9 || vertex < 0) {
		cout << "Cannot start Breadth First Search. Node exceded bounds\n";
		return;
	}

	// Initialize variables
	discovered = 0;
	processed = 0;

	// Temporary variables
	int t;
	
	//Print message
	cout << "Starting Breadth First Search...." << endl;
	
	//Push the vertex into the queue and vector
	bestQue.push(vertex);
	V.push_back(vertex);
	traversalOrder.push(vertex);
	
	discovered++;
	cout << "Discovered node: " << vertex << " at iteration " << discovered << endl;

	while(!bestQue.empty())
	{
		// Get value off the front of the queue
		t = bestQue.front();
		//cout << "Nodes: " << t << endl;
		bestQue.pop();

		
		discovered++;
		for (int i = 0; i < vertices; i++) 
		{
			if (nodes[t][i] == 1) 
			{
				traversalOrder.push(i);

				//If node i is not in V (node i hasn't been discovered)
				if (!(find (V.begin(), V.end(), i) != V.end()))
				{
					cout << "Discovered node: " << i << " at iteration " << discovered << endl;
					//Add i to V
					V.push_back(i);
					bestQue.push(i);
				}
			}
		}
	}

	//Print Queue traversal order to screen
	cout << "Done Breadth First Search!" << endl;
	cout << "Traversal Order: ";
	while (traversalOrder.size()!=0)
	{
		cout << traversalOrder.front() << " ";
		traversalOrder.pop();
	}
	cout << endl;
}