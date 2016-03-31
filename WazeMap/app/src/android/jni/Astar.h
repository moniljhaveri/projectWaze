#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include "Node.h"

void Astar(vector<Node>* nodes, vector<Node*>* path, Node *start_node, Node *end_node, float h_weight, bool debug);

#endif