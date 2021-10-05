//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Point.hpp
//
// Header-File for the Point class. 
// This file specifies the "blueprint" for a custom point type in a two-dimensional space.
// Every point has a private x-coordinate and a y-coordinate, which are doubles.
// A point can be created using the default constructor that creates the origin of the space (0,0). 
// Furthermore a point can be created with the x and y coordinates explicity stated.
// The coordinates can be retrieved or set using the respective getters and setters.
// A textual description of the point can either be retrieved using the ToString() function or the ostream operator.
// The distance to the origin or another point can be calculated.
// Using operator overloading, common mathematical operations can be performed.
//

#ifndef QUANTNET_HW_POINT_H
#define QUANTNET_HW_POINT_H

#include <iostream>
#include <sstream>
#include <cmath>
#include "Shape.hpp"
using namespace std;

namespace KonstantinK {
	namespace CAD {
		class Point : public Shape {

		private:
			double m_x, m_y; // The respective two-dimensional x and y coordinates of a point 

		public:

			// Constructors:
			Point(); // Default Constructor
			~Point(); // Destructor
			Point(const Point& point); // Copy constructor
			Point(double m_x, double m_y); // Custom Constructor to create a point with user specified values for x and y coordinates
			explicit Point(double value); // Custom Constructor (2)

			// Getters:
			double X() const; // Returns the m_x value of a point, therefore double as a return type
			double Y() const; // Returns the m_y value of a point, therefore double as a return type

			// Setters (default inline):
			void X(double newM_x) { m_x = newM_x; } // Sets the value of the m_x value of a point instance, no return type. Is needes since the actual values are private
			void Y(double newM_y) { m_y = newM_y; } // Sets the value of the m_y value of a point instance, no return type. Is needes since the actual values are private

			// Member functions:
			string ToString() const; // Returns a string interpretation of a point, using std::string
			double Distance() const; // Calculate the distance to the origin (0, 0).
			double Distance(const Point& p) const; // Calculate the distance between two points.
			void Draw() const; // Implement the draw function of the abstract base class Shape.

			// Basic Operator Overloading:
			Point operator - () const; // Negate the coordinates.
			Point operator * (double factor) const; // Scale the coordinates.
			Point operator + (const Point& p) const; // Add coordinates.
			bool operator == (const Point& p) const; // Equally compare operator.
			Point& operator = (const Point& source); // Assignment operator.
			Point& operator *= (double factor); // Scale the coordinates & assign.


			friend ostream& operator << (ostream& os, const Point& p); // Ostream << operator.
		};

		// Getters (normal inline):
		inline double Point::X() const { return m_x; } // Returns the m_x value of a point, as a double.
		inline double Point::Y() const { return m_y; } // Returns the m_y value of a point, as a double.
	}
}

#endif // QUANTNET_HW_POINT_H