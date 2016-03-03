#ifndef LOAD_H_
#define LOAD_H_
#include <iostream> 
#include <fstream> 

std::ifstream openNode(); 
std::ifstream openRoad(); 
Node makeNode(std::string nodeString); 
std::vector<std::string> stringVector(std::ifstream& x, int choice); 

#endif

