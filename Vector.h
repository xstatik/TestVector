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
	 * @todo OK. Better. Next AddItem.
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

        void print();


/*            /**
            * @brief  Sets array and returns true if successful.
            *
            * Creates dynamic array
            * Copies array newVec
            * Checks if m_theArray is NULL
            * Checks for available heap memory
            *
            * @param  newT the array to be saved
            * @param arraySize size of array to be copied.
            * @pre m_theArray must be NULL, and enough heap memory must be available to return true
            * @post an array the same as newT is created.
            */
/*         bool SetArray(const T *newT, const int arraySize);
            /**
            * @brief  Copies m_theArray and retruns a pointer to it.
            *
            * Creates a copy of the m_theArray variable and returns a pointer to it.
            *
            * @post an array the same as m_theArray is created and a pointer to it returned.
            */
 /*        T* GetArray() const;
            /**
            * @brief  Copies another Vector Object.
            *
            * Calls SetArray
            * Checks if newVec.m_theArray is NULL and if newVec.m_arrayLength > 0
            *
            * @param  newVec
            * @pre new.Vec.m_theArray must not be NULL, and newVec.arrayLength > 0 to return true
            * @post an array the same as newVec is created.
            */
 /*        bool Copy(Vector<T> *newVec);
            /**
            * @brief  Retrieves the size of the array.
            *
            * Returns m_arraySize
            *
            * @return int
            */
 /*        int GetSize() const;
        /**
            * @brief  Retrieves the length of the array.
            *
            * Returns m_arrayLength
            *
            * @return int
            */
 /*        int GetLength() const;

        T& operator[](int index);
        const T& operator[](int index) const;
*/


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
        }

        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
Vector<T>::Vector(Vector<T> &newVec)
{
    CopyVec(newVec);
}

/*
template <class T>
bool Vector<T>::SetArray(const T *newT, const int arraySize)
{
    if(m_theArray == NULL)
    {
        m_arraySize = arraySize;
        m_theArray = new T(m_arraySize);
    }

    if(m_theArray == NULL)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < m_arraySize; i++)
        {
            m_theArray[i] = newT[i];
            m_arrayLength++;
        }

        return true;
    }
}

template <class T>
T* Vector<T>::GetArray() const
{
    T *newT = NULL;

    newT = new T(m_arraySize);

    if(newT == NULL)
    {
        return newT;
    }
    else
    {
        for(int i = 0; i < m_arraySize; i++)
        {
            newT[i] = m_theArray[i];
        }
    }
    return newT;
}

template <class T>
bool Vector<T>::Copy(Vector<T> *newVec)
{
    if(newVec->m_theArray != NULL && newVec->m_arrayLength > 0)
    {
        return SetArray(newVec->GetArray(), newVec->m_arraySize);
    }
    else
    {
        return false;
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

template <class T>
T& Vector<T>::operator[](int index)
{
    if(0 <= index && index < m_arraySize)
        return m_theArray[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const
{
    if(0 <= index && index < m_arraySize)
        return m_theArray[index];
}
*/

#endif // VECTOR_H
