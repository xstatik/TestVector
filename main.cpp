#include "Vector.h"
#include <iostream>

using namespace std;

void Test02();
void Test03();
void Test04();

int main()
{
    Test02();
    Test03();
    Test04();

    return 0;
}

void Test02()
{
    cout << "------TEST02------" << endl << endl;

    Vector<int> intVec;

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;
}

void Test03()
{
    cout << "------TEST03------" << endl << endl;

    Vector<int> intVec(25);

    cout << "Length = " << intVec.GetLength() << endl;
    cout << "Size = " <<intVec.GetSize() << endl;
}

void Test04()
{
    cout << "------TEST04------" << endl << endl;

    Vector<int> intVec01(95);
    Vector<int> intVec02(intVec01);

    cout << "Length = " << intVec02.GetLength() << endl;
    cout << "Size = " <<intVec02.GetSize() << endl;

}
