//
//  Homework 6
//
//  Aleksandra Vojvodic
//  May 21 2017
//  ID: 904578899
//

#include <iostream> 
#include "ccc_win.h"

using namespace std;

class House
{
public:
	House() {} //default constructor

	House(int input_num, Point input_location)  //constructor with 2 parameters
	{
		house_num = input_num;
		location = input_location;
	}

	void draw() const {

		double x = location.get_x();
		double y = location.get_y();

		Point TL(x, y + 3); // Top Left
		Point BR(x + 3, y); // Bottom Right
		Point TR(x + 3, y + 3); // Top Right

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

		for (int i = 1; i < 20; i++)
		{
			double r = (double)rand() / RAND_MAX - 0.5;
			cwin << Circle(Point(TL.get_x() + 1.5 + r, TL.get_y() + 2 + 0.2*i), 0.2);
		}

	}

	//return location
	Point get_location() const{
		return location;
	}
	//return int house
	int get_num() const{
		return house_num;
	}

private:
	int house_num;
	Point location;
};


// declare Street class
class Street{
public:
	//default constructor
	Street() { }

	//constuctor with 3 parameters
	Street(House first_house, House last_house, int num)
	{
		first = first_house;
		last = last_house;
		num_houses = num;
	}

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
		for (int i = 0; i < num_houses; ++i){

			double new_x = x1 + dx*i;
			double new_y = y1 + dy*i;

			Point new_location(new_x, new_y);

			int new_label = label1 + dlabel*i;

			House new_house(new_label, new_location);
			new_house.draw();
		}

		last.draw();
	}

private:
	House first;
	House last;
	int num_houses;
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
		Point first_location = cwin.get_mouse("Please choose the location for the first house by clicking anywhere.");
		Point last_location = cwin.get_mouse("Please choose the location for the last house by clicking anywhere.");

		// ask for the first and last numbers
		int first_label = cwin.get_int("Enter the street number of the first house:");
		int last_label = cwin.get_int("Enter the street number of the last house:");

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

	cwin.clear();

	return 0;
}
