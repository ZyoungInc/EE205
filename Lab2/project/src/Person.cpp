#include "Person.hpp"
#include "Point2D.hpp"

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

void Person::set_location(Point2D coords) {
	location = coords;
}


