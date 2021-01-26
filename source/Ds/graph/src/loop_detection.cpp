#include "loop_detection.h"
#include <iostream>
using namespace std;

Graph::Graph(int v)
{
	this->adjMat = new vector<int> [v];
	this->numVer = v;
}

void Graph::addEdge(int v1, int v2)
{
	this->adjMat[v1].push_back(v2);
	this->adjMat[v2].push_back(v1);
}

/**
 * This algorithm works if you represent the graph as
 * Adjacent matrix
 */
void Graph::findLoop()
{
	unordered_map<int, int> degree;
	queue<int> leaves;
	int visited[numVer] =
	{ 0 };

	/**
	 *  Calculate degree of original graph
	 */
	for (int i=0; i < numVer; i++)
	{
		degree[i] = adjMat[i].size();
	}
	while (true)
	{
//----------------------------------------------------
// Everything happening in this block removes
// all current leaf nodes and revels new leaf nodes
//----------------------------------------------------

		// Find the leaf nodes from graph
		for (int i = 0; i < numVer; i++)
		{
			if (visited[i] == 0 && degree.at(i) == 1)
			{
				leaves.push(i);
			}
		}

		if ( leaves.empty() )
		{
			break;
		}
		while (leaves.empty() == false)
		{
			int temp = leaves.front();
			leaves.pop();
			// Reduce the degree of connected nodes
			for (int i = 0; i < adjMat[temp].size(); i++)
			{
				int tmpdeg = degree[adjMat[temp][i]];
				tmpdeg--;
				degree[adjMat[temp][i]] = tmpdeg;
			}
			// mark as visited
			visited[temp] = 1;
		}

//----------------------------------------------
// End of this block all current leaf nodes will
// be removed repeat this until all are removed
//----------------------------------------------
	}

// Print the remaining nodes which are not visited
	for (int i = 0; i < this->numVer; i++)
	{
		if ( !visited[i] )
		{
			cout << i << ", ";
		}
	}

}

int detectLoop(int ac, char **av)
{

	Graph g(7);
	/**
	 * we have to create below graph
	 *          1
	 *         / \
	 *        2   3
	 *        |   |
	 *        4---5
	 *        |    \
	 *        6     \
	 *               7
	 */
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.addEdge(4, 6);
	g.findLoop();

	return 0;
}
