/* 
Homework 4
Aleksandra Vojvodic
May 5, 2017
ID: 904578899
*/


#include "ccc_win.h"
#include <time.h>


//function for the moving object which scales
void draw_dude(Point p, double scale)
{
	
	double ax = p.get_x();
	double ay = p.get_y();

	Point start(ax, ay);
	Point bottom(ax, ay - scale * 1);
	Point top(ax, ay + scale * 0.5);
	Point right(ax + scale * 1, ay);
	Point left(ax - scale * 1, ay);
	Point r_leg(ax + scale * 0.5, ay - scale * 2);
	Point l_leg(ax - scale * 0.5, ay - scale * 2);
	Point circle(ax, ay + scale * 1);

	Line B(start, bottom);
	Line T(start, top);
	Line R(start, right);
	Line L(start, left);
	Line D(bottom, r_leg);
	Line W(bottom, l_leg);

	Circle C(circle, scale * 0.5);

	cwin << B << T << R << L << D << W << C;

}


//function for the static object, a candy that the stick figure is chasing
void draw_candy(Point p)
{
	double ax = p.get_x();
	double ay = p.get_y();

	Point bl(ax, ay); //bottom left
	Point ul(ax, ay + 1); //upper left
	Point br(ax + 1, ay); //bottom right
	Point ur(ax + 1, ay + 1); //upper right

	Point l1(ax, ay + 0.5); //left triangle point 1
	Point l2(ax - 0.3, ay);
	Point l3(ax - 0.3, ay + 1);

	Point r1(ax + 1, ay + 0.5); //right triangle point 1
	Point r2(ax + 1.3, ay);
	Point r3(ax + 1.3, ay + 1);

	//Rectangle
	Line bottom(bl, br); 
	Line left(bl, ul);
	Line right(br, ur);
	Line top(ul, ur);

	//left triangle
	Line ltri1(l1, l2);
	Line ltri2(l2, l3);
	Line ltri3(l3, l1);
	
	//right triangle
	Line rtri1(r1, r2);
	Line rtri2(r2, r3);
	Line rtri3(r3, r1);

	cwin << bottom << left << right << top << ltri1 << ltri2 << ltri3 << rtri1 << rtri2 << rtri3;

}


//pause for a number of x milliseconds
void pause(int x)
{
	clock_t goal = x + clock();
	while (goal > clock());
}


//main animate function
void animate(int pause_interval, int num_steps, Point start, Point stop)
{
	// start coordinates
	double ax = start.get_x();
	double ay = start.get_y();

	// stop coordinates
	double bx = stop.get_x();
	double by = stop.get_y();

	//changes in coordinate for every frame
	double dx = (bx - ax) / num_steps;
	double dy = (by - ay) / num_steps;


	//running a for loop with num steps
	for (int i = 0; i < num_steps; i++)
	{
		//location for figure in this frame
		double x = i*dx + ax;
		double y = i*dy + ay;

		//declare location point
		Point p(x, y);

		//this is like a scale
		double scale = 1 + i*0.02;

		//draw candy shape
		draw_candy(stop);

		//draw stick figure with scaling
		draw_dude(p, scale);

		//pause for pause interval
		pause(pause_interval);

		//clear screen
		cwin.clear();

	}

}

int ccc_win_main()
{
	 // set coordinates of the frame

	cwin.coord(-10, 10, 10, -10);

	// user input: 3 click points

	Point start = cwin.get_mouse("Pick starting location: ");
	Point middle = cwin.get_mouse("Pick middle location: ");
	Point stop = cwin.get_mouse("Pick stopping location: ");

	//call the animation with the supplied points
	animate(50, 200, start, middle);
	animate(50, 200, middle, stop);

	return 0;

}
