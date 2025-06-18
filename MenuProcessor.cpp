#include "MenuProcessor.h"

void MenuProcessor::DisplayMenuOptions()
{
    cout << "\n=============================== MENU OPTIONS ===============================\n";
    cout << endl;
    cout << "(1) The average wind speed and sample standard deviation\n";
    cout << "    for this wind speed given a specified month and year.\n";
    cout << endl;
    cout << "(2) Average ambient air temperature and sample standard deviation\n";
    cout << "    for each month of a specified year.\n";
    cout << endl;
    cout << "(3) Total solar radiation in kWh/m2 for each month of a specified year.\n";
    cout << endl;
    cout << "(4) Average wind speed (km/h), average ambient air temperature and\n";
    cout << "    total solar radiation in kWh/m2 for each month of a specified year.\n";
    cout << endl;
    cout << "(0) Exit program.\n";
    cout << endl;
    cout << "============================================================================\n";
    cout << endl;
}

void MenuProcessor::ProcessUserChoice(unsigned choice, Vector<SensorRecord>& sensorDataVector)
{

    switch (choice)
    {
    case 1:
        cout << "You have selected OPTION 1." << endl;
        MenuProcessor::MenuOptionOne(sensorDataVector);
        break;
    case 2:
        cout << "You have selected OPTION 2." << endl;
        MenuProcessor::MenuOptionTwo(sensorDataVector);
        break;
    case 3:
        cout << "You have selected OPTION 3." << endl;
        MenuProcessor::MenuOptionThree(sensorDataVector);
        break;
    case 4:
        cout << "You have selected OPTION 4." << endl;
        MenuProcessor::MenuOptionFour(sensorDataVector);
        break;
    case 5:
        cout << "You have selected OPTION 5." << endl;
        cout << "You have chosen to exit the program." << endl;;
        break;
    default:
        cout << "Invalid option, please choose again." << endl;
        break;
    }
}

void MenuProcessor::MenuOptionOne(Vector<SensorRecord>& sensorDataVector)
{
    cout << "Please enter the month (1-12): ";
    unsigned monthInput;
    cin >> monthInput;
    if (monthInput < 1 || monthInput > 12)
    {
        cout << "Invalid month entered. Please enter a month value (1-12)." << endl;
        return;
    }

    cout << "Please enter the year (YYYY): ";
    unsigned yearInput;
    cin >> yearInput;
    if (yearInput < 1900 || yearInput > 2100)
    {
        cout << "Invalid year entered. Please enter a four digit year value (YYYY)." << endl;
        return;
    }

    float sumOfWindSpeed = 0.0;
    unsigned numCount = 0;

    for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
    {
        SensorRecord data = sensorDataVector.RetrieveAt(i);
        if ((data.GetDate().GetMonth() == monthInput) && (data.GetDate().GetYear() == yearInput))
        {
            sumOfWindSpeed += data.GetWindSpeed();
            numCount++;
        }
    }

    if (numCount > 0)
    {
        float avgWindSpeed = MeasurementCalc::CalculateMean(sumOfWindSpeed, numCount);
        float stdDevWindSpeed = MeasurementCalc::CalculateStdDevWindSpeed(sensorDataVector, avgWindSpeed, numCount);

        cout << endl;
        cout << fixed << setprecision(1);
        cout << MenuProcessor::StringMonth(monthInput) << " " << yearInput << ":\n";
        cout << "Average speed: " << avgWindSpeed << "km/h\n";
        cout << "Sample stdev: " << stdDevWindSpeed << endl;
    }
    else
    {
        cout << MenuProcessor::StringMonth(monthInput) << " " << yearInput << ": No data" << endl;
    }
    cout << endl;
}

void MenuProcessor::MenuOptionTwo(Vector<SensorRecord>& sensorDataVector)
{
    cout << "Please enter the year (YYYY): ";
    unsigned yearInput;
    cin >> yearInput;

    if (yearInput < 1900 || yearInput > 2100)
    {
        cout << "Invalid year entered. Please enter a four digit year value (YYYY)." << endl;
        return;
    }

    float monthlyAirTempSum[12] = {0.0};
    unsigned monthlyNumCount[12] = {0};

    for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
    {
        SensorRecord data = sensorDataVector.RetrieveAt(i);
        if (data.GetDate().GetYear() == yearInput)
        {
            unsigned month = data.GetDate().GetMonth() - 1;
            monthlyAirTempSum[month] += data.GetAirTemperature();
            monthlyNumCount[month]++;
        }
    }

    cout << '\n' << yearInput << endl;
    for (unsigned month = 0; month < 12; month++)
    {
        if (monthlyNumCount[month] > 0)
        {
            float airTempSum = monthlyAirTempSum[month];
            unsigned monthlyNumSum = monthlyNumCount[month];

            // Collect temperatures for the current month
            Vector<float> monthlyTemperatures;
            for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
            {
                SensorRecord data = sensorDataVector.RetrieveAt(i);
                if (data.GetDate().GetYear() == yearInput && data.GetDate().GetMonth() - 1 == month)
                {
                    monthlyTemperatures.Add(data.GetAirTemperature());
                }
            }

            float avgAirTemp = MeasurementCalc::CalculateMean(airTempSum, monthlyNumSum);
            float airTempStdDev = MeasurementCalc::CalculateStdDevAirTemp(monthlyTemperatures, avgAirTemp);

            cout << fixed << setw(12) << setprecision(1);
            cout << MenuProcessor::StringMonth(month + 1) << ": ";
            cout << "average: " << avgAirTemp
                 << " degrees C, stdev: " << airTempStdDev << endl;
        }
        else
        {
            cout << setw(12);
            cout << MenuProcessor::StringMonth(month + 1) << ": No data" << endl;
        }
    }
    cout << endl;

}

