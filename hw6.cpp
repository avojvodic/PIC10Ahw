//
//  Homework 6
//
//  Aleksandra Vojvodic
//  May 21 2017
//  ID: 904578899
//

#include "ccc_win.h"
#include <time.h>

// declare House class
class House{
public:
    House(); // default constructor
    House(int input_num, Point input_location); // constructor with 2 parameters
    void draw() const; // draw member function (accessor)
    Point get_location() const; //get_location member function (accessor)
    int get_num() const; //get_num member function (accessor)
    
private:
    int house_num;
    Point location;
};


// declare Street class
class Street{
public:
    Street(); // default constructor
    Street(House first_input, House last_input, int num_input); // constructor with 3 parameters
    void plot() const; // plot member function (accessor)
private:
    House first;
    House last;
    int num_houses;
};

// House class definitions

House::House(){};

House::House(int input_num, Point input_location){
    house_num = input_num;
    location = input_location;
};

void House:: draw() const {
    
    
        Point TL(location.get_x(), location.get_y() + 3); // Top Left
        Point BR(location.get_x() + 3, location.get_y()); // Bottom Right
        Point TR(location.get_x() + 3, location.get_y() + 3); // Top Right
    
        Line bottom(location, BR);
        Line left(location, TL);
        Line right(BR, TR);
        Line top(TL, TR);
        
        // define point of roof
        Point roof(TL.get_x() + 1.5, TL.get_y() + 2);
        
        // define lines of roof
        Line roofL(TL, roof);
        Line roofR(roof, TR);
        
        // draw house
        cwin << bottom << left << right << top;
        cwin << roofL << roofR;
        
        //number the house with "address"
        Point center(location.get_x() + 1.5, location.get_y() + 2);
        Message M(center, house_num);
        cwin << M;
    };
    
    //return location
    Point get_location() const{
        return location;
    };
    
    //return int house
    int get_num() const{
        return house_num;
    };


// Street class definitions


Street::Street(){};

Street::Street(House first_input, House last_input, int num_input){
    first = first_input;
    last = last_input;
    num_houses = num_input;
};

void Street::plot() const{
    
    //get x1,y1,x2,y2
    double x1 = first.get_location().get_x();
    double y1 = first.get_location().get_y();
    double x2 = last.get_location().get_x();
    double y2 = last.get_location().get_y();
    
    // compute dx, dy
    double dx = (x2 - x1) / (num_houses - 1);
    double dy = (y2 - y1) / (num_houses - 1);
    
    // get labels
    double label1 = first.get_num();
    double label2 = last.get_num();
    
    //compute dlabel
    double dlabel = (label2 - label1) / (num_houses - 1);
    
    // create for loop that defines and draws all houses on street with iteration of num_houses
    for (int i = 0; i<num_houses; ++i){
        
        double new_x = x1 + dx*i;
        double new_y = y1 + dy*i;
        
        Point new_location(new_x, new_y);
        
        int new_label = label1 + dlabel*i;
        
        House new_house(new_label, new_location);
        new_house.draw();
    }
};


int ccc_win_main(){
    
    //set up coordinates
    cwin.coord(-30, 30, 30, -30);
    
    //program runs if user chooses to continue
    string response = "yes";
    while (response == "yes"){
        
        //start over
        cwin.clear();
        
        // record first and last house locations
        Point first_location = cwin.get_mouse("Choose the location for the first house by clicking anywhere on the right.");
        Point last_location = cwin.get_mouse("Please choose the location for the last house by clicking anywhere on the left.");
        
        // ask for the first and last numbers
        int first_label = cwin.get_int("Enter the street number of the first house.");
        int last_label = cwin.get_int("Enter the street number of the last house");
        
        //create 2 House variables
        House first_house(first_label, first_location);
        House last_house(last_label, last_location);
        
        //ask how many houses on the street
        int num_houses = cwin.get_int("How many houses are on the street?");
        
        //create a Street variable and draw all houses on street
        Street s(first_house, last_house, num_houses);
        s.plot();
        
        response = cwin.get_string("Want to draw another street? (yes/no) ?");
    }
    
    return 0;
}
