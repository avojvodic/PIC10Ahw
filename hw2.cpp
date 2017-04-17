//
//  hw2.cpp
//  April21Hw2
//
//  Created by Aleksandra Vojvodic
//  Student ID: 904578899
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[])
{
    int x,y;
    
    string c1, c2;
    
    cout << "How many in the first category? ";
    cin >> x >> c1 ;
    
    cout << "How many in the second category? ";
    cin >> y >> c2;
    
    
    // Casting of integers to calculate ratio.
    
    double cr1 = (double) x/y;
    
    double cr2 = (double) y/x;
    
    
    // Use substring to make ratio categories singular.
    string category1 = c1.substr (0, (c1.length() - 1));
    string category2 = c2.substr (0, (c2.length() - 1));
    
    string ratio_one = category1 + "-to-" + category2 + " ratio";
    string ratio_two = category2 + "-to-" + category1 + " ratio";

    // Show significant digits in output of doubles.
    cout << fixed;
    cout << setprecision(2);
    
    // Organize columns and output.
    cout << setw(ratio_one.length()) << c1 << setw(10) << x << endl;
    
    cout << setw(ratio_one.length()) << c2 << setw(10) << y << endl;
    
    cout << setw(ratio_one.length()) << ratio_one << setw(10) << cr1 << endl;
    
    cout << setw(ratio_one.length()) << ratio_two << setw(10) << cr2 << endl;
    
    return 0;
}
