#include <string> 
#include <string.h> 
#include <stdio.h> 
#include <iostream> 
#include <fstream> 
#include <vector> 
#include "node.h"
#include "road.h" 

std::ifstream openNode(){
	std::ifstream nodeFile; 
	nodeFile.open("cal.cnode.txt");  
	std::string testString; 
	if (nodeFile.good()){ 
		getline(nodeFile, testString); 
	}
	else{
		 std::cout << "Failed "<< std::endl;		
	//	 break; 
	}
	
	return nodeFile; 
} 

std::vector<std::string> stringVector(std::ifstream& x){ 
	std::vector<std::string>  stringContainer; 
	int counter = 0; 
	std::string tempString;  	
	while(std::getline(x, tempString)){
		stringContainer.push_back(tempString); 	
		counter++; 

	}

//	for(int i = 0; i < counter; i++){
//		std::cout << stringContainer[i] << std::endl; 		
//	}
	return stringContainer; 
}

std::ifstream openRoad(){
	std::ifstream roadFile; 
	roadFile.open("cal.cedge.txt");  
	std::string testString; 
	if (roadFile.good()){ 
		getline(roadFile, testString); 
	}
	else{
		std::cout << "Failed "<< std::endl;		
	//	break; 
	}
	return roadFile;  
} 

Node makeNode(std::string nodeString){ 
//I should be able to easily increase speed by getting rid of some of the function calls
	int ID; 	
	float latitude; 
	float longitude; 		
	std::string delim = " "; 
	std::string token;  
	std::string a, b, c; 	
	int count = 0;
	size_t pos = 0; 
	while((pos = nodeString.find(delim)) != std::string::npos){
		if (count == 0){ 
			a = nodeString.substr(0, pos); 
			nodeString.erase(0, pos + delim.length()); 
			count++; 
		} 
		else if (count == 1){ 
			b = nodeString.substr(0, pos); 
			nodeString.erase(0, pos + delim.length()); 
			count++; 

		}
	}
	c = nodeString; 
	ID =  std::stoi(a, nullptr, 0); 
	latitude = std::stof(b, nullptr); 	
	longitude = std::stof(c, nullptr); 	
//	std::cout << ID << " " << latitude << " " << longitude << std::endl; 
	Node node = Node(ID, latitude, longitude); 
	return node; 

} 
Road makeRoad(std::string string){ 
	int roadID; 
	int start; 
	int end; 
	float length; 	
	std::string delim = " "; 
	std::string a, b, c, d; 	
	int count = 0;
	size_t pos = 0; 
	while((pos = string.find(delim)) != std::string::npos){
		if (count == 0){ 
			a = string.substr(0, pos); 
			string.erase(0, pos + delim.length()); 
			count++; 
		} 
		else if (count == 1){ 
			b = string.substr(0, pos); 
			string.erase(0, pos + delim.length()); 
			count++; 

		}
		else if (count == 2){ 
			c = string.substr(0, pos); 
			string.erase(0, pos + delim.length()); 
			count++; 

		}
	}
	d = string; 
	roadID =  std::stoi(a, nullptr, 0); 
	start = std::stoi(b, nullptr); 	
	end = std::stoi(c, nullptr); 	
	length = std::stof(d, nullptr); 	
	
	//std::cout << roadID << " " << start << " " << end <<  " " << length << std::endl; 
	Road road= Road(roadID, start, end, length); 
	return road; 	


} 

