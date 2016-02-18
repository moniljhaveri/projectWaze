#include "Road.h"
#include <vector>
#include <string>

using namespace std;

Road::Road(string ID, string st, string en, float len)
{
roadID = ID;
start = st;
end = en;
length = len;
}

string Road::getRoad() const
{return roadID;}

string Road::getStart() const
{return start;}

string Road::getEnd() const
{return end;}

float Road::getLength() const
{return length;}

