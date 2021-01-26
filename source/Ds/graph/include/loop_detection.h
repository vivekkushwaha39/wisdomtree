/*
 * loop_detection.h
 *
 *  Created on: Jan 26, 2021
 *      Author: VivekK4
 */

#ifndef SOURCE_DS_GRAPH_INCLUDE_LOOP_DETECTION_H_
#define SOURCE_DS_GRAPH_INCLUDE_LOOP_DETECTION_H_
#include <vector>
#include <unordered_map>
#include <queue>

int detectLoop(int , char **);

class Graph
{
private:
	int numVer;
	std::vector<int> *adjMat;
public:
	Graph(int );
	void addEdge(int , int);
	void findLoop();
};
#endif /* SOURCE_DS_GRAPH_INCLUDE_LOOP_DETECTION_H_ */
