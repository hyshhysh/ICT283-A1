#include "SensorRecord.h"

SensorRecord::SensorRecord()
    : m_windSpeed(0), m_airTemperature(0), m_solarRadiation(0)
{

}

SensorRecord::SensorRecord(const Date& date, const Time& time, const float windSpeed,
                           const float airTemperature, const float solarRadiation)
    : m_date(date), m_time(time), m_airTemperature(airTemperature)
{
    m_windSpeed = windSpeed * 3.6;
    m_solarRadiation = solarRadiation / 6000;
}

const Date SensorRecord::GetDate() const
{
    return m_date;
}

const Time SensorRecord::GetTime() const
{
    return m_time;
}

const float SensorRecord::GetWindSpeed() const
{
    return m_windSpeed;
}

const float SensorRecord::GetAirTemperature() const
{
    return m_airTemperature;
}
const float SensorRecord::GetSolarRadiation() const
{
    return m_solarRadiation;
}

void SensorRecord::SetDate(const Date& date)
{
    m_date = date;
}

void SensorRecord::SetTime(const Time& time)
{
    m_time = time;
}

void SensorRecord::SetWindSpeed(float windSpeed)
{
    m_windSpeed = windSpeed * 3.6;
}


void SensorRecord::SetAirTemperature(float airTemp)
{
    m_airTemperature = airTemp;
}

void SensorRecord::SetSolarRadiation(float solarRadiation)
{
    m_solarRadiation = solarRadiation / 6000;
}

ostream & operator <<(ostream & output, const SensorRecord &sensorRec)
{
    output << sensorRec.GetDate() << " " << sensorRec.GetTime() << " "
           << sensorRec.GetWindSpeed();
}
