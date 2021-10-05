//
// Created by Konstantin Kuchenmeister on 07/21/2021
// 
// Sum.h
// 
// Implements four variations of the Sum($) function, that uses iterators to calculate various sums of selected stl containers.
//
#ifndef QUANTNET_HW_SUM_H
#define QUANTNET_HW_SUM_H

#include <map>
#include <string>
#include <iostream>

/// <summary>
/// Calculates the sum of all values in a container.
/// </summary>
/// <typeparam name="T">The container type.</typeparam>
/// <param name="container">The container of which the sum should be calculated of.</param>
/// <returns>Returns the sum of all values in a container.</returns>
template <typename T> double Sum(const T& container);

template <typename T>
double Sum(const T& container) {
	typename T::const_iterator iter = container.begin(); // Create iterator to traverse through the container.
	double result{}; // Stores the result, initialized with 0.

	for (; iter != container.end(); iter++) {
		result += (*iter); // Dereference the pointer-like iterator and add the value onto the result.
	}
	return result; // Return the result
}



/// <summary>
/// Calculates the sum of all values in a map.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="container">The map, which the second field is a numeric standard type and of which the sum should be calculated of.</param>
/// <returns>Returns the sum as a double.</returns>
template <typename T1, typename T2> double Sum(const std::map<T1, T2>& container); // Enables support for maps.

template <typename T1, typename T2>
double Sum(const std::map<T1, T2>& container) {
	// Note: Could also create iterator for the end but either way would work fine:)
	typename std::map<T1, T2>::const_iterator iter = container.begin(); // Create iterator to traverse through the map.
	double result = 0.0; // Initialize the result.

	for (; iter != container.end(); iter++) { 
		result += iter->second; // Adding the value (the double of the key value pair)
	}
	return result; // Return the result
}

// Passing by const refernce makes the most sense in my opinion:
// Call by value is not that great because the type is complex and we would not want to create two copies
// Calling only by reference would make it harder to call the function.
// Calling by const reference requires us to create just one copy (the first one) since the second iterator is not mutated in the function body anyways.

/// <summary>
/// Calculates the sum of all values between two passed in iterators. Includes the value of start, excludes the value of end.
/// </summary>
/// <typeparam name="T">The type of container.</typeparam>
/// <param name="start">The first iterator.</param>
/// <param name="end">The second iterator.</param>
/// <returns>Returns the sum of all values between the iterators as a double.</returns>
template <typename T> double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end);

template <typename T> 
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end) {
	typename T::const_iterator copy = start; // Creating a copy of the start iterator so it can be passed by const reference.
	double result = 0.0; // Intialize the result.

	while (copy != end) { // As long as the copy iterator is not at the same container point as the end iterator, advance it, and store the values.
		result += (*copy);
		copy++;
	}

	return result; // Return the result.
}


/// <summary>
/// Calculates the sum of all values between two passed in map<>-iterators. Extends the list and vector support of the Sum(iter1, iter2) function for maps. Includes the value of start, excludes the value of end.
/// </summary>
/// <typeparam name="T1">The key type of the map.</typeparam>
/// <typeparam name="T2">The value type of the map.</typeparam>
/// <param name="start">The first iterator. Has to be the "lower bound" one.</param>
/// <param name="end">The second iterator. "Has to be the "upper bound" one.</param>
/// <returns></returns>
template <typename T1, typename T2> double Sum(const typename std::map<T1, T2>::const_iterator& start, const typename std::map<T1, T2>::const_iterator& end);

template <typename T1, typename T2>
double Sum(const typename std::map<T1, T2>::const_iterator& start, const typename std::map<T1, T2>::const_iterator& end) {
	typename std::map<T1, T2>::const_iterator copy = start;
	double result{};

	while (copy != end) {
		result += (*copy).second;
		copy++;
	}
	return result;
}

#endif //QUANTNET_HW_SUM_H