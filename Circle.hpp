//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Circle.hpp
//
// Header-File for the Circle class. 
// This file specifies the "blueprint" for a custom circle type.
// Every circle has a radius and a centrepoint.
// The attributes are private, therefore they can be set or retrieved using the respective getters and setters.
// Futhermore, custom functions are provided, to return the description of a circle and its diameter, area and circumference.
//
#ifndef QUANTNET_HW_CIRCLE_H
#define QUANTNET_HW_CIRCLE_H
#define _USE_MATHS_DEFINES
#include <cmath> 
#include <string>
#include "Point.hpp"
#include "Shape.hpp"

namespace KonstantinK {
	namespace CAD {
		class Circle : public Shape {

		private:
			double m_radius; // The radius of the circle
			Point m_centre_point; // The centre point of the circle

		public:
			// Constructors & Destructors:
			Circle(); // Default constructor
			~Circle(); // Destructor
			Circle(const Point& newCentrePoint, const double& newRadius); // Custom constructor
			Circle(const Circle& circle); // Copy constructor

			// Getters
			Point CentrePoint() const;
			double Radius() const;

			//Setters
			void CentrePoint(const Point& newCentrePoint);
			void Radius(const double& newRadius);

			// Member functions:
			double Diameter() const; // Returns the diameter of the Circle object as a double, does not change values, can therefore be const
			double Area() const; // Returns the area of the circle object as a double, does not change values, can therefore be const
			double Circumference() const; // Returns the circumference of the circle object, can be used on const objects	
			string ToString() const; // Returns the description of a circle as a string
			void Draw() const; // Implementation of the draw function defined in the abstract base  class shape.

			// Basic Operator Overloading
			Circle& operator = (const Circle& source); // Assignment operator.

			friend ostream& operator << (ostream& os, const Circle& p); // Ostream << Operator.
		};
	}
}
#endif // QUANTNET_HW_CIRCLE_H