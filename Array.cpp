//
// Created by Konstantin Kuchenmeister on 07/03/2021
//
// Array.cpp
//
// CPP-File for the custom Array type.
// Implements the functionality previously defined in the Array.hpp file.
//

#ifndef QUANTNET_HW_ARRAY_C
#define QUANTNET_HW_ARRAY_C

#include <iostream>
using namespace std;
#include "Array.hpp"
#include "ArrayException.hpp"

namespace KonstantinK {
	namespace Containers {

		template<typename T>
		unsigned Array<T>::defaultSize{ 10 };

		// Default constructor that allocates ten elements
		template <typename T>
		Array<T>::Array() : size{ defaultSize }, m_data{ new T[defaultSize] }{
			cout << "Array has been created with the default constructor." << endl;
		}

		// Destructor, that handles the memory managment automatically for us
		template <typename T>
		Array<T>::~Array() {
			delete[] m_data;
			cout << "Array has been destructed." << endl;
		}

		// Custom Constructor that allocates a custom amount of points on the heap
		template <typename T>
		Array<T>::Array(unsigned int newSize) : size{ newSize }, m_data{ new T[newSize] } {
			cout << "Array with custom size has been created using the custom constructor." << endl;
		}

		// Copy constructor 
		template <typename T>
		Array<T>::Array(const Array<T>& source) {
			m_data = new T[source.size];
			size = source.size;

			for (unsigned int i = 0; i < source.size; i++) {
				m_data[i] = source.m_data[i];
			}

			cout << "Array has been created using the copy constructor." << endl;
		}

		template <typename T>
		Array<T>& Array<T>::operator = (const Array<T>& source) { // Assignment operator.
			// First if checks if the source object is the same as the this object, if the addresses are the same, just return this
			if (this == &source) {
				return *this;
			}
			else {
				delete[] m_data; // Delete the old array
				m_data = new T[source.size]; // Allocate new memory
				size = source.size; // Init the size

				// Deep copy of the points
				for (unsigned int i = 0; i < source.size; i++) {
					m_data[i] = source.m_data[i];
				}
				return *this;
			}
		}

		// Return the size of the array as an unsigned integer
		template <typename T>
		unsigned int Array<T>::Size() const {
			return size;
		}

		// Sets an element in the array, and prevents any out of bounds error
		template <typename T>
		void Array<T>::SetElement(const T& t, const unsigned int& index) {
			if (index >= 0 && index < size) {
				m_data[index] = t;
			}
			else {
				throw KonstantinK::ArrayExceptions::OutOfBoundsException(index);
			}
		}

		// Returns an element in the array, if the requested index is out of bounds, return the first element
		template <typename T>
		T& Array<T>::GetElement(const unsigned int& index) const {
			if (index >= 0 && index < size) {
				return m_data[index];
			}
			else {
				throw KonstantinK::ArrayExceptions::OutOfBoundsException(index);
			}
		}

		template <typename T>
		int Array<T>::DefaultSize() {
			return Array<T>::defaultSize;
		}

		template <typename T>
		void Array<T>::DefaultSize(int dSize) {
			Array<T>::defaultSize = dSize;
		}


		// Square bracket operator, works parallely to the get and set element functions
		template <typename T>
		T& Array<T>::operator [] (unsigned int index) {
			if (index >= 0 && index < size) {
				return m_data[index];
			}
			else {
				throw KonstantinK::ArrayExceptions::OutOfBoundsException(index);
			}
		}

		// Square bracket operator, works parallely to the get and set element functions
		template <typename T>
		const T& Array<T>::operator [] (unsigned int index) const {
			if (index >= 0 && index < size) {
				return m_data[index];
			}
			else {
				throw KonstantinK::ArrayExceptions::OutOfBoundsException(index);
			}
		}
	}
}

#endif //QUANTNET_HW_ARRAY_C
