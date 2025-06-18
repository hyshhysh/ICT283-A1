#include <iostream>
#include "FileProcessor.h"
#include "SensorRecord.h"

using namespace std;

string Test1CheckDefaultConstructor();
string Test2LoadCSVFileWithValidData();


int main()
{
    cout << "FILE PROCESSOR CLASS TEST\n" << endl;
    cout << Test1CheckDefaultConstructor() << endl;
    cout << Test2LoadCSVFileWithValidData() << endl;

    return 0;
}

string Test1CheckDefaultConstructor()
{
    cout << "Test 1 - Default constructor correctly initializes data: ";
    FileProcessor fileProcessor;
    if (fileProcessor.m_fileName == "")
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}

string Test2LoadCSVFileWithValidData()
{
    cout << "Test 2 - Load CSV file with valid data: ";
    FileProcessor fileProcessor;
    Vector<SensorRecord> sensorRecordVector;
    fileProcessor.LoadCSVFile("data/data_source.txt", sensorRecordVector);
    if (sensorRecordVector.GetSize() > 0)
    {
        return "PASS";
    }
    else
    {
        return "FAIL";
    }
}
