//Vector.h
//Using git for version management

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
	 *  This class holds information in a dynamic array for a set of variables
	 *
	 * @author Wade Davidson
	 * @version 01
	 * @date 10/04/2018 Wade Davidson, Created and pushed to git
	 *
	 * @author Wade Davidson
	 * @version 02
	 * @date 10/04/2018 Wade Davidson, added variables, constructor deconstructor and Clear function.
	 *
	 *
	 * @todo Test constructor and create Testplan.
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
            * @brief  Deletes dynamic memory and clears variables
            *
            * This function will delete the dynamic memrory and set m_theArray to NULL
            * and set m_arraySize and m_arrayLength to 0.
            *
            * @return void
            */
        void Clear();

    private:
            ///unsigned int to hold the size of the array.
        unsigned m_arraySize;
            ///unsigned int to hold the current length of the array.
        unsigned m_arrayLength;
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



#endif // VECTOR_H
