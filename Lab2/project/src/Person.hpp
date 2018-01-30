#ifndef PERSON_HPP
#define PERSON_HPP

#include "Point2D.hpp"

// std::string is a class from the C++ standard
// library that can be default-constructed
// and constructed from a C-style string (string
// literal like "Hello world")
#include <string>

// Make sure to use both Point2D and std::string
// as member variables in the class below.
class Person { 
private:
	std::string name;
	Point2D location;
public:
	//Default Constuctor
	Person();
	

	//Overloaded Constructor
	Person(std::string s, float x, float y);

	//Getters
	std::string get_name();
	Point2D get_location();

	//Setters
	void set_name(std::string s);
	void set_location(Point2D coords);
	


};

#endif // PERSON_HPP
