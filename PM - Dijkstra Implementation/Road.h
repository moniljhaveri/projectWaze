#ifndef ROAD_H_
#define ROAD_H_

#include <string>

using namespace std;

class Road
{
	private:
	int roadID;
	int start;
	int end;
	float length;
	
	public:
	Road(int roadID, int st, int en, float len);
	int getRoad() const;
	int getStart() const;
	int getEnd() const;
	float getLength() const;

};

#endif // ROAD_H_