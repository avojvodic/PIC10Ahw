
// PIC10Ahw
// Homework Assignment 2
//  main.cpp
//  April14Hw2
//
//  Created by Aleksandra Vojvodic on 4/10/17.
//  Student ID 904578899
//

#include <iostream>
using namespace std;

int main(int argc, char **argv)

{
    int initialseconds, initialminutes, initialhours, initialdays, initialyear, miles, seconds, minutes, hours, days, years; // variable declarations including conversion variables
    
    cout << "Please give me the time of travel in seconds. ";
    cin >> initialseconds; // User enters a positive integer here to represent seconds.
    
    cout << "Please give me your speed in miles per hour. ";
    cin >> miles; // User enters a positive integer here to represent miles per hour.
    
    seconds = initialseconds % 60; // remainder of seconds
    
    initialminutes = initialseconds/ 60;
    
    minutes = initialminutes % 60;
    
    initialhours = initialminutes / 60; // conversion from initial seconds to minutes to hours
    
    hours = initialhours % 24;
    
    initialdays = initialhours/24;
    
    days = initialdays % 24; // remainder of days
    
    initialyear = initialdays/ 365;
    
    years = initialyear % 365;
    
    
    cout << "You have been traveling for: " << "" << years << " years " << days<< " days "<< hours << " hours " << minutes << " minutes " << seconds <<" seconds. \n";
    
    cout << "Your distance travelled is: " << ""<< miles * ((double) initialseconds/3600) << " miles.\n"; // cast a double in order to convert seconds to hours and determine total miles.
    
    system("pause");
    return 0;
}
