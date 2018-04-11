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
    Test02();
    Test03();
    Test04();


    return 0;
}

void Test01()//Test constructor intialises variables
{
    cout << "----------TEST01----------" << endl;

    Vector<int> testVec;

    testVec.print();
}

void Test02()//Test set size
{
    cout << "----------TEST02----------" << endl;

    Vector<int> testVec;

    testVec.SetSize(10);

    testVec.print();
}

void Test03()//Test set size
{
    cout << "----------TEST03----------" << endl;

    Vector<int> testVec;

    if(!testVec.SetSize(0))
    {
        cout << "Zero or less!!!" << endl;
    }

    testVec.print();
}

void Test04()//Test set size
{
    cout << "----------TEST04----------" << endl;

    Vector<int> testVec, testVec02;

    testVec.SetSize(10);
    if(testVec02.CopyVec(testVec))
    {
        cout << "Vector copied" << endl;
    }

    testVec02.print();
}
