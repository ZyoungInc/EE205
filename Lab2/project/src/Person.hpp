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
	Point2D();

	//Overloaded Constructor
	Person(std::string s, float x, float y);

	//Getters
	std::string get_name();
	float get_location();

	//Setters
	void set_string(std::string s);
	void set_location(float x, float y);
	

	
};

#endif // PERSON_HPP
