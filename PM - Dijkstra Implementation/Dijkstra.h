#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <string>
#include <vector>
//#include "Node.h"

using namespace std; 

void dijkstra(vector<Node*> &ptrvec, vector<Node> &nodevec, string begin, string end);

void updateNodeDist(vector<Node*> &ptrvec, vector<Node> &nodevec, vector<Road> roadvec);

vector<string> retrievePath(vector<Node*> &visited, vector<Node> &nodevec, string begin, string end);
#endif // DIJKSTRA_H_