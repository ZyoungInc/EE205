#include "Point2D.hpp"

//Function for a 2d pointer

//Default Construtor
Point2D::Point2D() {
	x_point = 0;
	y_point = 0;
}

//Overloaded contructor
Point2D::Point2D(float x, float y) {
	x_point = x;
	y_point = y;
}

//Getters
float Point2D::get_x(void) {
	return x_point;
}

float Point2D::get_y(void) {
	return y_point;
}

//Setters
void Point2D::set_x(float f) {
	x_point = f;
}

void Point2D::set_y(float f) {
	y_point = f;
}

//Operator overload for "+"
 Point2D Point2D::operator+(const Point2D &lhs) {
	 Point2D temp_Point2D;
	 temp_Point2D.x_point = this->x_point + lhs.x_point;
	 temp_Point2D.y_point = this->y_point + lhs.y_point;
	 return temp_Point2D;
 }
 
//Operator overload for "-"
 Point2D Point2D::operator-(const Point2D &lhs) {
	 Point2D temp_Point2D;
	 temp_Point2D.x_point = this->x_point - lhs.x_point;
	 temp_Point2D.y_point = this->y_point - lhs.y_point;
	 return temp_Point2D;
 }
 //Operator overload for "*"
 Point2D Point2D::operator*(const Point2D &lhs) {
	 Point2D temp_Point2D;
	 temp_Point2D.x_point = this->x_point * lhs.x_point;
	 temp_Point2D.y_point = this->y_point * lhs.y_point;
	 return temp_Point2D;
 }
 
 //Operator overload for "/"
 Point2D Point2D::operator/(const Point2D &lhs) {
	 Point2D temp_Point2D;
	 temp_Point2D.x_point = this->x_point / lhs.x_point;
	 temp_Point2D.y_point = this->y_point / lhs.y_point;
	 return temp_Point2D;
 }
