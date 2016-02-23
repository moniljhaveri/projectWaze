#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <string>
#include <vector>
//#include "Node.h"

using namespace std; 

void dijkstra(vector<Node*> &ptrvec, vector<Node> &nodevec, int begin, int end);

void updateNodeDist(vector<Node*> &ptrvec, vector<Node> &nodevec, vector<Road> &roadvec);

vector<int> retrievePath(vector<Node*> &visited, vector<Node> &nodevec, int begin);
#endif // DIJKSTRA_H_