#include "Vector.hpp"

#include <utility>

Vector::Vector():
	arr(new int[1]),
	length(0),
	capacity(1) {}

Vector::Vector(const Vector& other):
	arr(new int[other.size()]),
	length(other.size()),
	capacity(other.capacity()) {
	for(std::size_t i=0; i < other.size(); i++){
		this->arr[i] = other.arr[i];}}

Vector::Vector(Vector&& other):
	arr(0),
	length(0),
	capacity(0) {}

void append(int num){
	if(capacity(other.capacity())
		throw const char*
	


void insert(int index, int num){
	if(out)
		throw const char*
	this->length

void remove(int index){
	if(out)
		throw const char*
	get number at index

int get(int index) const{
	return length;

std::size_t size() const{
	return ref;

int& operator[](int index){
	 

Vector::~Vector(){
	delete arr[];
}

