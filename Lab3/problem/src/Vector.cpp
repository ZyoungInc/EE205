#include "Vector.hpp"
#include <utility>

//Standard default constructor
Vector::Vector():
	arr(new int[1]),
	length(0),
	capacity(1) {}

//copy operator
Vector::Vector(const Vector& other):
	arr(new int[other.size()]),
	length(other.size()),
	capacity(other.capacity) {
	for(std::size_t i=0; i < other.size(); i++){
		this->arr[i] = other.arr[i];}}

//Move operator
Vector::Vector(Vector&& other):
	arr(std::move(other.arr)),
	length(std::move(other.length)),
	capacity(std::move(other.capacity)){}


void Vector::append(int num){
	if(capacity < this->length+1) {
			throw "the index is out of bounds";
	}
	this->arr[length+1] = num;
}
	
void Vector::insert(int index, int num){// over write with instructors!!!
	if(index < 0 || index > capacity) {
		throw "the index is out of bounds";
	}
	else if ((length+1) > capacity ) {
		this->double_capacity();
	}
	for(std::size_t i=index;i <= length-1;i++) {
		this->arr[i+1] = arr[i];
	}
	arr[index] = num;
	this->length++;
}

void Vector::remove(int index){
	if(index < 0 || index > length - 1) {
		throw "the index is out of bounds";
	}
	for(std::size_t i=index;i <= length-1;i++) {
		this->arr[i] = arr[i+1];
	}
	this->length--;
}
	
int Vector::get(int index) const{
	if(index < 0 || index >= capacity ) {
		throw "the index is out of bounds";
	}
	return this->arr[index];
}

std::size_t Vector::size() const{
	return this->length;
}
	
int& Vector::operator[](int index){
	if(index < 0 || index >= capacity ) {
		throw "the index is out of bounds";
	}
	return this->arr[index];
}

Vector::~Vector(){
	delete [] arr;
}

void Vector::double_capacity(){
	int *temp_arr = new int[this->capacity*2];
	for(std::size_t i=0;i <= this->length-1;i++) {
		temp_arr[i] = arr[i];
	}
	delete [] arr;
	arr = temp_arr;
	this->capacity=this->capacity*2;
}