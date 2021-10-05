//
// Created by Konstantin Kuchenmeister on a sunny day.
// 
// VariantMain.cpp
// 
// Testing boost variants, as well as the boost visitor.
//

#include "Point.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include <boost/variant/variant.hpp>
#include <boost/variant/get.hpp>
#include "Visitor.h"

using namespace KonstantinK::CAD;

// Variant that stores the shape type: can be any of the types at once
typedef boost::variant<Point, Line, Circle> ShapeType;

/// <summary>
/// Asks the user what shape (s)he wants to create and returns it as a variant.
/// </summary>
/// <returns>Returns the a variant that contains the wanted shape.</returns>
ShapeType createShape();

int main() {
	ShapeType t = createShape();

	cout << t << endl;

	try {
		boost::get<Line>(t) = Line(); // Will throw bad get error, if the variant is not a line.
	}
	catch (boost::bad_get& ex) {
		cout << "It appears as if the variant wasn't a line." << endl;
	}
	catch (...) {
		cout << "An unhandled exception has occured." << endl;
	}

	Visitor vis(3, 3);
	
	boost::apply_visitor(vis, t);

	cout << t << endl;

	return 0;
}

ShapeType createShape() {
	unsigned short input;
	cout << "What shape to create? (Point = 1, Line = 2, Circle = 3)" << endl;
	cin >> input;

	ShapeType shapeT;

	switch (input) {
	case 1: shapeT = Point(); break;
	case 2: shapeT = Line(); break;
	case 3: shapeT = Circle(); break;
	default: break;
	}

	return shapeT;
}