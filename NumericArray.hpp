//
// Created by Konstantin Kuchenmeister on 07/03/2021
//
// NumericArray.hpp
//
// Header-file for the NumericArray class. 
// This file extends the generic Array functionality by numeric operations.
// These include scaling, adding and scalar product calculation.
// It features a the same constructors as the parent Array class.
// Every circle has a radius and a centreendpoint
// The attributes are private, therefore they can be set or retrieved using the respective getters and setters
// Futhermore, custom functions are provided, to return the size, set and get an element
//
#ifndef QUANTNET_HW_NUMERIC_ARRAY_H
#define QUANTNET_HW_NUMERIC_ARRAY_H

#include "Array.hpp"
#include "ArrayException.hpp"

namespace KonstantinK {
	namespace Containers {
		template <typename T>
		class NumericArray : public Array<T> {
		public:

			// Constructors and Desctructor
			NumericArray(); // Default constructor
			NumericArray(unsigned int size); // Custom size constructor
			NumericArray(const NumericArray<T>& source); // Copy constructor
			~NumericArray(); // Destructor

			// Member functions:

			// Decided to make the return of the DotProduct not T but a double for the following reason:
			// If a custom complex type (like points) had the * operator with itself (its type) defined it would expect to return a value of that type.
			// However, we want the dot product to return a number each time. For the same reason I made the factor for the multiply operator a double.
			double DotProduct(const NumericArray<T>& arr) const; // Dot product of two numeric products.

			// Operators:
			NumericArray<T>& operator = (const NumericArray<T>& source); // Assignment operator
			NumericArray<T> operator * (const double factor) const; // Scale operator
			NumericArray<T> operator + (const NumericArray<T>& arr) const; // Addition operator
		};
	}
}

#ifndef QUANTNET_HW_NUMERIC_ARRAY_C
#include "NumericArray.cpp"
#endif

#endif