//
// Created by Konstantin Kuchenmeister on 07/14/2021
//
// PointArray.cpp
//
// Source-file for the Generic PointArray, that extends the Array<Point> type.
// Implements the functionality previously defined in the PointArray.hpp file.
//

#ifndef QUANTNET_HW_POINT_ARRAY_C
#define QUANTNET_HW_POINT_ARRAY_C

#include "PointArray.hpp"

namespace KonstantinK {
	namespace Containers {

		/// <summary>
		/// Creates a new PointArray according to the default constructor of the array parent class.
		/// </summary>
		PointArray::PointArray() : Array<KonstantinK::CAD::Point>() {
			cout << "New Array of Points has been created." << endl;
		}

		/// <summary>
		/// Creates a new Point Array with a custom size.
		/// </summary>
		/// <param name="size">The wished size for the Pointarray.</param>
		PointArray::PointArray(unsigned size) : Array<KonstantinK::CAD::Point>(size) {
			cout << "New Array of Points has been created using a custom size" << endl;
		}

		/// <summary>
		/// Copy constructor for the PointArray.
		/// </summary>
		/// <param name="source">The parameterized numeric array using for copying.</param>
		PointArray::PointArray(const PointArray& source) : Array<KonstantinK::CAD::Point>(source) {
			cout << "Point array has been created using the copy constructor." << endl;
		}


		/// <summary>
		/// Destructor for the PointArray objects. Is called automatically
		/// </summary>
		PointArray::~PointArray() {
			cout << "Point array has been destructed." << endl;
		}

		// Member functions:

		/// <summary>
		/// Calculates the total lenght between the points in the array.
		/// </summary>
		/// <returns>Returns the total length of the array.</returns>
		double PointArray::Length() const {
			double result = 0.0;

			if (this->Size() > 1) {
				for (unsigned i = 0; i < this->Size() - 1; i++) {
					result += this->GetElement(i).Distance(this->GetElement(i + 1));
				}
				return result;
			}
			else {
				throw KonstantinK::ArrayExceptions::SizeTooShortException();
			}

		}

		// Operators:
		// Assignment operator
		PointArray& PointArray::operator = (const PointArray& source) {
			if (this != &source) Array<KonstantinK::CAD::Point>::operator=(source);
			return *this;
		}
	}
}

#endif