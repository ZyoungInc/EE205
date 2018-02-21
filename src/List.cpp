#include "List.hpp"
#include <iostream>
#include <utility>

//Default constructor
List::List() :
	head(nullptr),
	length(0) {}
	
//Copy constructor	
List::List(const List& other) :
	head(head),
	length(length) {}
	
//Move 
List::List(List&& other) :
	head(std::move(other.head)),
	length(std::move(other.length)) {
		other.length = 0;
		other.head = nullptr;
	}
	
	
List::~List(){
	delete this->head;
}

void List::append(int num) {
	
	//creates a temporary node
	ListNode *new_node = new ListNode(num);
		
	if(this->head == nullptr) { //if the list is empty
		this->head = new_node;//attach temporary node to the head
	}
	else { //if not empty, traverse to end of list marked as null
		//Create a temporary pointer to the head
		ListNode *temp_list = this->head;
		while(temp_list->get_next() != nullptr) {
			//if the temp_list isn't the end, move onto next until you find the end
			temp_list = temp_list->get_next();
		}
		//assigns temp_list pointer to the node before nullptr
		temp_list->set_next(new_node);
	}
	//acculumates length by one
	this->length++;
}

void List::insert(int index, int num) {
	//if index is out of bounds throw error
	if(index < 0 || index > this->length) {
		throw "Error: Index is out of bounds";
	} 
	
	//set temporary pointer to head
	ListNode *temp_list = this->head;
	//creates temporary node
	ListNode *new_node = new ListNode(num);
	if(index == 0) {//if inserting at the head
		//Make new node the head and attach the previous head to next
		this->head = new_node;
		this->head->set_next(temp_list);
	}
	else {//if inserting not at the head
		for(int i = 1; i < index; i++) { //traverse through list until inserting at index
		//if inserting at last node, throw it out of bounds
		if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		
		//set new node pointer to current pointer and current to next
		new_node->set_next(temp_list->get_next());
		temp_list->set_next(new_node);
	
	}
	//acculumate length by 1
	this->length++;
	
}

void List::remove(int index) {
	//set temporary pointer to head
	ListNode *temp_list = this->head;
	//if index is not in list throw it out of bounds
	if(index < 0 || temp_list == nullptr) {
		throw "Error: Index is out of bounds";
	} 
	//if removing head set current head to next
	if(index == 0) {
		this->head = temp_list->get_next();
	}
	//removing from anywhere else in list
	else {
		//traverse list to index
		for(int i = 1; i < index; i++) {
			if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		//sets last list before nullptr to last node
		temp_list->set_next(nullptr);
	}
	//remove one from length
	this->length--;
	
}

int List::get(int index) const {
	//sets temporary pointer to head
	ListNode *temp_list = this->head;
	//if index is out of bounds throw error
	if(index < 0 || index > this->length) {
		throw "Error: Index is out of bounds";
	} 
	//return data at head
	if(index == 0) {
		return temp_list->get_data();
	}
	//return data at index
	else { 
		for(int i = 0; i < index; i++) {
			if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		return temp_list->get_data();
	}
	
}

std::size_t List::size() const {
	return this->length;
}

//bracket operator that references data at index
int& List::operator[](int index) {
	//creates temporary pointer at head
	ListNode *temp_list = this->head;
	//if index is out of bounds throw error
	if(index < 0 || index > this->length) {
		throw "Error: Index is out of bounds";
	} 
	
	if(index == 0) {
		return temp_list->data;
	}
	else {
		for(int i = 0; i < index; i++) {
			if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		return temp_list->data;
	}
}

