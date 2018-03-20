#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>
//using RecipeBook = std::map<std::string, std::map<Ingredient, unsigned>>; 

RecipeBook recipes;

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) :
	runner(runner_),
	kitchen(kitchen_) {}
	/*
void Cook::prepare_dish(
	std::stack<Order>& orders, 
	std::queue<std::pair<std::size_t, Dish>>& finished_dishes) {
		
	std::vector<std::string> order_list;
	std::map<Ingredient, unsigned> required_ingredientsl;
	std::pair<std::size_t, Dish> finished_item;
	
	while(orders.empty() == false) {
		
		Order current_order = orders.top();
		orders.pop();
		order_list = current_order.get_items();
	
		for(unsigned int i = 0; i < order_list.size(); i++) {
			auto search = recipes.find(order_list[i]);
			if(search != recipes.end()) {
				try {
					finished_item.first = current_order.get_id();
					finished_item.second = kitchen.prepare_dish(runner.get_ingredients(search->second));
					finished_dishes.push(finished_item);
				}
				catch (char const* c) {
					throw c;
				}
			}
			else {
				throw  "Not found\n";
			}
		}
	}
}

*/