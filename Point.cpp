//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Point.cpp
//
// CPP-File for the Point class.
// Implements the functions previously defined in the Point.hpp file.
//
#include "Point.hpp"

namespace KonstantinK {
	namespace CAD {
		// Default constructor, initializes a point with x=y=0. (Origin of the two-dimensional space)
		Point::Point() : m_x(0), m_y(0), Shape() {
			cout << "Point has been created with default constructor." << endl;
		}

		//Destructor
		Point::~Point() {
			cout << "Point has been destructed." << endl; // The destructor, provides a meaningful message
		}

		// Copy Constructor
		Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y), Shape(point) {
			cout << "Point has been created with the copy constructor." << endl;
		}

		// Custom constructor
		Point::Point(double newM_x, double newM_y) : m_x(newM_x), m_y(newM_y), Shape() {
			cout << "Point has been created with custom constructor." << endl;
		}

		// Custom constructor 2
		Point::Point(double value) : m_x(value), m_y(value), Shape() {
			cout << "Point has been created using the same value constructor." << endl;
		}

		// MARK: - Getters and Setters are implemented inline in the Point.hpp file

		// Returns the description of a point in specified manner as a string.
		string Point::ToString() const {
			stringstream ss;
			std::string s = Shape::ToString();
			ss << "Point(" << m_x << "," << m_y << ")" << " a " << s;
			return ss.str();
		}

		// Returns the distance from this point object to the origin of the space
		double Point::Distance() const {
			return sqrt(pow((m_x - 0), 2) + pow((m_y - 0), 2));
		}

		// d = sqrt((x_2 - x_1)^2 + (y_2 - y_2)^2)
		// Returns the distance between a parameterized point and the this.point.
		double Point::Distance(const Point& p) const {
			return sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2));
		}

		// Implementation of the draw function defined in the abstract base  class shape.
		void Point::Draw() const {
			cout << "Drawing a point at " << *this << endl;
		}

		// Basic Operator Overloading:

		// Negate the coordinates.
		Point Point::operator - () const {
			return Point(-m_x, -m_y);
		}
		// Scale the points.
		Point Point::operator * (double factor) const {
			return Point(factor * m_x, factor * m_y);
		}
		// Add two points.
		Point Point::operator + (const Point& p) const {
			return Point(m_x + p.m_x, m_y + p.m_y);
		}
		// Equally compare two points.
		bool Point::operator == (const Point& p) const {
			return ((m_x == p.m_x) && (m_y == p.m_y)) ? true : false;
		}
		// Assignment operator.
		Point& Point::operator = (const Point& source) {
			if (this == &source) {
				cout << "Current point object has been assigned to itself." << endl;
				Shape::operator=(source);
				return *this;
			}
			else {
				// delete &m_x, &m_y;
				Shape::operator=(source);
				m_x = source.m_x;
				m_y = source.m_y;
				cout << "Point object has been assigned to new point object." << endl;
				return *this;
			}
		}
		// Scale the coordinates & assign.
		Point& Point::operator *= (double factor) {
			m_x *= factor;
			m_y *= factor;
			return *this;
		}
		// Ostream << operator
		ostream& operator << (ostream& os, const Point& p) { // Send to ostream.
			os << "Point(" << p.m_x << "," << p.m_y << ")";
			return os;
		}
	}
}