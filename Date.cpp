#include "Date.h"

using std::string;

Date::Date()
    : m_dayOfMonth(0), m_month(0), m_year(0)
{}

Date::Date(unsigned dayOfMonth, unsigned month, unsigned year)
    : m_dayOfMonth(dayOfMonth), m_month(month), m_year(year)
{}

unsigned Date::GetDayOfMonth() const
{
    return m_dayOfMonth;
}

unsigned Date::GetMonth() const
{
    return m_month;
}

unsigned Date::GetYear() const
{
    return m_year;
}

void Date::SetDayOfMonth(unsigned dayOfMonth)
{
    m_dayOfMonth = dayOfMonth;
}

void Date::SetMonth(unsigned month)
{
    m_month = month;
}

void Date::SetYear(unsigned year)
{
    m_year = year;
}

ostream & operator <<(ostream & output, const Date & date)
{
    output << "Date: " << date.GetDayOfMonth() << "/"
           << date.GetMonth() << "/"
           << date.GetYear();

    return output;
}

istream & operator >>(istream & input, Date & date)
{
    string tempDay;
    string tempMonth;
    string tempYear;

    getline(input, tempDay, '/');
    date.SetDayOfMonth(stoi(tempDay));

    getline(input, tempMonth, '/');
    date.SetMonth(stoi(tempMonth));

    getline(input, tempYear, ' ');
    date.SetYear(stoi(tempYear));

    return input;
}
