//
// Created by Konstantin Kuchenmeister on 06/28/2021
//
// Circle.cpp
//
// CPP-File for the Circle class. 
// Implements the functionality previously defined in the Circle.hpp file.
//
#include "Circle.hpp"
#define M_PI 3.14159265359

namespace KonstantinK {
	namespace CAD {
		// Default constructor
		Circle::Circle() : m_centre_point(Point()), m_radius(0.0), Shape() {
			cout << "Circle has been created in the origin of the space." << endl;
		}
		// Destructor
		Circle::~Circle() {
			cout << "Circle has been destructed." << endl;
		}

		// Creating a circle object with custom centrepoint and radius
		Circle::Circle(const Point& newCentrePoint, const double& newRadius) : m_centre_point(newCentrePoint), m_radius(newRadius), Shape() {
			cout << "Created a circle with the center point: " << m_centre_point << " and the radius: " << m_radius << "." << endl;
		}

		// Copy constructor
		Circle::Circle(const Circle& circle) : m_radius(circle.m_radius), m_centre_point(circle.m_centre_point), Shape(circle) {
			cout << "Point has been created using the copy constructor." << endl;
		}

		// Getter for the centrepoint, can be const and returns the centrepoint object.
		Point Circle::CentrePoint() const {
			return m_centre_point;
		}

		// Getter for the circle object, can be const and returns the radius as a double.
		double Circle::Radius() const {
			return m_radius;
		}

		// Setter for the centrepoint, a const reference of a point can be given as parameter .
		void Circle::CentrePoint(const Point& newCentrePoint) {
			m_centre_point = newCentrePoint;
		}

		// Setter for the radius of the circle.
		void Circle::Radius(const double& newRadius) {
			m_radius = newRadius;
		}

		// Returns the diameter of a cirlce as a double
		double Circle::Diameter() const {
			return 2 * m_radius;
		}

		// Returns the area of a circle as a double
		double Circle::Area() const {
			return (M_PI * pow(m_radius, 2));
		}

		// Returns the circumference of the circle object as a double
		double Circle::Circumference() const {
			return (2 * M_PI * m_radius);
		}

		// Returns the description of a circle object as a string.
		string Circle::ToString() const {
			stringstream ss;
			std::string s = Shape::ToString();
			ss << "Circle with the center point of " << m_centre_point.ToString() << " and the radius of " << m_radius << " , which is a " << s << endl;
			return ss.str();
		}

		// Implementation of the draw function defined in the abstract base  class shape.
		void Circle::Draw() const {
			cout << "Drawing a line at " << *this << endl;
		}

		// Basic Operator Overloading 
		Circle& Circle::operator = (const Circle& source) { // Assignment operator.
			if (this == &source) {
				Shape::operator=(source);
				return *this;
			}
			else {
				Shape::operator=(source);
				m_centre_point = source.m_centre_point;
				m_radius = source.m_radius;
				return *this;
			}
		}

		// Ostream << operator
		ostream& operator << (ostream& os, const Circle& p) {
			os << "Circle with the center point of " << p.m_centre_point << " and the radius of " << p.m_radius << ".";
			return os;
		}
	}
}