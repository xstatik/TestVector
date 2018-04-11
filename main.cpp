#include "Vector.h"
#include <iostream>

using namespace std;

void Test01();
void Test02();
void Test03();
void Test04();
void Test05();
void Test06();

int main()
{
    Test01();


    return 0;
}

void Test01()
{
    Vector<int> testVec;

    testVec.print();
}
