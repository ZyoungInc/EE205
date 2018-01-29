#include "Person.hpp"

// Default Constuctor
Person::Person() {
	name = "";
	location(0,0);
}

//Overloaded Constructor
Person::Person(std::string s, float x, float y) {
	name = s;
	location(x,y);
}

//Getters
std::string Person::get_name() {
	return name;
}

float Person::get_location() {
	return location;
}

//Setters
void Person::set_name(std::string s) {
	name = s;
}

void Person::set_location(float x, float y) {
	location(x,y);
}


