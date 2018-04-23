#include "Vector.h"
#include "VectorUtils.h"
#include <iostream>
#include <string>

using namespace std;

int intArr[] = {12, 23, 45};
string strArr[] = {"Apples", "Oranges", "Pears"};

void Test01();
void Test02();
void Test03();
void Test04();
void Test05();
void Test06();
void Test07();
void Test08();
void Test09();
void Test10();
void Test11();
void Test12();
void Test13();

int main()
{
    Test01();
    Test02();
    Test03();
    Test04();
    Test05();
    Test06();
    Test07();
    Test08();
    Test09();
    Test10();
    Test11();//Test SetArray
    Test12();
    Test13();

    return 0;
}

void Test01()//Test constructor intialises variables
{
    cout << "----------TEST01----------" << endl;

    Vector<int> testVec;

    printIntVec(testVec);
}

void Test02()//Test SetSize
{
    cout << "----------TEST02----------" << endl;

    Vector<int> testVec;

    testVec.SetSize(10);

    printIntVec(testVec);
}

void Test03()//Test 0 with SetSize
{
    cout << "----------TEST03----------" << endl;

    Vector<int> testVec;

    if(!testVec.SetSize(0))
    {
        cout << "Zero or less!!!" << endl;
    }

    printIntVec(testVec);
}

void Test04()//Test CopyVec
{
    cout << "----------TEST04----------" << endl;

    Vector<int> testVec, testVec02;

    testVec.SetArray(intArr, 3);

    if(testVec02.CopyVec(testVec))
    {
        cout << "Vector copied" << endl;
    }

    printIntVec(testVec);
}

void Test05()//Test constructor with size parameter
{
    cout << "----------TEST05----------" << endl;

    Vector<int> testVec(11);

    printIntVec(testVec);
}

void Test06()//Test Copy constructor
{
    cout << "----------TEST06----------" << endl;

    Vector<int> testVec;

    testVec.SetArray(intArr, 3);

    Vector<int> testVec02(testVec);

    printIntVec(testVec);
}

void Test07()//Test Overloaded [] const
{
    cout << "----------TEST07----------" << endl;

    Vector<int> testVec01;
    testVec01.SetArray(intArr, 3);

    const Vector<int> testVec02(testVec01);

        //Test parameters
    cout << testVec02[1] << endl;


    printIntVec(testVec02);
}


void Test08()//Test overloaded operator []
{
    cout << "----------TEST08----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 3; i++)
    {
        testVec[i] = i;
    }

    for(int i = 0; i < 3; i++)
    {
        testVec[i] = i + 10;
    }

    printIntVec(testVec);
}

void Test09()//Test GetArray
{
    cout << "----------TEST09----------" << endl;

    Vector<int> testVec;
    int *testArr;

    testVec.SetArray(intArr, 3);
    testVec.GetArray(testArr);

    for(int i = 0; i < 3; i++)
    {
        cout << testArr[i] << endl;
    }
}

void Test10()//Test SetArray
{
    cout << "----------TEST10----------" << endl;

    Vector<string> testVec(3);

    if(testVec.SetArray(strArr, 3))
        printIntVec(testVec);
}

void Test11()//Test GetLength and Size
{
    cout << "----------TEST11----------" << endl;

    Vector<string> testVec;

    testVec.SetArray(strArr, 3);

    cout << testVec.GetLength() << endl;
    cout << testVec.GetSize() << endl;
}

void Test12()//Test overloaded = operator
{
    cout << "----------TEST12----------" << endl;

    Vector<string> testVec01, testVec02;

    testVec01.SetArray(strArr, 3);

    testVec02 = testVec01;

    printIntVec(testVec02);
}

void Test13()//Test Resize
{
    cout << "----------TEST13----------" << endl;

    Vector<string> testVec;

    testVec.SetArray(strArr, 3);

    testVec.Resize(20);
    printIntVec(testVec);
}
