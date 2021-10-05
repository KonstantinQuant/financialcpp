//
// Created by Konstantin Kuchenmeister on 07/21/2021
// 
// MainSTLAlgorithms1.cpp
//

#include <vector>
#include <algorithm>
#include <iostream>
#include "SmallerThanDouble.h"
using namespace std;

/// <summary>
/// Checks if a double input is smaller than 10.
/// </summary>
/// <param name="input">The input number to be compared.</param>
/// <returns>Returns true if the value is less than 10, false else.</returns>
bool SmallerThan(double input) {
	return input < 10.0;
}

int main() {

	// Creating a vector
	vector<double> dVector;
	// Growing the vector by appending elements
	dVector.push_back(9.0);
	dVector.push_back(8.0);
	dVector.push_back(7.0);
	dVector.push_back(6.0);
	dVector.push_back(11.0);
	dVector.push_back(12.0);

	// Uses the global function implementation, that can check for a 'literal' value, that has to be set as a constant.
	cout << "Number of items smaller than 10: " << count_if(dVector.begin(), dVector.end(), SmallerThan) << endl;

	// Uses the function object, where a custom smaller-than-value can be passed.
	cout << "Number of items smaller than 13: " << count_if(dVector.begin(), dVector.end(), SmallerThanDouble(13.0)) << endl;
	
	return 0;
}