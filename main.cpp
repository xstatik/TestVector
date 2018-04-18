#include "Vector.h"
#include "VectorUtils.h"
#include <iostream>
#include <string>

using namespace std;

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
void Test14();
void Test15();
void Test16();

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
    Test14();
    Test15();
    Test16();

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

    testVec.SetSize(10);
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

    Vector<int> testVec(3);

    for(int i = 0; i < 3; i ++)
        testVec.AddItem(i);

    Vector<int> testVec02(testVec);

    printIntVec(testVec);
}

void Test07()//Test AddItem
{
    cout << "----------TEST07----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 3; i++)
    {
        testVec.AddItem(i);
    }

    printIntVec(testVec);
}


void Test08()//Test overloaded operator []
{
    cout << "----------TEST08----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 3; i++)
    {
        testVec.AddItem(i);
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

    Vector<int> testVec(3);
    int *testArr;

    for(int i = 0; i < 3; i++)
    {
        testVec.AddItem(i);
    }

    testVec.GetArray(testArr);

    printIntVec(testVec);
}

void Test10()//Test Additem range
{
    cout << "----------TEST10----------" << endl;

    Vector<int> testVec(2);

    for(int i = 0; i < 4; i++)
    {
        if(testVec.AddItem(i))
            cout << "Inside Range" << endl;
        else
            cout << "Outside Range" << endl;
    }

    printIntVec(testVec);
}

void Test11()//Test SetArray
{
    cout << "----------TEST11----------" << endl;

    Vector<string> testVec(3);
    string strArr[] = {"Apples", "Oranges", "Pears"};

    if(testVec.SetArray(strArr, 3))
        printIntVec(testVec);
}

void Test12()//Test GetLength and GetSize
{
    cout << "----------TEST12----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 2; i++)
    {
        testVec.AddItem(i);
    }

    cout << testVec.GetLength() << endl;
    cout << testVec.GetSize() << endl;
}

void Test13()//Test with String
{
    cout << "----------TEST13----------" << endl;

    Vector<string> testVec(3);
    string testString = "String 0";
    string emptyStr;

    for(int i = 0; i < 3; i++)
    {
        testVec.AddItem(testString);
        cout << testVec[i] << i << endl;
    }
}

void Test14()//Test with String
{
    cout << "----------TEST14----------" << endl;

    Vector<string> testVec(3);
    Vector<string> testVec2;
    string testString = "String 0";

    for(int i = 0; i < 3; i++)
    {
        testString = testString + to_string(i);
        testVec.AddItem(testString);
        testString = "String 0";
    }

    testVec2 = testVec;

    printIntVec(testVec2);
}

void Test15()//Test with String
{
    cout << "----------TEST15----------" << endl;

    Vector<string> testVec(3);
    string strArr[] = {"Wade", "Meli", "Me"};

    if(testVec.SetArray(strArr, 3))
        printIntVec(testVec);

    if(!testVec.Resize(2))
    {
        cout << "Fail" << endl;
    }

    testVec.Resize(10);
    printIntVec(testVec);
}

void Test16()//Test with String
{
    cout << "----------TEST16----------" << endl;

    Vector<string> testVec(3);
    string testString = "Choose";
    string strArr[] = {"Wade", "Meli", "Me"};

    testVec.SetArray(strArr, 3);

    testString = testVec[2];

    printIntVec(testVec);
}
