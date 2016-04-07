#ifndef YEN_H
#define YEN_H

#include <vector>
#include "Node.h"

struct potential_path {
	vector<Node*> path;
    double distance;
};
void Yen(vector<Node>* nodes, vector< vector<Node*>* >* paths, Node *start_node, Node *end_node, int k_max);

#endif