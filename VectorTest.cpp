#include <iostream>
#include "Vector.h"

using namespace std;

string Test1CheckDefaultConstructor();
string Test2CheckAdd();
string Test3CheckCopyConstructor();
string Test4CheckRemoveLast();
string Test5CheckInsertAt();
string Test6CheckRemoveAT();
string Test7CheckRetrieveAt();
string Test8CheckReplaceAt();
string Test9CheckClearIsEmpty();
string Test10CheckResize();
string Test11CheckSize();
string Test12CheckBracketOperator();

int main()
{

    cout << "VECTOR CLASS TEST\n" << endl;
    cout << Test1CheckDefaultConstructor() << endl;
    cout << Test2CheckAdd() << endl;
    cout << Test3CheckCopyConstructor() << endl;
    cout << Test4CheckRemoveLast() << endl;
    cout << Test5CheckInsertAt() << endl;
    cout << Test6CheckRemoveAT() << endl;
    cout << Test7CheckRetrieveAt() << endl;
    cout << Test8CheckReplaceAt() << endl;
    cout << Test9CheckClearIsEmpty() << endl;
    cout << Test10CheckResize() << endl;
    cout << Test11CheckSize() << endl;
    cout << Test12CheckBracketOperator() << endl;

}

string Test1CheckDefaultConstructor()
{
    cout << "Test 1 - Default constructor correctly initializes data: ";
    Vector<int> marksArray;
    if ((marksArray.GetCapacity() == 5)
            && (marksArray.GetSize() == 0))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }

}

string Test2CheckAdd()
{
    cout << "Test 2 - Add function correctly appends value to the back: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.Add(66);
    if (marksArray.GetSize() == 4)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
string Test3CheckCopyConstructor()
{
    cout << "Test 3 - Copy constructor correctly copies the data from other object: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.Add(66);
    Vector<int> myTermMarks(marksArray);
    if ((myTermMarks[0] == 99) && (myTermMarks[1] == 88)
            && (myTermMarks[2] = 77) && (myTermMarks[3] == 66))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test4CheckRemoveLast()
{
    cout << "Test 4 - RemoveLast function correctly removes the value at the back: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.Add(66);
    marksArray.RemoveLast();
    if ((marksArray[0] == 99) && (marksArray[1] == 88)
            && (marksArray[2] = 77) && (marksArray.GetSize() == 3))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test5CheckInsertAt()
{
    cout << "Test 5 - InsertAt function correctly inserts value to the specified location: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.InsertAt(0, 89);
    if ((marksArray[0] == 89) && (marksArray[1] == 99)
            && (marksArray[2] = 88) && (marksArray[3] = 77))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test6CheckRemoveAT()
{
    cout << "Test 6 - RemoveAt function correctly removes value at the specified location: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.InsertAt(0, 89);
    marksArray.RemoveAt(2);
    if ((marksArray[0] == 89) && (marksArray[1] == 99)
            && (marksArray[2] = 77) && marksArray.GetSize() == 3)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test7CheckRetrieveAt()
{
    cout << "Test 7 - RetrieveAt function correctly retrieves the value at the specified location: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.InsertAt(0, 89);
    marksArray.RemoveAt(2);
    if ((marksArray.RetrieveAt(1) == 99))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test8CheckReplaceAt()
{
    cout << "Test 8 - ReplaceAt function correctly replaces the value at the specified location: ";
    Vector<int> marksArray;
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(77);
    marksArray.InsertAt(0, 89);
    marksArray.ReplaceAt(2, 88);
    if ((marksArray[0] == 89) && (marksArray[1] == 99)
            && (marksArray[2] == 88))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test9CheckClearIsEmpty()
{
    cout << "Test 9 - Clear function deletes all values from the Vector without deleting it. \n";
    cout << "         IsEmpty function correctly determines if the Vector is empty: ";
    Vector<int> myTermMarks;
    myTermMarks.Add(99);
    myTermMarks.Add(88);
    myTermMarks.Add(77);
    myTermMarks.Clear();
    if (myTermMarks.IsEmpty())
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test10CheckResize()
{
    cout << "Test 10 - Vector resizes correctly when number of values contained exceeds threshold.\n";
    cout << "           Capacity getter returns the correct value: ";
    Vector<int> marksArray;
    marksArray.Add(89);
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(33);
    marksArray.Add(22);
    marksArray.Add(55);
    if (marksArray.GetCapacity() == 10)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test11CheckSize()
{
    cout << "Test 11 - Size getter returns the correct value: ";
    Vector<int> marksArray;
    marksArray.Add(89);
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(33);
    marksArray.Add(22);
    marksArray.Add(55);
    if (marksArray.GetSize() == 6)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test12CheckBracketOperator()
{
    cout << "Test 12 - The overloaded index operator returns correct values when accessed: ";
    Vector<int> marksArray;
    marksArray.Add(89);
    marksArray.Add(99);
    marksArray.Add(88);
    marksArray.Add(33);
    marksArray.Add(22);
    marksArray.Add(55);
    if ((marksArray[1] == 99) && (marksArray[4] == 22))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
