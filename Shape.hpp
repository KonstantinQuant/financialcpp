//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Shape.hpp
//
// Header-File for the Shape class. 
// The shape class is the base class for the derived classes: Point, Line, Circle.
// Every shape (and derived classes) has an id.
// The id is private, and can be retrieved using a getter.
// A custom ToString() function returns the description of a shape.
// The canonical header file was followed, therefore a copy constructor, a default constructor,
// a desctructor and the assignment operator was implemented.
// Furhter functionality is implemented in the respective base classes.
//
#ifndef QUANTNET_HW_SHAPE_H
#define QUANTNET_HW_SHAPE_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
using namespace std;

namespace KonstantinK {
	namespace CAD {
		class Shape {
		private:
			int m_id;

		public:

			// Constructors:
			Shape(); // Default constructor
			Shape(const Shape& shape); // Copy constructor
			virtual ~Shape(); // Destructor

			// Member functions:
			virtual string ToString() const;
			int ID() const { return this->m_id; } // Normal inline for the getter.
			virtual void Draw() const = 0;
			void print() const;

			// Basic Operator Overloading:
			Shape& operator = (const Shape& source); // Assignment operator.
		};
	}
}
#endif // QUANTNET_HW_SHAPE_H