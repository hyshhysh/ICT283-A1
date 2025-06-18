#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <string>
#include <iostream>

using std::istream;
using std::ostream;


//---------------------------------------------------------------------------------

/**

  \class Time
  \brief Represents a time with hours and minutes.

   The class provides methods to get and set the hours and minutes.

  \author Josie Lim
  \version 1.0
  \date 27/02/24

  \version 2.0
  \date 29/02/24

   */

//---------------------------------------------------------------------------------


using std::string;

class Time
{
private:
    string m_hours;
    string m_minutes;

public:
    /**
    \brief Default constructor for Time class.
    */
    Time();

    /**
    \brief Parameterized constructor for Time class.

    \param hours The hours component of the time.
    \param minutes The minutes component of the time.
    */
    Time(const string& hours, const string& minutes);

    /**
     \brief Retrieve the hours component of the time.

     \return The hours.
    */
    string GetHours() const;

    /**
    \brief Retrieve the minutes component of the time.

    \return The minutes.
    */
    string GetMinutes() const;

    /**
    \brief Set the hours component of the time.

    \param hours The hours to be set.
    */
    void SetHours(const string& hours);

    /**
    \brief Set the minutes component of the time.

    \param minutes The minutes to be set.
    */
    void SetMinutes(const string& minutes);

};

/**
\brief Output stream operator for the Time class.

\param output The output stream.
\param time The Time object to be output.
\return The modified output stream.
*/
ostream & operator <<(ostream & output, const Time & time);

/**
\brief Input stream operator for the Time class.

\param input The input stream.
\param time The Time object to be input.
\return The modified input stream.
*/
istream & operator >>(istream & input, Time & time);

#endif // TIME_H_INCLUDED
