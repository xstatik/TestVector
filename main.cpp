#include "Vector.h"
#include <iostream>

using namespace std;

void Test2();

int main()
{
    Test2();

    return 0;
}

void Test2()
{
    Vector<int> intVec;

    cout << intVec.GetLength() << endl;
    cout << intVec.GetSize() << endl;
}
