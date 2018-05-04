//Vector.h
//Author: Wade Davidson
//Using git for version control

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//---------------------------------------------------------------------------------

/**
	 * @class Vector
	 * @brief  A template class to hold a dynamic array
	 *
	 *  This class holds information in a dynamic array for a set of variables.
	 *
	 * @author Wade Davidson
	 * @version 01
	 * @date 10/04/2018 Wade Davidson, Created and pushed to git
	 *
	 * @author Wade Davidson
	 * @version 02
	 * @date 10/04/2018 Wade Davidson, added variables, constructor deconstructor and Clear function.
	 *
	 * @author Wade Davidson
	 * @version 03
	 * @date 10/04/2018 Wade Davidson, added GetLength() and SetLength() and add TestPlan. Tested.
	 *
	 * @author Wade Davidson
	 * @version 04
	 * @date 10/04/2018 Wade Davidson, added constructor with size paramter. Tested.
	 *
	 * @author Wade Davidson
	 * @version 05
	 * @date 10/04/2018 Wade Davidson, added copy constructor. Tested.
	 *
	 * @author Wade Davidson
	 * @version 06
	 * @date 10/04/2018 Wade Davidson, added SetArray and GetArray and tested. Changed copy constructor.
	 *
	 * @author Wade Davidson
	 * @version 07
	 * @date 11/04/2018 Wade Davidson, cleared functions starting again. Print added to test.
	 *
	 * @author Wade Davidson
	 * @version 08
	 * @date 11/04/2018 Wade Davidson, created Setsize and tested.
	 *
	 * @author Wade Davidson
	 * @version 09
	 * @date 11/04/2018 Wade Davidson, created VecCopy and tested.
	 *
	 * @author Wade Davidson
	 * @version 10
	 * @date 11/04/2018 Wade Davidson, fixed copy constructor and constructor with size parameter. Tested.
	 *
	 * @author Wade Davidson
	 * @version 12
	 * @date 11/04/2018 Wade Davidson, added PushBack and GetItem functions and tested.
	 *
	 * @author Wade Davidson
	 * @version 13
	 * @date 11/04/2018 Wade Davidson, added GetSize and GetLength back in and tested.
	 *
	 * @author Wade Davidson
	 * @version 13
	 * @date 11/04/2018 Wade Davidson, teseted with string and added to test plan.
	 *
	 * @author Wade Davidson
	 * @version 14
	 * @date 13/04/2018 Wade Davidson, changed to addItem and add overloaded [] operator. Tested.
	 * @date 13/04/2018 Wade Davidson, removed GetItem. Made changes to doxygen comments
	 *
	 * @author Wade Davidson
	 * @version 15
	 * @date 13/04/2018 Wade Davidson, added GetArray. Tested. Chaged test paln as VectorUtils.h was added.
	 * @date 13/04/2018 Wade Davidson, print function removed.
	 *
	 * @author Wade Davidson
	 * @version 16
	 * @date 17/04/2018 Wade Davidson, added overloaded =. Tested.
	 *
	 * @author Wade Davidson
	 * @version 17
	 * @date 18/04/2018 Wade Davidson, added SetArray and Resize. Tested.
	 *
	 * @author Wade Davidson
	 * @version 18
	 * @date 23/04/2018 Wade Davidson, Cleaned it up a little. Added new test plan.
	 *
	 * @author Wade Davidson
	 * @version 19
	 * @date 04/05/2018 Wade Davidson, changed to STL Vector.
	 *
	 * @todo ...
	 *
	 * @bug None yet...
	 */

template <class T>

class Vector
{
    public:
        Vector();
            /**
            * @brief  Copy Constructor
            *
            * Copies another vector
            *
            * @param  newVec the object to be copied.
            */
        Vector(Vector<T> &newVec);
            /**
            * @brief  Copies another Vector
            *
            * Copies the elements of one Vector Object to another
            * Returns true if successful
            *
            * @param  newVec the Vector to be copied
            * @pre newVec must not be empty otherwise it will return false
            * @post a copy of newVec is copied
            */
        void CopyVec(const Vector<T> &newVec);
            /**
            * @brief  Retrieves the size of the Vector.
            *
            * @return int
            */
        int GetSize() const;
            /**
            * @brief  Retrieves the amount of elements stored in the array.
            *
            * @return int
            */
        int GetLength() const;
            /**
            * @brief  Overloaded [] operator
            *
            * @param  index the index of the element to access
            * @pre must be within the length of the Vector
            * @return T&
            */
        const T& operator[](int index) const;
            /**
            * @brief  Overloaded [] operator
            *
            * @param  index the index of the element to access
            * @pre must be within the length of the Vector
            * @return T&
            */
        T& operator[](int index);
            /**
            * @brief  Overloaded = operator
            *
            * Assigns one Vector to another
            *
            * @param  coVec the Vector to be assigned
            * @return Vector<T>&
            */
        const Vector<T>& operator=(const Vector<T> &coVec);


    private:
            ///Variable to store amount of elements
        unsigned m_arrLength;
            ///T pointer to hold the base address of the array.
        vector<T> m_theArray;
            /**
            * @brief  Resizes the Vector and keeps the elements
            *
            * @param  newSize the size you desire
            * @post Vector is the same but bigger.
            */
};

template <class T>
Vector<T>::Vector()
    : m_arrLength(0), m_theArray()
{}

template <class T>
Vector<T>::Vector(Vector<T> &newVec)
    : m_arrLength(0), m_theArray()
{
    CopyVec(newVec);
}

template <class T>
void Vector<T>::CopyVec(const Vector<T> &newVec)
{
    m_arrLength = newVec.m_arrLength;
    m_theArray = newVec.m_theArray;
}

template <class T>
int Vector<T>::GetSize() const
{
    return m_theArray.capacity();
}

template <class T>
int Vector<T>::GetLength() const
{
    return m_arrLength;
}

template <class T>
const T& Vector<T>::operator[](int index) const
{
    assert(index >= 0 && index < m_arrLength);

    return m_theArray[index];
}

template <class T>
T& Vector<T>::operator[](int index)
{
    assert(index >= 0);

    if(m_theArray.capacity() == 0)
    {
        m_theArray.resize(5);
    }

    while(m_theArray.capacity() <= index)
    {
        m_theArray.resize(1.5 * m_theArray.capacity());
    }

    m_arrLength = index + 1;

    return m_theArray[index];
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T> &coVec)
{
    CopyVec(coVec);

    return *this;
}

#endif // VECTOR_H
