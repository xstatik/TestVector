#include "Vector.h"
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
    Test11();

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

void Test03()//Test 0 with SetSize
{
    cout << "----------TEST03----------" << endl;

    Vector<int> testVec;

    if(!testVec.SetSize(0))
    {
        cout << "Zero or less!!!" << endl;
    }

    testVec.print();
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

    testVec02.print();
}

void Test05()//Test constructor with size parameter
{
    cout << "----------TEST05----------" << endl;

    Vector<int> testVec(11);

    testVec.print();
}

void Test06()//Test Copy constructor
{
    cout << "----------TEST06----------" << endl;

    Vector<int> testVec(17);
    Vector<int> testVec02(testVec);

    testVec02.print();
}

void Test07()//Test PushBack
{
    cout << "----------TEST07----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 3; i++)
    {
        testVec.PushBack(i);
    }

    testVec.print();
}

void Test08()//Test PushBack range
{
    cout << "----------TEST08----------" << endl;

    Vector<int> testVec(2);

    for(int i = 0; i < 4; i++)
    {
        if(testVec.PushBack(i))
            cout << "Inside Range" << endl;
        else
            cout << "Outside Range" << endl;
    }

    testVec.print();
}

void Test09()//Test GetItem
{
    cout << "----------TEST09----------" << endl;

    Vector<int> testVec(3);
    int x;

    for(int i = 0; i < 3; i++)
    {
        testVec.PushBack(i);
        testVec.GetItem(x, i);
        cout << x << endl;
    }
}

void Test10()//Test GetLength and GetSize
{
    cout << "----------TEST10----------" << endl;

    Vector<int> testVec(3);

    for(int i = 0; i < 2; i++)
    {
        testVec.PushBack(i);
    }

    cout << testVec.GetLength() << endl;
    cout << testVec.GetSize() << endl;
}

void Test11()//Test with String
{
    cout << "----------TEST11----------" << endl;

    Vector<string> testVec(3);
    string testString = "String 0";
    string emptyStr;

    for(int i = 0; i < 3; i++)
    {
        testVec.PushBack(testString);
        testVec.GetItem(emptyStr, i);
        cout << emptyStr << i << endl;
    }
}
