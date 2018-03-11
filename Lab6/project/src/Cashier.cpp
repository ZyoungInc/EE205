#include "Cashier.hpp"
#include "Order.hpp"
#include "Customer.hpp"
#include "restaurant-utility.hpp"
#include "string_conversion.hpp"

#include <string>
#include <vector>
#include <map>

//Contructor
Cashier::Cashier(double money_) :
	money(money_){}
	
//Getter
double Cashier::get_money() const {
	return this->money;
}

void Cashier::serve_customer(std::queue<Customer>& line, std::stack<Order>& orders) {
	//Creates variables we will use;
	std::vector<std::string>  name_of_items;
	std::string name_of_item;
	unsigned int number_of_items;
	double total_cost = 0;
	
	//Grab the front customer and "pop" them off the queue
	Customer current_customer(line.front());
	line.pop();
	
	std::string customer_order = current_customer.get_order();
	
	//Convert customer's order into a vector of  name_of_items
	for(unsigned int cnt = 0; cnt < customer_order.size(); cnt++) {
		number_of_items = 0;
		name_of_item.clear();
		
		while(customer_order[cnt] != ' ') {
			//Convert character array into int
			if((customer_order[cnt] - 48) > 0 || (customer_order[cnt] - 48) <=9) {
				number_of_items = 10 * number_of_items;
				number_of_items += (customer_order[cnt] - 48);
			}
			else {
				throw "Not a valid value of items";
			}
			cnt++;
		}
		cnt++;
		
		//Grab customer's order
		while(customer_order[cnt] != ' ' && customer_order[cnt] != '\0' ) {
			name_of_item += customer_order[cnt];
			cnt++;
		}
		
		//Copy order by number of items
		for(unsigned int cnt1 = 0; cnt1 < number_of_items ; cnt1++) {
			name_of_items.push_back(lexical_cast(name_of_item));
		}
	}
	
	//Calculate total cost and validates customer's order
	try {
		total_cost = calculate_order_cost(name_of_items);
	}
	catch  (char const* c) {
		current_customer.expel();
	}

	//if customer doesn't have enough money, then expel him
	if(current_customer.get_money() < total_cost) {
		current_customer.expel();
	}
	//if customer isn't expelled then take his order
	else if (false == current_customer.is_expelled()) {
		current_customer.charge_money(total_cost);
		this->money += total_cost;
		Order current_customer_order(orders.size(), name_of_items);
		orders.push(current_customer_order);
	}
}