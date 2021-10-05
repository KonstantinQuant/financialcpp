//
// Created by Konstantin Kuchenmeister on 07/22/2021
// 
// Gambling.cpp
// 
// Program that makes use of the boost random libraries to simulate
// a random process of a number generator. This generator generates
// natural numbers \in [0,6]. The frequencies of each number are then
// kept track of to compute the hit percentage.
//
#include <boost/random.hpp> 
#include <map>

int main() {

	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;

	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);

	std::map<int, long> statistics; // Structure to hold outcome + frequencies

	// These variables store the amount of times each outcome from 1-6 has occured.
	// Where a <-> 1,.., f <-> 6
	long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

	int outcome{};
	for (unsigned i = 0; i < 1000000; i++) {
		outcome = six(myRng);

		switch (outcome) {
			case 1: a++; break;
			case 2: b++; break;
			case 3: c++; break;
			case 4: d++; break;
			case 5: e++; break;
			case 6: f++; break;
			default: break; 
		}		
	}

	// Inserting the results to the map.
	statistics.insert(std::pair<int, long>(1, a));
	statistics.insert(std::pair<int, long>(2, b));
	statistics.insert(std::pair<int, long>(3, c));
	statistics.insert(std::pair<int, long>(4, d));
	statistics.insert(std::pair<int, long>(5, e));
	statistics.insert(std::pair<int, long>(6, f));

	std::cout << "How many Trials? 1000000." << "\n" << std::endl;
	for (std::map<int, long>::const_iterator iter = statistics.begin(); iter != statistics.end(); iter++) { // Printing out the results
		std::cout << "Trial " << iter->first << " has " << ((double)iter->second / 10000) << "% outcomes." << std::endl; // Only 10.000 to account for the *100 percentage conversion
	}

}