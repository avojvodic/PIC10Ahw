#include "ccc_win.h"
#include <time.h>

class House{
public:
	//default constructor
	House(){}

	//constructor with 2 parameters
	House(int input_num, Point input_location){
		house_num = input_num;
		location = input_location;
	}

	void draw() const {

		//draw the house at location

		Point BL(-3, -2); //bottom left
		Point BR(3, -2);
		Point UL(-3, 2);
		Point UR(3, 2);
		Point P(0, 4); // point of house

		Line B(BL, BR); //bottom
		Line R(BR, UR); // right
		Line L(BL, UL);
		Line T(UR, UL);
		Line P1(UR, P); // point 1
		Line P2(UL, P); // point 2

		cwin << B << R << L << T << P1 << P2;

		//number the house, use message
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


class Street{
public:
	//default constructor
	Street(){
	}

	//constuctor with 3 parameters
	Street(House first_input, House last_input, int num_input){
		first = first_input;
		last = last_input;
		num_houses = num_input;
	}

	void plot() const {
		double x1, y1, x2, y2;
		x1 = first.get_location().get_x();
		y1 = first.get_location().get_y();
		x2 = last.get_location().get_x();
		y2 = last.get_location().get_y();

		dx = (x1 / x2);
		dy = (y1 / y2);

		double l1, l2, dl;
		l1 = first.get_num();
		l2 = last.get_num();

		dl = (l1 / l2);

		for (int i = 0; i<num_houses; ++i){
			Point new_location;
			int new_label;


			//compute new_location and new_label

			House new_house(new_location, new_label);
			new_house.draw();
		}
	}


private:
	House first, last;
	int num_houses;
};



int ccc_win_main(){

	Point P1, P2;
	int first, last, num;

	P1 = cwin.get_mouse("Click somewhere!");
	P2 = cwin.get_mouse("Click again!");

	first = cwin.get_int("Enter the first house number: ");
	last = cwin.get_int("Enter the last house number");

	num = cwin.get_int("Enter the number of houses on the street: ");


	//create 2 House variables
	//create a Street variable
	//call plot() from Street variable

	return 0;
}
}
