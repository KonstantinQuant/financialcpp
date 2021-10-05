//
// Created by Konstantin Kuchenmeister on 07/21/2021
// 
// SmallerThanDouble.h
//

#ifndef SMALLERTHANDOUBLE_H
#define SMALLERTHANDOUBLE_H

/// <summary>
/// Used to create function object in stl algorithms that overloads the round bracket operator, and checks whether a value of the stl-container is smaller than a provided double.
/// </summary>
class SmallerThanDouble {
	double value;

public:
	SmallerThanDouble(double newValue) : value{ newValue } {}; // Constructor

	~SmallerThanDouble() {}; // Destructor, could omit it aswell, canonical header file should not be needed for the use case of this class.

	/// <summary>
	/// Overloads the round bracket operator, so that an object of the class can be passed that returns whether and item's value is smaller than a constructor-set value.
	/// </summary>
	/// <param name="input">The items of the container.</param>
	/// <returns>Returns true if the container's current item is smaller than the value, false else.</returns>
	bool operator() (const double input) const {
		return input < value;
	}
};

#endif //SMALLERTHANDOUBLE_H