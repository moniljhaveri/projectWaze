#ifndef NODE_H_
#define NODE_H_ 

#include <string> 
#include <vector> 
#include "Road.h" 

class Node
{ 
	private: 
	int NodeID; 
	float latitude; 
	float longitude; 
	std::vector<Road> roads; 
	int Nodefrom; 
	
	public: 
	float distance; 

	public: 
	Node(int ID, float lat, float longit); 
	void setDistance(float);
	void setNodeFrom(int ID); 
	float getDistance() const; 
	void setCoordinate(float lat, float longit); 
	int getNode() const; 
	int getNodeFrom() const; 
	float getLat() const; 
	float getLong() const; 
	void addRoad(Road road); 
	std::vector<Road> getRoads(); 
};  
#endif 
