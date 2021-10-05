// QUANTNET_HW_STACK_H
//
// Created by Konstantin Kuchenmeister on 17.07.21.
// 
// Stack.hpp 
//

#ifndef QUANTNET_HW_STACK_H
#define QUANTNET_HW_STACK_H
#include "Array.hpp"
#include "StackException.hpp"

namespace KonstantinK {
    namespace Containers {

        /// <summary>
        /// Stack data structure that can hold objects of numerous types and perform push and pop operations.
        /// </summary>
        /// <typeparam name="T">The generic type used for filling the stack.</typeparam>
        template <typename T, int size>
        class Stack {

        private:
            unsigned m_current;
            KonstantinK::Containers::Array<T> m_stackData;

        public:

            // Constructors and Destructors:
            Stack();
            Stack(const Stack<T, size>& source); // Copy constructor
            ~Stack();

            // Member functions:
            void Push(const T& element); // Store the element at the current position
            T Pop(); // Remove the element at the current position

            // Operators:
            Stack<T, size>& operator = (const Stack<T, size>& source);
        };
    }
}

#ifndef QUANTNET_HW_STACK_C
#include "Stack.cpp"
#endif

#endif // QUANTNET_HW_STACK_H
