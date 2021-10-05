//
// Created by Konstantin Kuchenmeister on 07/12/2021
//
// Array.hpp
//
// Header-file for the Array class. 
// This file specifies the "blueprint" for a custom Array type.
// Purpose of this custom point array type, is that we do not need to explicitly manage memory.
// It contains a pointer to the first element of the array, the size and a static default size, which is 10.
// Beyond the functionality of the canonical header-file, it features a custom size constructor, getters and setters for the size
// and elements, as well as crucial array-operators like the square bracket operator.
//
#ifndef QUANTNET_HW_ARRAY_H
#define QUANTNET_HW_ARRAY_H

namespace KonstantinK {
	namespace Containers {
		template <typename T>
		class Array {
		private:
			T* m_data; // The pointer that points to the first element of the generic array
			unsigned int size; // The size of the array as an unsigned int, since it cannot be negative
			static unsigned defaultSize; // The default size of the generic array

		public:

			// Constructors and Destructor:

			Array(); // The default constructor for the array
			Array(unsigned int newSize); // Custom constructor to set a variable, custom size
			Array(const Array<T>& source); // Copy constructor
			~Array(); // Destructor

			// Member functions:

			// Getter
			unsigned int Size() const; // Returns the size of the array
			T& GetElement(const unsigned int& index) const; // Returns an element at a specified index
			static int DefaultSize();

			// Setter
			void SetElement(const T& t, const unsigned int& index); // Sets an element at a specified index
			static void DefaultSize(int dSize);

			// Operator overloading:
			T& operator [] (unsigned int index); // Square bracket operator that can be used for reading and writing
			Array<T>& operator = (const Array<T>& source); // Assignment operator
			const T& operator [] (unsigned int index) const; // Square bracket operator for constant arrays, can only be used for reading
		};
	}
}

// Templates must be defined and implemented in the header-file. Therefore include the cpp file here.
#ifndef QUANTNET_HW_ARRAY_C
#include "Array.cpp"
#endif

#endif //QUANTNET_HW_ARRAY_H