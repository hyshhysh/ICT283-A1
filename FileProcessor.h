#ifndef FILEPROCESSOR_H_INCLUDED
#define FILEPROCESSOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vector.h"
#include "SensorRecord.h"

using std::ifstream;
using std::stringstream;
using std::string;
using std::out_of_range;

//---------------------------------------------------------------------------------

/**
  \class FileProcessor
  \brief Handles the processing of CSV files containing sensor data.

  The class provides methods to load CSV files, extract header information, and populate data vectors.

  \author Josie Lim
  \version 1.0
  \date 29/02/2024
*/


//---------------------------------------------------------------------------------

class FileProcessor
{
private:
    /**
     \brief Retrieve the column number for a given column name.

     \param columnName The name of the column.
     \param vectr The vector containing column names.
     \return The column number.
    */
    unsigned GetColumnNo(const string columnName, const Vector<string>& vectr);

    /**
     \brief Load header information from a CSV file.

     \param dataFile The input file stream.
     \param headers The vector to store column headers.
    */
    void LoadHeaderVec(ifstream& dataFile, Vector<string>& headers);

    /**
     \brief Load data from a CSV file into a matrix.

     \param dataFile The input file stream.
     \param rowArray The vector to store a single row of data.
     \param dataMatrix The matrix to store all data rows.
    */
    void LoadDataFromCSV(ifstream& dataFile, Vector<string>& rowArray, Vector<Vector<string>>& dataMatrix);

    /**
    \brief Append data from the matrix to the vector of SensorRecords.

    \param dataMatrix The matrix containing data rows.
    \param sensorRecordVector The vector to store SensorRecords.
    \param headers The vector containing column headers.
    */
    void AppendDataToVec(Vector<Vector<string>>& dataMatrix, Vector<SensorRecord> &sensorRecordVector, Vector<string>& headers);

public:
    string m_fileName;

    /**
    \brief Default constructor for FileProcessor class.
    */
    FileProcessor();

    /**
    \brief Load a CSV file and populate a vector of SensorRecords.

    \param fileSource The path to the CSV file.
    \param sensorRecordVector The vector to store SensorRecords.
    */
    void LoadCSVFile(const string& fileSource, Vector<SensorRecord> &sensorRecordVector);


};

#endif // FILEPROCESSOR_H_INCLUDED
