#include "Vector.h"
#include <iostream>

using namespace std;

template <class T>
void printIntVec(const Vector<T> &intArr)
{
    cout << "Length = " << intArr.GetLength() << endl;
    cout << "Size = " << intArr.GetSize() << endl;


    for(int i = 0; i < intArr.GetLength(); i++)
    {
        cout << "Element " << i << " is: " << intArr[i] << endl;
    }
}




