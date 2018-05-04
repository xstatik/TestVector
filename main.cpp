#include "Vector.h"
#include "VectorUtils.h"
#include "Date.h"
#include <iostream>
#include <string>


using namespace std;

int intArr[] = {12, 23, 45};
string strArr[] = {"Apples", "Oranges", "Pears"};

void Test01();//Test constructor intialises variables
void Test02();//Test SetSize
void Test03();//Test 0 with SetSize
void Test04();//Test CopyVec
//void Test05();//Test constructor with size parameter - Removed
void Test06();//Test Copy constructor
void Test07();//Test Overloaded [] const
void Test08();//Test overloaded operator []
void Test09();//Test GetArray
void Test10();//Test SetArray
void Test11();//Test GetLength and Size
void Test12();//Test overloaded = operator
void Test13();//Test Resize

int main()
{
    Test01();//Test constructor intialises variables
//    Test02();//Test SetSize
//    Test03();//Test 0 with SetSize
//    Test04();//Test CopyVec
//    Test05();//Test constructor with size parameter - Removed
    Test06();//Test Copy constructor
    Test07();//Test Overloaded [] const
    Test08();//Test overloaded operator []
//    Test09();//Test GetArray
//    Test10();//Test SetArray
    Test11();//Test GetLength and Size
    Test12();//Test overloaded = operator
//    Test13();//Test Resize

    return 0;
}

void Test01()//Test constructor intialises variables
{
    cout << "----------TEST01----------" << endl;

    Vector<int> testVec;

    testVec[0] = 10;

    testVec.GetSize();
    testVec.GetLength();

    printIntVec(testVec);
}

void Test06()//Test Copy constructor
{
    cout << "----------TEST06----------" << endl;

    Vector<int> testVec;

    testVec[3] = 10;

    Vector<int> testVec02(testVec);

    printIntVec(testVec02);
}

void Test07()//Test Overloaded [] const
{
    cout << "----------TEST07----------" << endl;

    Vector<int> testVec01;
    testVec01[0] = 10;

    const Vector<int> testVec02(testVec01);

        //Test parameters
    cout << testVec02[0] << endl;


    printIntVec(testVec02);
}


void Test08()//Test overloaded operator []
{
    cout << "----------TEST08----------" << endl;

    Vector<int> testVec;

    for(int i = 0; i < 3; i++)
    {
        testVec[i] = i + 10;
    }

    printIntVec(testVec);
}

void Test11()//Test GetLength and Size
{
    cout << "----------TEST11----------" << endl;

    Vector<string> testVec;

    testVec[30] = 10;

    cout << testVec.GetLength() << endl;
    cout << testVec.GetSize() << endl;
}

void Test12()//Test overloaded = operator
{
    cout << "----------TEST12----------" << endl;

    Vector<string> testVec01, testVec02;

    testVec01[10] = "POP";

    testVec02 = testVec01;

    printIntVec(testVec02);
}


