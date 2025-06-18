#include <iostream>
#include "SensorRecord.h"

using namespace std;

string Test1CheckDefaultConstructor();
string Test2CheckSetters();
int main()
{
    cout << "SENSOR RECORD CLASS TEST\n" << endl;
    cout << Test1CheckDefaultConstructor() << endl;
    cout << Test2CheckSetters() << endl;

    return 0;
}

string Test1CheckDefaultConstructor()
{
    cout << "Test 1 - Default constructor correctly initializes data: ";
    SensorRecord sensorRec;
    if ((sensorRec.GetWindSpeed() == 0) && (sensorRec.GetAirTemperature() == 0)
            && (sensorRec.GetSolarRadiation() == 0))
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test2CheckSetters()
{
    cout << "Test 2 - Setters set correct values: ";
    SensorRecord sensorRec;
    Date newDate(12, 2, 2023);
    Time newTime("8", "0");
    sensorRec.SetDate(newDate);
    sensorRec.SetTime(newTime);
    sensorRec.SetAirTemperature(22.5);
    if (sensorRec.GetDate().GetMonth() == 2 && sensorRec.GetAirTemperature() == 22.5)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
