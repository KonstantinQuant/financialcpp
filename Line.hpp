//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Line.hpp
//
// Header-File for the Line class. 
// This file specifies the "blueprint" for a custom line type.
// It features a default constructor and destructor.
// Every line has a startpoint and a endpoint, that are "Points".
// The attributes are private, therefore they can be set or retrieved using the respective getters and setters.
// The description of a line can be printed using the custom ToString() function or the ostream operator.
// Furthermore, the distance of the line (distance between the start and endpoint) can be retrieved.
//

#ifndef QUANTNET_HW_LINE_H
#define QUANTNET_HW_LINE_H

#include "Point.hpp"
#include "Shape.hpp"

namespace KonstantinK {
	namespace CAD {
		class Line : public Shape {

		private:
			Point startPoint, endPoint; // Each line consists out of a startpoint and an endpoint, which underlines the composition

		public:
			// Constructors:
			Line(); // Default constructor
			~Line(); // Destructor
			Line(const Point& newStartPoint, const Point& newEndPoint); // Custom constructor
			Line(const Line& line); // Copy constructor

			// Getters:
			const Point& P1() const;
			const Point& P2() const;

			// Setters:
			void P1(const Point& newStartPoint);
			void P2(const Point& newStartPoint);

			// Member functions:
			string ToString() const; // Custom toString function that returns the description of a line.
			double Length() const; // Calculate the lenght between the start and endpoint to return the length of a line
			void Draw() const; // Implement the draw function of the abstract base class Shape.

			// Basic Operator Overloading:
			Line& operator = (const Line& source); // Assignment operator.

			friend ostream& operator << (ostream& os, const Line& p); // Ostream << Operator
		};
	}
}

#endif // QUANTNET_HW_LINE_H
