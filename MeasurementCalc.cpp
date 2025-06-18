#include "MeasurementCalc.h"

float MeasurementCalc::CalculateMean(float sum, unsigned numCount)
{
    return sum / numCount;
}

float MeasurementCalc::CalculateStdDevWindSpeed(const Vector<SensorRecord>& sensorDataVector, float mean, unsigned numCount)
{
    float sum = 0.0;
    for (unsigned i = 0; i < sensorDataVector.GetSize(); i++) {
        sum += pow(sensorDataVector[i].GetWindSpeed() - mean, 2);
    }

    return sqrt(sum / (numCount - 1));
}


float MeasurementCalc::CalculateStdDevAirTemp(const Vector<float>& tempArray, float mean)
{
    unsigned count = tempArray.GetSize();

    if (count <= 1)
    {
        return 0.0;
    }

    float sumSquaredDifferences = 0.0;

    for (unsigned i = 0; i < count; ++i)
    {
        float airTemp = tempArray[i];
        sumSquaredDifferences += pow(airTemp - mean, 2);
    }

    float stdDev = sqrt(sumSquaredDifferences / (count - 1));

    return stdDev;
}
