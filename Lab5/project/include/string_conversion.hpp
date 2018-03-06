#ifndef EE205_STRING_CONVERSION_HPP
#define EE205_STRING_CONVERSION_HPP

#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string lexical_cast(T obj) {
    // Create a std::stringstream
    // Using operator<<, output the object to it
    // Take the std::string from the stringstream
	std::stringstream ss;
	ss << obj;
    return ss.str();
}

template <typename T>
std::string vector_to_string(std::vector<T>& items) {
    // For each item in the vector
    // Get the string representation of it
    // Put a comma after it if it's not the last element
    // Accumuate that string into a final result
	std::string s;
	//Iterate through the vector 
	for(unsigned int i = 0; i < items.size(); i++) {
		s.append(lexical_cast(items[i]));
		//append each vector to string
		if(i != items.size() - 1) {
			//if its not the last item of vector, then add a ","
			s.append(",");
		}
	}
    return s;
}

#endif // EE205_STRING_CONVERSION_HPP 