void MenuProcessor::MenuOptionThree(Vector<SensorRecord>& sensorDataVector)
{
    cout << "Please enter the year (YYYY): ";
    unsigned yearInput;
    cin >> yearInput;

    if (yearInput < 1900 || yearInput > 2100)
    {
        cout << "Invalid year entered. Please enter a four-digit year value (YYYY)." << endl;
        return;
    }

    float monthlySumSR[12] = {0.0};
    unsigned monthlyNumCount[12] = {0};

    for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
    {
        SensorRecord data = sensorDataVector.RetrieveAt(i);
        if (data.GetDate().GetYear() == yearInput)
        {
            float solarRadiation = data.GetSolarRadiation();
            unsigned month = data.GetDate().GetMonth() - 1;

            if (solarRadiation * 6000.0 >= 100)
            {
                monthlySumSR[month] += solarRadiation;
                monthlyNumCount[month]++;
            }
        }
    }

    cout << '\n' << yearInput << endl;
    for (unsigned month = 0; month < 12; month++)
    {
        if (monthlyNumCount[month] > 0)
        {
            cout << fixed << setw(12) << setprecision(1);
            cout << MenuProcessor::StringMonth(month + 1) << ": ";
            cout << monthlySumSR[month] << " kWh/m2" << endl;
        }
        else
        {
            cout << setw(12);
            cout << MenuProcessor::StringMonth(month + 1) << ": No Data" << endl;
        }
    }
    cout << endl;
}

void MenuProcessor::MenuOptionFour(Vector<SensorRecord>& sensorDataVector)
{
    cout << "Please enter the year (YYYY): ";
    unsigned yearInput;
    cin >> yearInput;

    if (yearInput < 1900 || yearInput > 2100)
    {
        cout << "Invalid year entered. Please enter a four-digit year value (YYYY)." << endl;
        return;
    }

    string fileName = "WindTempSolar.csv";
    ofstream outFile(fileName);
    if (!outFile)
    {
        cerr << "Error opening file.";
        return;
    }

    outFile << yearInput << '\n';

    float monthlySumSR[12] = {0.0};
    float monthlySumWindSpeed[12] = {0.0};
    float monthlySumAirTemp[12] = {0.0};
    unsigned monthlyNumCount[12] = {0};

    for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
    {
        SensorRecord data = sensorDataVector.RetrieveAt(i);
        if (data.GetDate().GetYear() == yearInput)
        {
            float windSpeed = data.GetWindSpeed();
            float airTemp = data.GetAirTemperature();
            float solarRadiation = data.GetSolarRadiation();
            unsigned month = data.GetDate().GetMonth() - 1;

            monthlySumWindSpeed[month] += windSpeed;
            monthlySumAirTemp[month] += airTemp;

            if (solarRadiation * 6000 >= 100)
            {
                monthlySumSR[month] += solarRadiation;
            }
            monthlyNumCount[month]++;
        }
    }

    bool yearHasData = false;

    for (unsigned month = 0; month < 12; month++)
    {
        if (monthlyNumCount[month] > 0)
        {
            float avgWindSpeed = MeasurementCalc::CalculateMean(monthlySumWindSpeed[month], monthlyNumCount[month]);
            float avgAirTemp = MeasurementCalc::CalculateMean(monthlySumAirTemp[month], monthlyNumCount[month]);
            float sumSolarRad = monthlySumSR[month];

            float stdDevWindSpeed = MeasurementCalc::CalculateStdDevWindSpeed(sensorDataVector, avgWindSpeed, monthlyNumCount[month]);

            Vector<float> tempArray;
            for (unsigned i = 0; i < sensorDataVector.GetSize(); i++)
            {
                SensorRecord data = sensorDataVector.RetrieveAt(i);
                if (data.GetDate().GetYear() == yearInput && data.GetDate().GetMonth() == month + 1)
                {
                    tempArray.Add(data.GetAirTemperature());
                }
            }
            float stdDevAirTemp = MeasurementCalc::CalculateStdDevAirTemp(tempArray, avgAirTemp);

            outFile << MenuProcessor::StringMonth(month + 1) << ",";
            if (monthlyNumCount[month] > 0)
            {
                outFile << fixed << setprecision(1);
                outFile << avgWindSpeed << '(' << stdDevWindSpeed << ')' << ",";
                outFile << avgAirTemp << '(' << stdDevAirTemp << ')'  << ",";
                outFile << sumSolarRad;
            }
            else
            {
                outFile << ",";
                outFile << ",";
                outFile << "no data";
            }
            outFile << endl;
            yearHasData = true;
        }
    }
    cout << "File written successfully." << endl;
    cout << endl;
}

string MenuProcessor::StringMonth(const unsigned &month)
{
    string stringMonth;
    switch (month)
    {
    case 1:
        stringMonth = "January";
        break;
    case 2:
        stringMonth = "February";
        break;
    case 3:
        stringMonth = "March";
        break;
    case 4:
        stringMonth = "April";
        break;
    case 5:
        stringMonth = "May";
        break;
    case 6:
        stringMonth = "June";
        break;
    case 7:
        stringMonth = "July";
        break;
    case 8:
        stringMonth = "August";
        break;
    case 9:
        stringMonth = "September";
        break;
    case 10:
        stringMonth = "October";
        break;
    case 11:
        stringMonth = "November";
        break;
    case 12:
        stringMonth = "December";
        break;
    default:
        break;
    }
    return stringMonth;
}
