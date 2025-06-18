#ifndef SENSORRECORD_H_INCLUDED
#define SENSORRECORD_H_INCLUDED

#include <string>
#include "Date.h"
#include "Time.h"

//---------------------------------------------------------------------------------

/**
  \class SensorRecord
  \brief Represents a sensor record with date, time, wind speed, air temperature, and solar radiation.

  The class provides methods to get and set the individual components of a sensor record.

  \author Josie Lim
  \version 1.0
  \date 29/02/2024
*/

//---------------------------------------------------------------------------------

class SensorRecord
{
private:
    Date m_date;
    Time m_time;
    float m_windSpeed;
    float m_airTemperature;
    float m_solarRadiation;

public:
    /**
    \brief Default constructor for SensorRecord class.
    */
    SensorRecord();

    /**
    \brief Parameterized constructor for SensorRecord class.

    \param date The date of the sensor record.
    \param time The time of the sensor record.
    \param windSpeed Wind speed in the sensor record.
    \param airTemperature Air temperature in the sensor record.
    \param solarRadiation Solar radiation in the sensor record.
    */
    SensorRecord(const Date& date, const Time& time, const float windSpeed,
                 const float airTemperature, const float solarRadiation);

    /**
     \brief Retrieve the date of the sensor record.

     \return The date.
    */
    const Date GetDate() const;

    /**
    \brief Retrieve the time of the sensor record.

    \return The time.
    */
    const Time GetTime() const;

    /**
    \brief Retrieve the wind speed in the sensor record.

    \return The wind speed.
    */
    const float GetWindSpeed() const;

    /**
    \brief Retrieve the air temperature in the sensor record.

    \return The air temperature.
    */
    const float GetAirTemperature() const;

    /**
    \brief Retrieve the solar radiation in the sensor record.

    \return The solar radiation.
    */
    const float GetSolarRadiation() const;

    /**
    \brief Set the date of the sensor record.

    \param date The date to be set.
    */
    void SetDate(const Date& date);

    /**
    \brief Set the time of the sensor record.

    \param time The time to be set.
    */
    void SetTime(const Time& time);

    /**
    \brief Set the wind speed in the sensor record.

    \param windSpeed The wind speed to be set.
    */
    void SetWindSpeed(float windSpeed);

    /**
    \brief Set the air temperature in the sensor record.

    \param airTemp The air temperature to be set.
    */
    void SetAirTemperature(float airTemp);

    /**
    \brief Set the solar radiation in the sensor record.

    \param solarRadiation The solar radiation to be set.
    */
    void SetSolarRadiation(float solarRadiation);

};

/**
\brief Output stream operator for the SensorRecord class.

\param output The output stream.
\param sensorRec The SensorRecord object to be output.
\return The modified output stream.
*/
ostream & operator <<(ostream & output, const SensorRecord & sensorRec);



#endif // SENSORRECORD_H_INCLUDED
