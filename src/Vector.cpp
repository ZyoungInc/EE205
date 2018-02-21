#include "Vector.hpp"
#include <utility>

//Standard default constructor
Vector::Vector():
	arr(new int[1]),
	length(0),
	capacity(1) {}

//copy operator
Vector::Vector(const Vector& other):
	arr(new int[other.capacity]),
	length(other.size()),
	capacity(other.capacity) {
	//Iterate through the other array and copy its values
	for(std::size_t i=0; i < other.size(); i++){
		this->arr[i] = other.arr[i];}
	}

//Move operator
Vector::Vector(Vector&& other):
	//Create array with move operations
	arr(std::move(other.arr)),
	length(std::move(other.length)),
	capacity(std::move(other.capacity)){
		//Destory previous object
		other.arr = nullptr;
		other.length = other.capacity = 0;
	}

//Setters
void Vector::append(int num){
	//Bound check, if its already at or greater than cap, throw error.
	if(this->capacity <= this->length) {
			throw "the index is out of bounds";
	}
	//append number at end and increase length
	this->arr[length] = num;
	this->length++;
}

void Vector::insert(int index, int num){
	//Check if index is out of bounds
	if(index < 0 || index > this->length) {
		throw "Vector.index is out of bounds";
	}
	//Check to see if there is capacity
	else if(this->length + 1 >= this->capacity) {
		this->double_capacity();
	}
	//Illiterate through the array
	for(int i = this->length; i > index; i--) {
		this->arr[i] = this->arr[i-1];
	}
	//Finally insert num into array and increase length by 1
	this->arr[index] = num;
	this->length++;
}

void Vector::remove(int index){
	//Check if index is out of bound
	if(index < 0 || index >= this->length) {
		throw "the index is out of bounds";
	}
	//Illiterate at index down by 1
	for(std::size_t i = index; i < this->length; i++) {
		this->arr[i] = this->arr[i+1];
	}
	//reduce length by 1
	this->length--;
}
	
//Getters
int Vector::get(int index) const{
	if(index < 0 || index >= this->length) {
		throw "the index is out of bounds";
	}
	return this->arr[index];
}

std::size_t Vector::size() const{
	return this->length;
}
	
int& Vector::operator[](int index){
	if(index < 0 || index > this->capacity ) {
		throw "the index is out of bounds";
	}
	return this->arr[index];
}

Vector::~Vector(){
	delete [] arr;
}

void Vector::double_capacity(){
	//Allocate memory with double the old capacity
	int *temp_arr = new int[this->capacity*2];
	
	//Copy old values into new arry
	for(std::size_t i=0;i < this->length;i++) {
		temp_arr[i] = arr[i];
	}
	//Delete the old array
	delete [] arr;
	
	//Assign the old array as the newly made array;
	arr = temp_arr;
	
	//set the old capacitor to double of its original value.
	this->capacity=this->capacity*2;
}