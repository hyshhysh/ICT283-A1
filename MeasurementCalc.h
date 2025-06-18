#ifndef MEASUREMENTCALC_H_INCLUDED
#define MEASUREMENTCALC_H_INCLUDED

#include <cmath>
#include "Vector.h"
#include "SensorRecord.h"

//---------------------------------------------------------------------------------

/**
  \class MeasurementCalc
  \brief Provides static methods for calculating statistical measurements on sensor data.

  The class includes methods for calculating mean and standard deviation for wind speed and air temperature.

  \author Josie Lim
  \version 1.0
  \date 29/02/2024
*/

//---------------------------------------------------------------------------------

class MeasurementCalc
{
public:
    /**
     \brief Calculate the mean value.

     \param sum The sum of values.
     \param numCount The number of values.
     \return The calculated mean.
    */
    static float CalculateMean(float sum, unsigned numCount);

    /**
    \brief Calculate the standard deviation for wind speed.

    \param sensorDataVector The vector containing SensorRecord objects.
    \param mean The mean wind speed.
    \param numCount The number of values.
    \return The calculated standard deviation for wind speed.
    */
    static float CalculateStdDevWindSpeed(const Vector<SensorRecord>& sensorDataVector, float mean, unsigned numCount);

    /**
     \brief Calculate the standard deviation for air temperature.

     \param tempArray The vector containing air temperature values.
     \param mean The mean air temperature.
     \return The calculated standard deviation for air temperature.
    */
    static float CalculateStdDevAirTemp(const Vector<float>& tempArray, float mean);

};

#endif // MEASUREMENTCALC_H_INCLUDED
