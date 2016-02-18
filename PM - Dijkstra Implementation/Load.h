#ifndef LOAD_H_
#define LOAD_H_

#include <string>

using namespace std;

vector<Node> loadNodes(string filename);
void loadRoads(string filename, vector<Node> &nodevec); 

#endif // LOAD_H_
