#ifndef A_STAR_H_
#define A_STAR_H_

#include "node.h"
#include "road.h"
#include "load.h"
#include <vector> 

float heuristics(Node a, Node b); 
void A_star(std::vector<Node> start, std::vector<Node> goal); 


#endif
