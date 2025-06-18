#include "FileProcessor.h"

FileProcessor::FileProcessor()
    : m_fileName("")
{

}

void FileProcessor::LoadCSVFile(const string& fileSource, Vector<SensorRecord> &sensorRecordVector)
{
    // get file
    ifstream inSource(fileSource);
    if (!inSource)
    {
        cerr << "Error opening file." << endl;
    }
    string fileName;
    getline(inSource, fileName);
    fileName = "data/" + fileName;
    //cout << fileName << endl;

    inSource.close();

    // read data file
    ifstream dataFile(fileName);
    if (!dataFile)
    {
        cerr << "Error opening file '" << fileName << "'" << endl;
    }

    // Read and store headers
    Vector<string> headerVec;
    LoadHeaderVec(dataFile, headerVec);



    Vector<string> rowArray;
    Vector<Vector<string>> dataMatrix;
    LoadDataFromCSV(dataFile, rowArray, dataMatrix);

    AppendDataToVec(dataMatrix, sensorRecordVector, headerVec);
}

void FileProcessor::LoadHeaderVec(ifstream& dataFile, Vector<string>& headers)
{
    string line;

    if (getline(dataFile, line))
    {
        stringstream ss(line);
        string header;

        while (getline(ss, header, ','))
        {
            headers.Add(header);
        }
    }
}

void FileProcessor::LoadDataFromCSV(ifstream& dataFile, Vector<string>& rowArray, Vector<Vector<string>>& dataMatrix)
{
    string line;
    int row = 0;
    while (getline(dataFile, line))
    {

        rowArray.Clear();
        stringstream ss(line);
        string data;

        int column = 0;
        while (getline(ss, data, ','))
        {
            rowArray.Add(data);
            column++;
        }

        dataMatrix.Add(rowArray);
        row++;
    }


}

void FileProcessor::AppendDataToVec(Vector<Vector<string>>& dataMatrix, Vector<SensorRecord> &sensorRecordVector, Vector<string>& headers)
{

    unsigned column_wast = GetColumnNo("WAST", headers);
    unsigned column_s = GetColumnNo("S", headers);
    unsigned column_sr = GetColumnNo("SR", headers);
    unsigned column_t = GetColumnNo("T", headers);

    float windSpeed, airTemp, SolarRdtn;
    string day, month, year, hour, minute;

    for (unsigned i = 0; i < dataMatrix.GetSize(); i++)
    {
        Vector<string> dataArray = dataMatrix.RetrieveAt(i);

        if (dataArray.GetSize() != 0)
        {
            SensorRecord sensorRec;  // Create a new SensorRecord object for each row

            stringstream ss(dataArray.RetrieveAt(column_wast));
            getline(ss, day, '/');
            getline(ss, month, '/');
            getline(ss, year, ' ');
            getline(ss, hour, ':');
            getline(ss, minute);
            sensorRec.SetTime(Time(hour, minute));

            unsigned d = stoi(day);
            unsigned m = stoi(month);
            int y = stoi(year);
            sensorRec.SetDate(Date(d, m, y));

            windSpeed = stof(dataArray.RetrieveAt(column_s));
            sensorRec.SetWindSpeed(windSpeed);

            airTemp = stof(dataArray.RetrieveAt(column_t));
            sensorRec.SetAirTemperature(airTemp);

            SolarRdtn = stof(dataArray.RetrieveAt(column_sr));
            sensorRec.SetSolarRadiation(SolarRdtn);

            // cout << sensorRec.GetWindSpeed() << " " << sensorRec.GetAirTemperature() << " " << sensorRec.GetSolarRadiation() << endl;

            // Add the SensorRecord object to the vector
            sensorRecordVector.Add(sensorRec);
        }
    }
}

unsigned FileProcessor::GetColumnNo(const string columnName, const Vector<string>& vectr)
{
    unsigned columnNo = -1;
    for (unsigned i = 0; i < vectr.GetSize(); i++)
    {
        if (vectr[i] == columnName)
        {
            columnNo = i;
        }
    }
    if (columnNo == -1)
    {
        throw out_of_range("Column Name does not exist");
    }
    return columnNo;
}

