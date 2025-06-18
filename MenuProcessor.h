#ifndef MENUPROCESSOR_H_INCLUDED
#define MENUPROCESSOR_H_INCLUDED

#include <iomanip>
#include <fstream>
#include <iostream>
#include "Vector.h"
#include "SensorRecord.h"
#include "MeasurementCalc.h"

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::fixed;
using std::setprecision;
using std::setw;
using std::ofstream;
using std::cerr;

//---------------------------------------------------------------------------------

/**
  \class MenuProcessor
  \brief Handles menu options and user input for sensor data processing.

  The class provides static methods for displaying menu options and processing user choices.

  \author Josie Lim
  \version 1.0
  \date 29/02/2024
*/

//---------------------------------------------------------------------------------

class MenuProcessor
{
private:
    /**
     \brief Convert a numerical month to its corresponding string representation.

     \param month The numerical month.
     \return The string representation of the month.
    */
    static string StringMonth(const unsigned &month);

public:
    /**
     \brief Display the menu options to the user.
    */
    static void DisplayMenuOptions();

    /**
     \brief Process the user's choice and perform corresponding actions.

     \param choice The user's menu choice.
     \param sensorDataVector The vector containing SensorRecord objects.
    */
    static void ProcessUserChoice(unsigned choice, Vector<SensorRecord>& sensorDataVector);

    /**
     \brief Perform actions for menu option one.

     \param sensorDataVector The vector containing SensorRecord objects.
    */
    static void MenuOptionOne(Vector<SensorRecord>& sensorDataVector);

    /**
     \brief Perform actions for menu option two.

     \param sensorDataVector The vector containing SensorRecord objects.
    */
    static void MenuOptionTwo(Vector<SensorRecord>& sensorDataVector);

    /**
     \brief Perform actions for menu option three.

     \param sensorDataVector The vector containing SensorRecord objects.
    */
    static void MenuOptionThree(Vector<SensorRecord>& sensorDataVector);

    /**
     \brief Perform actions for menu option four.

     \param sensorDataVector The vector containing SensorRecord objects.
    */
    static void MenuOptionFour(Vector<SensorRecord>& sensorDataVector);

};

#endif // MENUPROCESSOR_H_INCLUDED
