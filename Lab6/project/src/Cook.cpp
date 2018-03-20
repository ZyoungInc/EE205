#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>
//using RecipeBook = std::map<std::string, std::map<Ingredient, unsigned>>; 
//using IngredientMap = std::map<Ingredient, unsigned int>;


Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) :
	runner(runner_),
	kitchen(kitchen_) {}
	
void Cook::prepare_dish(
	std::stack<Order>& orders, 
	std::queue<std::pair<std::size_t, Dish>>& finished_dishes) {
	
	//variables
	std::vector<std::string> order_list;
	std::pair<std::size_t, Dish> finished_item;
	bool found_ingredient = false;
	std::map<std::string, std::map<Ingredient, unsigned>>::iterator it = recipes.begin();
	
	//temp copy of an ingredient map
	std::map<Ingredient, unsigned> temp_things;
	
	//if order is empty then do nothing
	if(orders.empty() == false) {
	
		//Take order off stack and "pop it"
		Order current_order = orders.top();
		orders.pop();
		
		//Convert current order into a vector of strings
		order_list = current_order.get_items();
	
		//Go through the vector of orders and create a dish for each single order
		for(unsigned int i = 0; i < order_list.size(); i++) {
			
			//Iterate through the recipe until its found, we know the order is valid 
			//because cashier didn't expel customer
			while(it != recipes.end() && found_ingredient == false) {
				
				if(it->first == order_list[i]) {
					
					//When the order matches the recipe it add an ID
					finished_item.first = current_order.get_id();
					
					try {
						//if runner throws an error, then there is not enough ingredient
						runner.get_ingredients(it->second);
					}
					catch (char const* c) {
						throw c ;
					}
					//Temp variables so it can be "move"
					temp_things = it->second;
					
					finished_item.second = kitchen.prepare_dish(std::move(temp_things));
					//push out final product
					finished_dishes.push(finished_item);
					
					found_ingredient = true;
				}
				it++;
			}
			//Reset the iterator
			found_ingredient = false;
			it = recipes.begin();
		}
	}
}

