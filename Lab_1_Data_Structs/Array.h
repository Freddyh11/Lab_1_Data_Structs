//
//  Array.h
//  Lab_1
//
//  Created by Freddy Hernandez on 1/12/23.
//

#ifndef Array_h
#define Array_h

#include <iostream>
#include <string>
#include "Exceptions.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


template <typename T>
class Array {
private:
    T* m_array;
    int m_start_index;
    int m_length;
    int m_newArray;

public:
    Array() : m_array(nullptr), m_start_index(0), m_length(0) {};//default constructor
    
    Array(int length, int start_index = 0);                            //constructor
    Array(const Array<T>& copy);                                    //copy constructor
    Array(Array<T>&& move) noexcept;                                            //move constructor

    ~Array();                                        //destructor

    Array<T>& operator = (const Array<T>& copy);    //overloaded copy assignment operator
    Array<T>& operator = (Array<T>&& move) noexcept;    //overloaded move assignment operator
    T& operator [] (const int);                        //overloaded subscript operator

    const int getStartIndex();                        //gets start index
    void setStartIndex(const int start_index);        //sets start index
    const int getLength();                            //gets length of array
    void setLength(int length);                        //sets length of array
};

template<typename T>
Array<T>::Array(int length, int start_index) :m_start_index(start_index), m_length(length)
{
   m_array = new T[length]; // create dynamic mem for array
}

template<typename T>
Array<T>::Array(const Array<T>& copy) // copy construct
{
    if(this != &copy)
        {
            m_length = copy.m_length;
            m_start_index = copy.m_start_index;
            m_array = new T[m_length];
            for (int i = 0; i < m_length; i++)
            {
                m_array[i] = copy.m_array[i];
            }
        }
}

template<typename T>
Array<T>::Array(Array<T>&& move) noexcept 
{
    m_length = move.m_length;
       m_start_index = move.m_start_index;
       m_array = move.m_array;
    
       move.m_array = nullptr;
       move.m_length = 0;
       move.m_start_index = 0;
}

template<typename T>
Array<T>::~Array()
{
    delete []m_array;
}

template<typename T>
Array<T>& Array<T>::operator = (const Array<T>& copy)
{
    if (this != &copy) {
            delete[] m_array;
            m_array = new T[m_length];
            m_start_index = copy.m_start_index;
            m_length = copy.m_length;
            for (int i = 0; i < m_length; i++) {
                m_array[i] = copy.m_array[i];
            }
        }
        return *this;
}

template<typename T>
Array<T>& Array<T>::operator = (Array<T>&& move) noexcept
{
    if (this != &move)
        {
            // deallocate current resources
            delete[] m_array;

            // transfer ownership of resources
            m_array = move.m_array;
            m_length = move.m_length;
            m_start_index = move.m_start_index;

            // reset moved-from object
            move.m_array = nullptr;
            move.m_length = 0;
            move.m_start_index = 0;
        }
        return *this;
}

template<typename T>
T& Array<T>::operator [] (const int index)
{
    return m_array[index - m_start_index];
}


template<typename T>
const int Array<T>::getStartIndex()
{
    return m_start_index;
}

template<typename T>
void Array<T>::setStartIndex(const int start_index)
{
    m_start_index = start_index;
}

template<typename T>
const int Array<T>::getLength()
{
    return m_length;
}

template<typename T>
void Array<T>::setLength(int length)
{
    if (length <= 0) // check to see if length of array is < 0
    {
       throw Exception("ERROR: Array Lengths cannot be Negative!"); // Exception should be caught
    }
    m_length = length;
    
}


#endif /* Array_h */
