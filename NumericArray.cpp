//
// Created by Konstantin Kuchenmeister on 07/12/2021
//
// NumericArray.cpp
//
// Source-file for the Generic NumericArray, that extends the Array<T> type.
// Implements the functionality previously defined in the NumericArray.hpp file.
//

#ifndef QUANTNET_HW_NUMERIC_ARRAY_C
#define QUANTNET_HW_NUMERIC_ARRAY_C

#include "NumericArray.hpp"
#include <typeinfo>

namespace KonstantinK {
	namespace Containers {

		// Constructors and Desctructor:

		/// <summary>
		/// Creates a NumericArray object of length 10 by calling the default constructor of the Array type.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		template <typename T>
		NumericArray<T>::NumericArray() : Array<T>::Array() {
			cout << "NumericArray has been created using the default constructor." << endl;
		}

		/// <summary>
		/// Creates a NumericArray object of custom size.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="size">The wanted size of the array.</param>
		template <typename T>
		NumericArray<T>::NumericArray(unsigned int size) : Array<T>::Array(size) {
			cout << "NumericArray has been created using a custom size." << endl;
		}

		/// <summary>
		/// Copy constructor for the NumericArray class.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="source">The parameterized numeric array using for copying.</param>
		template <typename T>
		NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>::Array(source) {
			cout << "NumericArray has been created using the copy constructor." << endl;
		}

		/// <summary>
		/// Destructs a NumericArray object. Is automatically called.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		template <typename T>
		NumericArray<T>::~NumericArray() {
			cout << "NumericArray has been destructed." << endl;
		}

		// Member functions and operators:

		/// <summary>
		/// Allows to scale elements of a numeric array by a factor.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="factor">The factor that each element of the array is multiplied by.</param>
		/// <returns>Returns a new numeric array object that contains the scaled elements.</returns>
		template <typename T>
		NumericArray<T> NumericArray<T>::operator * (const double factor) const { // Scale the elements of the NumericArray by a factor.
			NumericArray<T> resultArr(this->Size());

			for (unsigned int i = 0; i < this->Size(); ++i) {
				resultArr[i] = ((*this)[i]) * factor; // Here, I assume that the underlying type (T) has the scale and assign operator.
			}
			return resultArr;
		}

		/// <summary>
		/// A function that enables to add two numeric arrays memberwise.
		/// This memberwise addition operation requires both arrays to be the same size.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="arr">The summand of the operation.</param>
		/// <returns>Returns a new numeric array object that contains the memberwise addition results.</returns>
		template <typename T>
		NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& arr) const {
			if (this->Size() == arr.Size()) {
				NumericArray<T> resultArr(this->Size());
				for (unsigned int i = 0; i < this->Size(); ++i) {
					resultArr[i] = arr[i] + Array<T>::GetElement(i); // Here, I assume that the underlying type (T) has the scale and assign operator.
				}
				return resultArr;
			}
			else throw KonstantinK::ArrayExceptions::IncompatibleSizeException();
		}

		/// <summary>
		/// A function that calculates the dot product of two numeric arrays of the same size.
		/// This product is defined as: sum(a[i] * b[i])).
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="arr">The second factor of the multiplication.</param>
		/// <returns>Returns a double contains the sum of the memberwise multiplication results.</returns>
		template <typename T>
		double NumericArray<T>::DotProduct(const NumericArray<T>& arr) const { // Dot product of two numeric products.
			if ((*this).Size() == arr.Size()) {
				double result = 0;
				for (unsigned int i = 0; i < (*this).Size(); i++) {
					result += (double)(*this).GetElement(i) * (double)arr.GetElement(i);
				}
				return result;
			}
			else throw KonstantinK::ArrayExceptions::IncompatibleSizeException();

		}

		/// <summary>
		/// Allows for assigning a numeric array object to another numeric array object.
		/// </summary>
		/// <typeparam name="T">The generic numeric type.</typeparam>
		/// <param name="source">The right hand object of the assignment.</param>
		/// <returns>Returns a reference to the this-object.</returns>
		template <typename T>
		NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source) { // Assignment operator
			if (this != source) Array<T>::operator=(source);
			return *this;
		}
	}
}

#endif

