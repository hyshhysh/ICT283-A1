#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.h"
#include "FileProcessor.h"
#include "MenuProcessor.h"

void PrintSensorVector(const Vector<SensorRecord>& sensorRecVector);

const string fileSource = "data/data_source.txt";

int main()
{
    FileProcessor newFileRead;
    Vector<SensorRecord> sensorDataVector;
    newFileRead.LoadCSVFile(fileSource, sensorDataVector);

    unsigned choice;
    do
    {
        MenuProcessor::DisplayMenuOptions();

        cout << "Please select an option: ";
        cin >> choice;
        cout << endl;

        MenuProcessor::ProcessUserChoice(choice, sensorDataVector);

    } while (choice != 5);

    return 0;
}



















void PrintSensorVector(const Vector<SensorRecord>& sensorRecVector)
{
    for (unsigned i = 0; i < sensorRecVector.GetSize(); i++)
    {
        cout << "Sensor Record " << (i + 1) << ":" << endl;
        cout << "Date: " << sensorRecVector[i].GetDate() << endl;
        cout << "Time: " << sensorRecVector[i].GetTime() << endl;
        cout << "Wind Speed: " << sensorRecVector[i].GetWindSpeed() << endl;
        cout << "Air Temp: " << sensorRecVector[i].GetAirTemperature() << endl;
        cout << "Solar Radiation: " << sensorRecVector[i].GetSolarRadiation() << endl;
        cout << "------------------------" << endl;
    }
}
