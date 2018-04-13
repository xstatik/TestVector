#include "Vector.h"
#include <iostream>

using namespace std;

void printIntVec(Vector<int> &intArr)
{
    int *ptr;

    cout << "Length = " << intArr.GetLength() << endl;
    cout << "Size = " << intArr.GetSize() << endl;

    intArr.GetArray(ptr);
    if(ptr == NULL)
    {
        cout << "Array = NULL" << endl;
    }
    else
    {
        cout << "NOT NULL" << endl;
    }

    if(ptr != NULL)
    {
        for(int i = 0; i < intArr.GetLength(); i++)
        {
            cout << "Element " << i << " is: " << ptr[i] << endl;
        }
    }

};
