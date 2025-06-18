#include "Time.h"

Time::Time()
    : m_hours("0"), m_minutes("00")
{}

Time::Time(const string& hours, const string& minutes)
    : m_hours(hours), m_minutes(minutes)
{}

string Time::GetHours() const
{
    return m_hours;
}

string Time::GetMinutes() const
{
    return m_minutes;
}

void Time::SetHours(const string& hours)
{
    m_hours = hours;
}

void Time::SetMinutes(const string& minutes)
{
    m_minutes = minutes;
}

ostream & operator <<(ostream & output, const Time & time)
{
    output << "Time: " << time.GetHours() << ":" << time.GetMinutes();

    return output;
}

istream & operator >>(istream & input, Time & time)
{
    string tempHours;
    string tempMinutes;

    getline(input, tempHours, ':');
    time.SetHours(tempHours);

    getline(input, tempMinutes, ',');
    time.SetMinutes(tempMinutes);

    return input;
}
