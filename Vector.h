//Vector.h
//Using git for version control

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------

#include <iostream>
#include <cassert>

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
	 * @todo Remove print and add VectorUtilies and add overloaded = and maybe remove cassert.
	 *
	 * @bug None yet...
	 */

template <class T>

class Vector
{
    public:
        Vector();
        ~Vector(){Clear();}
            /**
            * @brief  Constructor with size parameter
            *
            * Creates a Vector class object
            *
            * @param  arrSize size of array to be created.
            * @pre arrSize must be above zero
            * @post a Vector object of size specified is created.
            */
        Vector(const int arrSize);
            /**
            * @brief  Copy Constructor
            *
            * Copies another vector
            *
            * @param  newVec the object to be copied.
            */
        Vector(Vector<T> &newVec);
            /**
            * @brief  Deletes dynamic memory and clears variables
            *
            * This function will delete the dynamic memrory and and clear the variables.
            *
            * @return void
            */
        void Clear();
            /**
            * @brief  Sets the size of the Vector object
            *
            *Creates a Vector object of the specified size
            *
            * @param  arrSize size of Vector to be created.
            * @pre arrSize must be above zero otherwise an empty Vector is created
            * @post a Vector of size specified is created
            */
        bool SetSize(int arrSize);
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
        bool CopyVec(Vector<T> &newVec);
            /**
            * @brief  Adds element to end of Vector
            *
            * Adds an element to the Vector obeject and increases the size
            *
            * @param  newT element to be added.
            * @pre The Vector must not be empty
            * @post newT is added to the end of the Vector.
            */
        bool AddItem(const T &newT);

        void print();
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

    private:
            ///int to hold the size of the array.
        int m_arraySize;
            ///int to hold the current length of the array.
        int m_arrayLength;
            ///T pointer to hold the base address of the array.
        T *m_theArray;

};

template <class T>
Vector<T>::Vector()
{
    m_arraySize = 0;
    m_arrayLength = 0;
    m_theArray = NULL;
}

template <class T>
Vector<T>::Vector(const int arrSize)
{
    m_arraySize = 0;
    m_arrayLength = 0;
    m_theArray = NULL;

    SetSize(arrSize);
}

template <class T>
Vector<T>::Vector(Vector<T> &newVec)
{
    CopyVec(newVec);
}

template <class T>
void Vector<T>::Clear()
{
    m_arraySize = 0;
    m_arrayLength = 0;

    if(m_theArray != NULL)
    {
        delete [] m_theArray;
    }

    m_theArray = NULL;
}

template <class T>
void Vector<T>::print()
{
    cout << "Length = " << m_arrayLength << endl << "Size = " << m_arraySize << endl;
    if(m_theArray != NULL)
    {
        cout << "NOT NULL" << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }
    if(m_arrayLength > 0)
    {
        cout << "ARRAY NOT EMPTY" << endl;
        for(int i = 0; i < m_arrayLength; i++)
        {
            cout << m_theArray[i] << endl;
        }
    }
}

template <class T>
bool Vector<T>::SetSize(int arrSize)
{
    if(m_theArray != NULL)
    {
        Clear();//Clears Vector
    }

    if(m_theArray == NULL && arrSize > 0)
    {
        m_arraySize = arrSize;
        m_theArray = new T[m_arraySize];
    }

    if(m_theArray == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }

}

template <class T>
bool Vector<T>::CopyVec(Vector<T> &newVec)
{
    if(SetSize(newVec.m_arraySize))
    {
        for(int i = 0; i < newVec.m_arrayLength; i++)
        {
            m_theArray[i] = newVec.m_theArray[i];
            m_arrayLength++;
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool Vector<T>::AddItem(const T &newT)
{
    if(m_arrayLength < m_arraySize && m_theArray != NULL)
    {
        m_theArray[m_arrayLength] = newT;
        m_arrayLength++;

        return true;
    }

    return false;
}

template <class T>
int Vector<T>::GetSize() const
{
    return m_arraySize;
}

template <class T>
int Vector<T>::GetLength() const
{
    return m_arrayLength;
}

template <class T>
const T& Vector<T>::operator[](int index) const
{
    assert(index >= 0 && index < m_arrayLength);

    return m_theArray[index];
}

template <class T>
T& Vector<T>::operator[](int index)
{
    assert(index >= 0 && index < m_arrayLength);

    return m_theArray[index];
}

#endif // VECTOR_H
