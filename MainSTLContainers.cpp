//
// Created by Konstantin Kuchenmeister on 07/20/2021
// 
// MainSTLContainers.cpp
// 
// Playing around with basic functionality of selected STL containers. 
//

#include <list>
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {

	// Creating a list with default constructor
	list<double> dList;
	
	// Filling the list
	for (double i = 0.0; i < 5; i++) {
		dList.push_back(i);
	}

	// Printing out the first and last element of the vector
	cout << "First element of the list: " << dList.front() << "\n" << "Last element of the list: " << dList.back() << endl;

	// Creating a vector of the length 5
	vector<double> dVector(5);
	
	// Adding elements to the vector
	for (double i = 0.0; i < dVector.size(); i++) {
		dVector[(unsigned)i] = 2*i; // Accessing the elements using the index operator
	}

	// Printing out the first and last element of the vector
	cout << "First element of the vector: " << dVector[0] << "\nLast element of the vector: " << dVector[(dVector.size() - 1)] << endl;

	// Adjusting the size dynamically using push_back = Making the vector grow.
	dVector.push_back(199.7);
	dVector.push_back(177.9);

	// Creating a map that consists out of string double pairs
	map<string, double> sdMap;

	// Inserting three elements into the map
	sdMap.insert( std::pair<string, double>("F", 10) );
	sdMap.insert(std::pair<string, double>("S", 20));
	sdMap.insert(std::pair<string, double>("T", 30));

	// Printing the first and last element of the map.
	cout << "First element of the map: " << sdMap["F"] << "\nLast element of the map: " << sdMap["T"] << endl;
	
	return 0;
}