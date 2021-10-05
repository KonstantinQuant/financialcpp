//
// Created by Konstantin Kuchenmeister on 07/22/2021
// 
// TuplesInCpp.cpp
// 
// Exploring boost's implementation of tuples in c++, by creating a person tuple (similar to a database table).
// This person has a name(string), an age(unsigned integer) and a height in cm(float).
//
#include <string>
#include <iostream>
#include <boost/tuple/tuple.hpp>

using namespace std;

typedef boost::tuple<string, unsigned, float> Person;

/// <summary>
/// Printing out the attributed of the person tuple, defined before.
/// </summary>
/// <param name="input">A constant reference to the person whose attributes should be printed.</param>
void printPerson(const Person& input) {
	cout << "Person with the name " << input.get<0>() << " the age of " << input.get<1>() << " years, and a height of " << input.get<2>() << " cm." << endl;
}

int main() {
	// Creating three people.
	Person le("Leonhard Euler", 314, 182);
	Person cgf("Carl Friedrich Gauss", 244, 179);
	Person gic("Gaius Iulius Caesar", 2120, 179);

	// Incrementing the age of Gaius to his actual age.
	get<1>(gic)++;
	
	// Printing the fields of person
	printPerson(le);
	printPerson(cgf);
	printPerson(gic);

	return 0;
}

