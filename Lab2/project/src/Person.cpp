#include "Person.hpp"

// Default Constuctor
Person::Person() {
	name = "";
	Point2D location(0,0);
}

//Overloaded Constructor
Person::Person(std::string s, float x, float y) {
	name = s;
	Point2D location(x,y);
}

//Getters
std::string Person::get_name() {
	return name;
}

Point2D Person::get_location() {
	return location;
}

//Setters
void Person::set_name(std::string s) {
	name = s;
}
/*
void Person::set_location(float x, float y) {
	Point2D location(x,y);
}
*/

void Person::set_location(const Point2D &temp_l) {
	Point2D location(x,y);
}
