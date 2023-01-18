//
//  Exceptions.h
//  Lab_1
//
//  Created by Freddy Hernandez on 1/12/23.
//

#ifndef Exceptions_h
#define Exceptions_h

#include <string>
#include <iostream>
#include <exception>

using std::string;
using std::exception;
using std::ostream;

class Exception : public exception {

    string m_msg;

public:
    Exception() noexcept : m_msg("Unknown Error") {};                    //default constructor
    Exception(const string& msg) : m_msg(msg) {};                    //constructor with parameters
    Exception(const Exception& move) noexcept : m_msg(move.m_msg) {};    //copy constructor
    Exception(Exception&& copy) noexcept;                                //move constructor

    Exception& operator = (const Exception& move) noexcept;                    //copy assignment operator
    Exception& operator = (Exception&& copy) noexcept;                        //move assignment operator

    const string getMessage() { return m_msg; }                    //gets exception message
    void setMessage(const string& message) { m_msg = message; }    //sets exception message

    friend std::ostream& operator << (std::ostream&, const Exception&);    //overloaded output operator
};


Exception::Exception(Exception&& copy) noexcept = default; // initalized to defauly

Exception& Exception::operator = (const Exception& move) noexcept
{
    this-> m_msg = move.m_msg; //move construct
    return *this;
}

Exception& Exception::operator = (Exception&& copy) noexcept
{
    m_msg = copy.m_msg; //copy construct
    return *this;
}

ostream& operator << (ostream& out, const Exception& except)
{
    out << except.m_msg;
    return out;
}


#endif /* Exceptions_h */
