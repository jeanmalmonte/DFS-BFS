// File: Graph.h
// Author: Jean Michael Almonte
// Instructor: Ajinkya Kulkarni
// CS317 - Analysis of Algorithms 

#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
#include <algorithm> 
#include <queue>

using namespace std;

class Graph
{
	public:
		Graph();
		~Graph();
		
		// Graph construction functions
		bool addEdge(int v1, int v2);  
		bool deleteEdge(int v1, int v2);
		bool is_connected(int v1, int v2);
		void printGraph();
		bool isEmpty();

		// Graph Algorithms to search the graph object given a vertex (node) to look for 
		void dfs(int vertex);
		void bfs(int vertex);

	private:
		const static int vertices = 10;
		int nodes[10][10];
		// For processing nodes 
		int discovered;
		int processed;
};
