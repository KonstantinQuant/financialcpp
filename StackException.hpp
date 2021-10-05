//
// Created by Konstantin Kuchenmeister on 07/11/2021
//
// ArrayException.hpp
//
// Header file for the ArrayException Objects that can occur and be thrown.
//

#ifndef QUANTNET_HW_STACK_EXCEPTION_H
#define QUANTNET_HW_STACK_EXCEPTION_H

using namespace std;
#include <iostream>
#include <sstream>
#include <string>

namespace KonstantinK {
	namespace StackExceptions {

		class StackException {
		public:
			virtual const string GetMessage() const = 0;
		};

		class StackFullException : public StackException {
		public:
			// Default constructor
			StackFullException() {
				cout << "StackFullException has been created." << endl;
			}

			// Destructor
			~StackFullException() {
				cout << "StackFullException object has been destructed." << endl;
			}

			const string GetMessage() const {
				stringstream ss;
				ss << "StackFullException: The stack is full. Cannot perform push operation on full stack.";
				return ss.str();
			}
		};


		class StackEmptyException : public StackException {
		public:
			// Default constructor
			StackEmptyException() {
				cout << "StackEmptyException has been created." << endl;
			}

			// Destructor
			~StackEmptyException() {
				cout << "StackEmptyException object has been destructed." << endl;
			}

			const string GetMessage() const {
				stringstream ss;
				ss << "StackEmptyException: The stack is empty. Cannot perform pop operation on empty stack.";
				return ss.str();
			}
		};
	}
}

#endif