#//
// Created by Konstantin Kuchenmeister on 06/27/2021
//
// Line.cpp
//
// CPP-File for the Line class. 
// Implements the functionality previously defined in the Line.hpp file.
//

#include "Line.hpp"

namespace KonstantinK {
	namespace CAD {
		// Default constructor. Creates a line between the two equal points: The origin.
		Line::Line() : startPoint(Point::Point()), endPoint(Point::Point()), Shape() {
			cout << "Line has been created with the default constructor and initialized with points 0." << endl;
		}

		// Copy constructor
		Line::Line(const Line& line) : startPoint(line.startPoint), endPoint(line.endPoint), Shape(line) {
			cout << "Line has been created using the copy constructor." << endl;
		}

		// Custom constructor, that omits using setters and getters to create a Line with points other than 0,0
		// Assigns the parameterized values to the created object's points
		Line::Line(const Point& newStartPoint, const Point& newEndPoint) : startPoint(newStartPoint), endPoint(newEndPoint), Shape() {
			cout << "Line has been created using two custom points." << endl;
		}

		// Destructor
		Line::~Line() {
			cout << "Line has been destructed." << endl;
		}

		// Overloaded getters and setters, since the points of a line are private properties:
		// Getter for the startPoint of the line.
		const Point& Line::P1() const {
			return startPoint;
		}

		// Getter for the endPoint of the line.
		const Point& Line::P2() const {
			return endPoint;
		}

		// Setter for the startPoint of the line. Allows to change the startPoint of a line.
		void Line::P1(const Point& newStartPoint) {
			startPoint = newStartPoint;
		}

		// Setter for the endPoint of the line. Allows to change the endPoint of a line.
		void Line::P2(const Point& newEndPoint) {
			endPoint = newEndPoint;
		}

		// Custom ToString function that prints the description of a line object in a textual representation.
		string Line::ToString() const {
			stringstream ss;
			std::string s = Shape::ToString();
			ss << "Line between the start-point " << startPoint.ToString() << " and the end-point " << endPoint.ToString() << " , which is a " << s;
			return ss.str();
		}

		// Returns the length of the line, is calculated with the points distance function between the start and endpoint.
		double Line::Length() const {
			return startPoint.Distance(endPoint);
		}

		// Implementation of the draw function defined in the abstract base  class shape.
		void Line::Draw() const {
			cout << "Drawing a line at " << *this << endl;
		}

		// Basic operator overloading:

		Line& Line::operator = (const Line& source) { // Assignment operator.
			if (this == &source) {
				cout << "Current line object has been assigned to itself." << endl;
				Shape::operator=(source);
				return *this;
			}
			else {
				Shape::operator=(source);
				startPoint = source.startPoint;
				endPoint = source.endPoint;
				cout << "Line object has been assigned to new line object." << endl;
				return *this;
			}
		}

		ostream& operator << (ostream& os, const Line& p) { // Ostream << operator
			os << "Line between the start-point " << p.startPoint << " and the end-point " << p.endPoint;
			return os;
		}
	}
}