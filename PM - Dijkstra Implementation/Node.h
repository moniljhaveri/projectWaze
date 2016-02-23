#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <vector>
#include "Road.h"

using namespace std; 

class Node
{
	private:	
	int nodeID;
	float lat;
	float longit;
	vector<Road> roads;
	int nodefrom;
	public:
	float distance;	

	public:
	Node(int ID, float lat, float longit);
	void setDistance(float);
	float getDistance() const;
	int getNodeFrom() const;
	void setNodeFrom(int nodeID);
	void setCoord(float lat, float longit);
	int getNode() const;
	float getLat() const;
	float getLongit() const;
	void addRoad(Road);
	vector<Road> getRoads();
	bool operator<(const Node &d);
	bool operator>(const Node &d);
	
};

struct CompareNodes {
    bool operator()(const Node &n1, const Node &n2) const
	{
        return n1.getDistance() > n2.getDistance();
    }
};

struct CompareNodePtrs {
	bool operator()(Node* a, Node* b) 
	{ return (a->getDistance() > b->getDistance()); }
};

#endif // NODE_H_