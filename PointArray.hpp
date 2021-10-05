//
// Created by Konstantin Kuchenmeister on 07/14/2021
//
// PointArray.hpp
//
// Header-file for the PointArray class. 
// Created to extend the generic Array<T> type by specific Point functionality: Calculating the total length between the points in the array.
//
#ifndef QUANTNET_HW_POINT_ARRAY_H
#define QUANTNET_HW_POINT_ARRAY_H

#include "Array.hpp"
#include "ArrayException.hpp"
#include "Point.hpp"

namespace KonstantinK {
	namespace Containers {

		class PointArray : public Array<KonstantinK::CAD::Point> {
		public:

			// Constructors and Desctructor
			PointArray(); // Default constructor
			PointArray(unsigned size); // Custom size constructor
			PointArray(const PointArray& source); // Copy constructor
			~PointArray(); // Destructor

			// Member functions:

			double Length() const; // Returns the total length between the points in the array.

			// Operators:
			PointArray& operator = (const PointArray& source); // Assignment operator
		};
	}
}

#endif