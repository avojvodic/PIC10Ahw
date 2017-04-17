
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
    int initial_seconds,
    initial_minutes,
    initial_hours,
    initial_days,
    initial_year,
    mph,
    seconds,
    minutes,
    hours,
    days,
    years; // variable declarations including conversion variables
   
    
    // Prompt user to enter a positive integer to represent seconds.
    cout << "Please give me the time of travel in seconds. ";
    cin >> initial_seconds; 
    
   // Prompt user to enter a positive integer to represent miles per hour. 
    cout << "Please give me your speed in miles per hour. ";
    cin >> mph; 
    
    seconds = initial_seconds % 60; // remainder of seconds
    
    initial_minutes = initial_seconds / 60;
    
    minutes = initial_minutes % 60;
    
    initial_hours = initial_minutes / 60; // conversion from initial seconds to minutes to hours
    
    hours = initial_hours % 24;
    
    initial_days = initial_hours / 24;
    
    days = initial_days % 24; // remainder of days
    
    initial_year = initial_days / 365;
    
    years = initial_year % 365;
    
    
    cout << "You have been traveling for: " << years << " years " 
        << days << " days "
        << hours << " hours " 
        << minutes << " minutes " 
        << seconds << " seconds." << endl;
    
    // convert seconds to hours and multiply by miles per hour to determine total miles travelled.
    cout << "Your distance travelled is: "<< mph * ((double) initial_seconds/3600) << " miles." << endl; 
    
    system("pause");
    return 0;
}
