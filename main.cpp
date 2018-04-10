#include "Vector.h"
#include <iostream>

using namespace std;

void Test02();
void Test03();
void Test04();
void Test05();
void Test06();

int main()
{
    Test02();
    Test03();

    return 0;
}

void Test02()//Test GetLength() && GetSize()
{
    cout << "------TEST02------" << endl << endl;

    Vector<int> intVec;

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;
}

void Test03()//Test SetArray
{
    cout << "------TEST03------" << endl << endl;

    Vector<int> intVec;
    int intArray01[] = {3,4,5,6,7,8};
    int *intArray02 = NULL;

    intVec.SetArray(intArray01, 6);

    intArray02 = intVec.GetArray();

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;

    for(int i = 0; i < 6; i++)
    {
        cout << *(intArray02 + i) << endl;
    }

    delete [] intArray02;
    intArray02 = NULL;
}

