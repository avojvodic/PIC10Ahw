//  main.cpp
//  April28HW3
//
//  Created by Aleksandra Vojvodic on 4/26/17.
//  Copyright © 2017 Aleksandra Vojvodic. All rights reserved.
//
#include <iostream>
#include "ccc_win.h"

//draw X
void draw_X(double x, double y){
	Line x1(Point(x - 1, y + 1), Point(x + 1, y - 1));
	Line x2(Point(x - 1, y - 1), Point(x + 1, y + 1));
	cwin << x1 << x2;
}

//draw O
void draw_O(double x, double y){
	Point p(x, y);
	Circle C(p, 1);
	cwin << C;
}

int ccc_win_main ( )

{
		string response = "yes";
		while (response == "yes") {

			// set up a new game
			cwin.clear();

			// draw board

			cwin.coord(-6, 6, 6, -6);

			Line v1(Point(-2, 6), Point(-2, -6));
			Line v2(Point(2, 6), Point(2, -6));

			Line h1(Point(-6, 2), Point(6, 2));
			Line h2(Point(-6, -2), Point(6, -2));

			cwin << v1 << v2 << h1 << h2;

			string s = "000000000";
			// runs the game for 9 turns

			for (int i = 1; i <= 9; ++i) {

				bool bad_choice = true;

				while (bad_choice) {

					Point p;
					p = cwin.get_mouse("X's turn!");

					// check whether p falls within an occupied square or not

					double x = p.get_x();
					double y = p.get_y();

					if ((-6 <= x) && (x < -2))
						x = -4;
					else if ((-2 <= x) && (x < 2))
						x = 0;
					else
						x = 4;

					if ((-6 <= y) && (y < -2))
						y = -4;
					else if ((-2 <= y) && (y < 2))
						y = 0;
					else
						y = 4;

					int box;

					if ((x == -4) && (y == 4)) box = 0;
					else if ((x == 0) && (y == 4)) box = 1;
					else if ((x == 4) && (y == 4)) box = 2;
					else if ((x == -4) && (y == 0)) box = 3;
					else if ((x == 0) && (y == 0)) box = 4;
					else if ((x == 4) && (y == 0)) box = 5;
					else if ((x == -4) && (y == -4)) box = 6;
					else if ((x == 0) && (y == -4)) box = 7;
					else box = 8;

					// check if box is empty

					if (s[box] == '0') {

						if (i % 2 == 1){

							draw_X(x, y);
						}

						else {
							// draw an O at the point (x,y)

							draw_O(x, y);
						}

						s[box] = 1;
						bad_choice = false;

					}
				}
			}
			//ask the user if they want to continue
			//ask user for a response

			response = cwin.get_string("Game Over! Do you want to play again (yes/no)?");
		}
				return 0;
	}

			
