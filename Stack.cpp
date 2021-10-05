//
// Created by Konstantin Kuchenmeister on 17.07.21.
// 
// Stack.cpp 
//

#ifndef QUANTNET_HW_STACK_C
#define QUANTNET_HW_STACK_C

#include "Stack.hpp"

namespace KonstantinK {
    namespace Containers {

        /// <summary>
        /// Default constructor for a Stack. Will create a default T stack of the size 10. 
        /// </summary>
        /// <typeparam name="T">The generic type used for filling the stack.</typeparam>
        template <typename T, int size>
        Stack<T, size>::Stack() : m_current{ 0 }, m_stackData{ KonstantinK::Containers::Array<T>::Array(size) } {
            cout << "Stack has been created using the default constructor." << endl;
        }

        /// <summary>
        /// Copy constructor for the stack type.
        /// </summary>
        /// <typeparam name="T">The generic type used for filling the stack.</typeparam>
        /// <param name="source">The parameterized stack array using for copying.</param>
        template <typename T, int size>
        Stack<T, size>::Stack(const Stack<T, size>& source) {
            m_current = source.m_current;
            m_stackData = source.m_stackData;
            cout << "Stack has been created using the copy constructor." << endl;
        }

        /// <summary>
        /// Destructor for the stack type. Is called automatically.
        /// </summary>
        /// <typeparam name="T">The generic type used for filling the stack.</typeparam>
        template <typename T, int size>
        Stack<T, size>::~Stack() {
            cout << "Stack has been destructed" << endl;
        }

        /// <summary>
        /// Appends a element to the stack.
        /// Possible Exceptions are handled by the underlying array type.
        /// </summary>
        /// <typeparam name="T">The generic type used for filling the stack.</typeparam>
        /// <param name="element">The element that is pushed onto the stack.</param>
        template <typename T, int size>
        void Stack<T, size>::Push(const T& element) {
            try {
                m_stackData.SetElement(element, m_current);
                m_current++;
            }
            catch (KonstantinK::ArrayExceptions::ArrayException& ex) {
                throw KonstantinK::StackExceptions::StackFullException();
            }
        }

        /// <summary>
        /// A function that removes the element at the top of the stack.
        /// </summary>
        /// <typeparam name="T">The generic type T.</typeparam>
        /// <returns>Returns the reference of the popped element.</returns>
        template <typename T, int size>
        T Stack<T, size>::Pop() {
            try {
                T temp{};
                m_current--;
                temp = m_stackData[m_current];
                // When creating a stack of a chosen size, size number of elements on the stack are created with the default constructur.
                // If it has been changed over its lifetime, it is reset here.
                m_stackData[m_current] = T{}; // Reset the element at the popped index to default
                return temp;
            }
            catch (KonstantinK::ArrayExceptions::ArrayException& ex) {
                m_current = 0;
                throw KonstantinK::StackExceptions::StackEmptyException();
            }

        }

        /// <summary>
        /// Allows for assigning a stack object to another stack object.
        /// </summary>
        /// <typeparam name="T">The generic type T.</typeparam>
        /// <param name="source">The right hand object of the assignment.</param>
        /// <returns>Returns a reference to the this object.</returns>
        template <typename T, int size>
        Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source) {
           // if (m_stackData.Size() == source.m_stackData.Size()) { 
                if (this != &source) {
                    m_stackData.operator=(source.m_stackData);
                    m_current = source.m_current;
                }
                return *this;
           // }
           // else {
           //     throw KonstantinK::ArrayExceptions::IncompatibleSizeException();
            //}
            
        }
    }
}

#endif