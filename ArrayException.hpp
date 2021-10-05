//
// Created by Konstantin Kuchenmeister on 07/11/2021
//
// ArrayException.hpp
//
// Header file for the ArrayException Objects that can occur and be thrown.
//

#ifndef QUANTNET_HW_ARRAY_EXCEPTION_H
#define QUANTNET_HW_ARRAY_EXCEPTION_H

using namespace std;
#include <iostream>
#include <sstream>
#include <string>

namespace KonstantinK {
	namespace ArrayExceptions {
		class ArrayException {
		public:
			virtual const string GetMessage() const = 0;
		};

		/// <summary>
		/// Occurs whenever someone tries to access the index of an array that is not allocated or intialized.
		/// </summary>
		class OutOfBoundsException : public ArrayException {
		private:
			unsigned int m_index; // The index of the array where the error is thrown

		public:

			// Default constructor
			OutOfBoundsException() : m_index(0) {
				cout << "OutOfBoundsException has been created at index: 0." << endl;
			}

			OutOfBoundsException(unsigned int index) : m_index(index) {
				cout << "OutOfBoundsException has been created at index: " << m_index << "." << endl;
			}

			// Destructor
			~OutOfBoundsException() {
				cout << "OutOfBoundsException object has been destructed." << endl;
			}

			const string GetMessage() const {
				stringstream ss;
				ss << "ArrayIndexOutOfBoundsException: The current index " << m_index << " is out of bounds.";
				return ss.str();
			}
		};

		/// <summary>
		/// Occurs whenever the size is different while operating two numeric arrays where equal size is crucial to the operation.
		/// </summary>
		class IncompatibleSizeException : public ArrayException {

		public:
			// Default constructor
			IncompatibleSizeException() {
				cout << "IncompatibleSizeException has been created." << endl;
			}

			// Destructor
			~IncompatibleSizeException() {
				cout << "IncompatibleSizeException object has been destructed." << endl;
			}

			const string GetMessage() const {
				stringstream ss;
				ss << "IncompatibleSizeException: The operation cannot be performed on arrays of different sizes.";
				return ss.str();
			}
		};

		/// <summary>
		/// Occurs whenever the size of the Array less than 2 in a Points array and the special length function is called.
		/// </summary>
		class SizeTooShortException : public ArrayException {

		public:
			// Default constructor
			SizeTooShortException() {
				cout << "IncompatibleSizeException has been created." << endl;
			}

			// Destructor
			~SizeTooShortException() {
				cout << "IncompatibleSizeException object has been destructed." << endl;
			}

			const string GetMessage() const {
				stringstream ss;
				ss << "This array is too short to invoke this function.";
				return ss.str();
			}
		};
	}
}

#endif // QUANTNET_HW_ARRAY_EXCEPTION_H