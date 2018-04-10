#include "Vector.h"
#include <iostream>

using namespace std;

void Test2();
void Test3();

int main()
{
    Test2();
    Test3();

    return 0;
}

void Test2()
{
    cout << "------TEST02------" << endl << endl;

    Vector<int> intVec;

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;
}

void Test3()
{
    cout << "------TEST03------" << endl << endl;

    Vector<int> intVec(25);

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;
}
