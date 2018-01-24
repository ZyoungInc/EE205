// These two lines are the opening part of what's called a "header guard"
// If this file is ever included more than one, it'll make sure that
// only one version of this code will show up to the compiler.
//
// In other words, it won't try to redefine things twice because it
// was included twice.
#ifndef POINT2D_HPP
#define POINT2D_HPP

// You'll need to turn this into a class.
// Make sure you use the concept of encapsulation,
// and hide the class's internal data.
#include <iostream>

using namespace std;

//Class definition for Point2D
class Point2D {
	public:
    		//Default Constructor
		Point2D();

		//Overloaded Constructor
		Point2D(float x, float y);

		//Getters
		float get_x();
		float get_y();

		//Setters
		void set_x(float f);
		void set_y(float f);

		//Operator overloading
		Point2D operator+(const Point2D &hs);
		Point2D operator-(const Point2D &hs);
		Point2D operator*(const Point2D &hs);
		Point2D operator/(const Point2D &hs);

	private:
		float x_point;
		float y_point;
};

// lhs = "left hand side"
// rhs = "right hand side"

#endif // POINT2D_HPP
