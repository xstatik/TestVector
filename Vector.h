//Vector.h
//Using git for version control

#ifndef VECTOR_H
#define VECTOR_H

//---------------------------------------------------------------------------------

#include <iostream>

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
	 * @todo Not sure...
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
            * Creates an array of size arrSize
            * Calls SetSize()
            *
            * @param  arrSize size of array to be created.
            * @pre arrSize must be non-zero
            * @post a Vector object of size arrSize is created.
            */
        Vector(const int arrSize);
            /**
            * @brief  Copy Constructor
            *
            * Calls CopyVec()
            *
            * @param  newVec object to be copied.
            */
        Vector(Vector<T> &newVec);
            /**
            * @brief  Deletes dynamic memory and clears variables
            *
            * This function will delete the dynamic memrory and set m_theArray to NULL
            * and set m_arraySize and m_arrayLength to 0.
            *
            * @return void
            */
        void Clear();
            /**
            * @brief  Creates the array the size of arrSize
            *
            * Creates an array of size arrSize
            * Checks if arrSize is greater than 0, if not than it returns false
            *
            * @param  initSize size of array to be created.
            * @pre arrSize must be non-zero otherwise and m_theArray must be NULL
            * @post an array of size arrSize is created
            */
        bool SetSize(int arrSize);
            /**
            * @brief  Copies anothe Vector
            *
            * Creates an array of size arrSize
            * Checks if arrSize is greater than 0, if not than it returns false
            * Copies elements to new Vector array if their is any
            * Returns true if successful
            *
            * @param  newVec the vector to be copied
            * @pre newVec must not be empty otherwise it will return false
            * @post a copy of newVec is created.
            */
        bool CopyVec(Vector<T> &newVec);
            /**
            * @brief  Adds element to end of Vector
            *
            * Sets last element to newT. Must be within the range of the Vector.
            * Returns true if successful
            *
            * @param  newT element to be added.
            * @pre list must not be full or m_theArray NULL.
            * @post newT is added to the end of the Vector.
            */
        bool PushBack(T &newT);
            /**
            * @brief  Retreives element from specified index
            *
            * Retreives element from specified index as long as it is 0 or above and less than length
            *
            * @param  newItem to retrieve the item.
            * @param  index to retrieve from
            * @pre index must be 0 or above and less than the length
            * @post item at index is retruned.
            */
        void GetItem(T &newItem, int index) const;

        void print();
            /**
            * @brief  Retrieves the size of the array.
            *
            * Returns m_arraySize
            *
            * @return int
            */
        int GetSize() const;
            /**
            * @brief  Retrieves the length of the array.
            *
            * Returns m_arrayLength
            *
            * @return int
            */
        int GetLength() const;
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
        m_theArray = new T(m_arraySize);
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
bool Vector<T>::PushBack(T &newT)
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
void Vector<T>::GetItem(T &newItem, int index) const
{
    if(index >= 0 && index < m_arrayLength)
    {
        newItem = m_theArray[index];
    }
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

#endif // VECTOR_H
