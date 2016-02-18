#ifndef ROAD_H_
#define ROAD_H_

#include <string>

using namespace std;

class Road
{
	private:
	string roadID;
	string start;
	string end;
	float length;
	
	public:
	Road(string roadID, string st, string en, float len);
	string getRoad() const;
	string getStart() const;
	string getEnd() const;
	float getLength() const;

};

#endif // ROAD_H_