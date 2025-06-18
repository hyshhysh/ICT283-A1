#include <iostream>
#include "Time.h"

using namespace std;

string Test1CheckDefaultConstructor();
string Test2CheckParameterizedConstructor();
string Test3CheckHoursGetter();
string Test4CheckMinutesGetter();
string Test5CheckHoursSetter();
string Test6CheckMinutesSetter();


int main()
{
    cout << "TIME CLASS TEST\n" << endl;
    cout << Test1CheckDefaultConstructor() << endl;
    cout << Test2CheckParameterizedConstructor() << endl;
    cout << Test3CheckHoursGetter() << endl;
    cout << Test4CheckMinutesGetter() << endl;
    cout << Test5CheckHoursSetter() << endl;
    cout << Test6CheckMinutesSetter() << endl;



    return 0;
}


string Test1CheckDefaultConstructor()
{
    cout << "Test 1 - Default constructor correctly initializes data: ";
    Time startTime;
    if ((startTime.GetHours() == "0")
            && (startTime.GetMinutes() == "00"))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test2CheckParameterizedConstructor()
{
    cout << "Test 2 - Parameterized constructor correctly initializes data: ";
    Time endTime("22", "22");
    if ((endTime.GetHours() == "22")
            && (endTime.GetMinutes() == "22"))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test3CheckHoursGetter()
{
    cout << "Test 3 - Hours getter returns correct value: ";
    Time endTime("22", "22");
    if (endTime.GetHours() == "22")
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }

}

string Test4CheckMinutesGetter()
{
    cout << "Test 4 - Minutes getter returns correct value: ";
    Time endTime("22", "22");
    if (endTime.GetMinutes() == "22")
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test5CheckHoursSetter()
{
    cout << "Test 5 - Hours setter sets correct value: ";
    Time startTime;
    startTime.SetHours("11");
    if (startTime.GetHours() == "11")
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
string Test6CheckMinutesSetter()
{
    cout << "Test 6 - Minutes setter sets correct value: ";
    Time startTime;
    startTime.SetMinutes("11");
    if (startTime.GetMinutes() == "11")
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
