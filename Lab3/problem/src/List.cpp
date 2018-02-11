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
	
	ListNode *new_node = new ListNode(num);
		
	if(head == nullptr) { //if the list is empty
		this->head = new_node;
	}
	else { //if not empty, traverse to end of list marked as null
		//Create a temporary pointer to the head
		ListNode *temp_list = this->head;
		while(temp_list->get_next() != nullptr) {
			//if the temp_head isn't the end, move onto next until you find the end
			temp_list = temp_list->get_next();
		}
		temp_list->set_next(new_node);
	}
	this->length++;
}

void List::insert(int index, int num) {
	if(index < 0 || index > this->length) {
		throw "Error: Index cannot be less than 0";
	} 
	
	//Traverse through the list X amount of time to see if its a nullpointer(end)
	//if so, throw an exception
	ListNode *temp_list = this->head;
	ListNode *new_node = new ListNode(num);
	if(index == 0) {
		//ListNode *old_nodes = this->head;
		this->head = new_node;
		this->head->set_next(temp_list);
	}
	else {
		for(int i = 1; i < index; i++) {
			if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			std::cout << "stuck" << std::endl; //test
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		

		new_node->set_next(temp_list->get_next());
		temp_list->set_next(new_node);
	
		std::cout << "insert finshed" << std::endl; //test
	}
	this->length++;
	
}

void List::remove(int index) {
	//Traverse through the list X amount of time to see if its a nullpointer(end)
	//if so, throw an exception
	ListNode *temp_list = this->head;
	if(index < 0 || temp_list == nullptr) {
		throw "Error: Index cannot be less than 0";
	} 
	
	if(index == 0) {
		this->head = temp_list->get_next();
	}
	else {
		for(int i = 1; i < index; i++) {
			if(temp_list == nullptr) { 
				throw "Out of bound";
			}
			//move through the list by 1
			temp_list = temp_list->get_next();
		}
		temp_list->set_next(nullptr);
	}
	this->length--;
	
}

int List::get(int index) const {
	//Traverse through the list X amount of time to see if its a nullpointer(end)
	//if so, throw an exception
	ListNode *temp_list = this->head;
	if(index < 0 || index > this->length) {
		throw "Error: Index cannot be less than 0";
	} 
	
	if(index == 0) {
		return temp_list->get_data();
	}
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

int& List::operator[](int index) {
	//Traverse through the list X amount of time to see if its a nullpointer(end)
	//if so, throw an exception
	
	ListNode *temp_list = this->head;
	if(index < 0 || index > this->length) {
		throw "Error: Index cannot be less than 0";
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

