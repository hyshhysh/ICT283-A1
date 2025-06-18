#include <iostream>
#include "Date.h"

using namespace std;

string Test1CheckDefaultConstructor();
string Test2CheckParameterizedConstructor();
string Test3CheckDayOfMonthGetter();
string Test4CheckMonthGetter();
string Test5CheckYearGetter();
string Test6CheckDayOfMonthSetter();
string Test7CheckMonthSetter();
string Test8CheckYearSetter();

int main()
{
    cout << "DATE CLASS TEST\n" << endl;
    cout << Test1CheckDefaultConstructor() << endl;
    cout << Test2CheckParameterizedConstructor() << endl;
    cout << Test3CheckDayOfMonthGetter() << endl;
    cout << Test4CheckMonthGetter() << endl;
    cout << Test5CheckYearGetter() << endl;
    cout << Test6CheckDayOfMonthSetter() << endl;
    cout << Test7CheckMonthSetter() << endl;
    cout << Test8CheckYearSetter() << endl;



    return 0;
}

string Test1CheckDefaultConstructor()
{
    cout << "Test 1 - Default constructor correctly initializes data: ";
    Date anniversary;
    if ((anniversary.GetDayOfMonth() == 0)
        && (anniversary.GetMonth() == 0)
        && (anniversary.GetYear() == 0))
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
    Date birthdate(5,11,2000);
    if ((birthdate.GetDayOfMonth() == 5)
        && (birthdate.GetMonth() == 11)
        && (birthdate.GetYear() == 2000))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test3CheckDayOfMonthGetter()
{
    cout << "Test 3 - Day of month getter returns correct value: ";
    Date birthdate(5,11,2000);
    if (birthdate.GetDayOfMonth() == 5)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test4CheckMonthGetter()
{
    cout << "Test 4 - Month getter returns correct value: ";
    Date birthdate(5,11,2000);
    if (birthdate.GetMonth() == 11)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test5CheckYearGetter()
{
    cout << "Test 5 - Year getter returns correct value: ";
    Date birthdate(5,11,2000);
    if (birthdate.GetYear() == 2000)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test6CheckDayOfMonthSetter()
{
    cout << "Test 6 - Day of month setter sets correct value: ";
    Date anniversary;
    anniversary.SetDayOfMonth(2);
    if (anniversary.GetDayOfMonth() == 2)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test7CheckMonthSetter()
{
    cout << "Test 7 - Month setter sets correct value: ";
    Date anniversary;
    anniversary.SetMonth(10);
    if (anniversary.GetMonth() == 10)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test8CheckYearSetter()
{
    cout << "Test 8 - Year setter sets correct value: ";
    Date anniversary;
    anniversary.SetYear(2021);
    if (anniversary.GetYear() == 2021)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
