#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <iostream>

using std::istream;
using std::ostream;

//---------------------------------------------------------------------------------

/**
  \class Date
  \brief Represents a date with day, month, and year.

  The class provides methods to get and set the day, month, and year.

  \author Josie Lim
  \version 1.0
  \date 21/02/24

  \version 2.0
  \date 29/02/24
  \brief Updated doxygen comments.
*/

//---------------------------------------------------------------------------------

class Date
{
private:
    unsigned m_dayOfMonth;
    unsigned m_month;
    unsigned m_year;

public:
    /**
    \brief Default constructor for Date class.
    */
    Date();

    /**
    \brief Parameterized constructor for Date class.
    */
    Date(unsigned dayOfMonth, unsigned month, unsigned year);


    /**
     \brief Retrieve day of the month.
     \return The day of the month.
    */
    unsigned GetDayOfMonth() const;

    /**
    \brief Retrieve month.
    \return The month.
    */
    unsigned GetMonth() const;

    /**
    \brief Retrieve year.
    \return The year.
    */
    unsigned GetYear() const;

    /**
         \brief Modify the day of the month.
         \param dayOfMonth The day of the month to be modified.
        */
    void SetDayOfMonth(unsigned dayOfMonth);

    /**
         \brief Modify the month.
         \param month The month to be modified.
        */
    void SetMonth(unsigned month);

    /**
         \brief Modify the year.
         \param year The year to be modified.
        */
    void SetYear(unsigned year);

};

/**
\brief Output stream operator for the Date class.

\param output The output stream.
\param date The Date object to be output.
\return The modified output stream.
*/
ostream & operator <<(ostream & output, const Date & date);

/**
\brief Input stream operator for the Date class.

\param input The input stream.
\param date The Date object to be input.
\return The modified input stream.
*/
istream & operator >>(istream & input, Date & date);


#endif // DATE_H_INCLUDED
