//
// Created by Konstantin Kuchenmeister on 07/03/2021
//
// Shape.cpp
//
// CPP-File for the custom Shape type.
// Implements the functionality previously defined in the Shape.hpp file.
//

#include "Shape.hpp"

namespace KonstantinK {
	namespace CAD {
		// Default constructor
		KonstantinK::CAD::Shape::Shape() : m_id(rand()) {
			cout << "Shape has been created using the default constructor." << endl;
		}

		// Copy constructor
		Shape::Shape(const Shape& shape) : m_id(shape.m_id) {
			cout << "Shape has been created using the copy constructor." << endl;
		}

		// Destructor
		Shape::~Shape() {
			cout << "Shape has been destructed." << endl;
		}

		// Returns a textual representation of the id of the shape.
		string Shape::ToString() const {
			stringstream ss;
			ss << "Shape with the id : " << m_id << ".";
			return ss.str();
		}

		// Assignment operator
		Shape& Shape::operator = (const Shape& source) {
			if (this == &source) {
				return *this;
			}
			else {
				m_id = source.m_id;
				return *this;
			}
		}

		void Shape::print() const {
			cout << this->ToString() << endl;
		}
	}
}