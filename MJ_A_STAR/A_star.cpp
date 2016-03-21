#include <iostream> 
#include <vector> 
#include <string> 
#include <cmath>  
#include <algorithm> 
#include <queue> 
#include "node.h"
#include "road.h" 
#include "load.h" 
#include "A_star.h"

 
float heuristics(Node a, Node b){ 
	float Along = a.getLong();
	float Alat = a.getLat();
	float Blong = b.getLong(); 
	float Blat = b.getLat(); 
	float dx = std::abs(Blong - Along); 
	float dy = std::abs(Blat - Alat); 	
	return sqrt(dx*dx + dy*dy); 
} 

void A_star(std::vector<Node> start, std::vector<Node> goal){ 
	std::priority_queue<Node> OpenList;  
	std::vector<Node> closedList; 
	start.setDistance = 0.0; 
	
} 

