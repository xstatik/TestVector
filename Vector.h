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
	 * @todo copy constructor
	 *
	 * @bug None yet...
	 */

template <class T>

class Vector
{
    public:
        Vector(){Clear();}
        ~Vector(){Clear();}
            /**
            * @brief  Constructor with size parameter
            *
            * Creates an array of size initSize
            * Checks if initSize is greater than 0, if not than m_arrySize is set to 0
            * and Clear() is run.
            *
            * @param  initSize size of array to be created.
            * @return void
            * @pre initSize must be non-zero otherwise Clear() is run.
            * @post an array of size initSize is created and m_arraySize is set to initSize.
            */
        Vector(const int initSize);
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
void Vector<T>::Clear()
{
    m_arraySize = 0;
    m_arrayLength = 0;

    if(m_theArray != NULL)
    {
        delete m_theArray;
    }

    m_theArray = NULL;
}

template <class T>
Vector<T>::Vector(int const initSize)
{
    if(initSize <= 0)
    {
        Clear();
    }
    else
    {
        m_arraySize = initSize;
        m_arrayLength = 0;
        m_theArray = new T[initSize];
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
