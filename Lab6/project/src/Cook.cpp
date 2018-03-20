#include "Dish.hpp"
#include "Order.hpp"
#include "SupplyRunner.hpp"
#include "Kitchen.hpp"
#include "Cook.hpp"

#include <queue>
#include <stack>
//using RecipeBook = std::map<std::string, std::map<Ingredient, unsigned>>; 
//using IngredientMap = std::map<Ingredient, unsigned int>;

RecipeBook recipes;

Cook::Cook(SupplyRunner& runner_, Kitchen& kitchen_) :
	runner(runner_),
	kitchen(kitchen_) {}
	
void Cook::prepare_dish(
	std::stack<Order>& orders, 
	std::queue<std::pair<std::size_t, Dish>>& finished_dishes) {
		
	std::vector<std::string> order_list;
	std::vector<Ingredient> v_supplies_needed;
	std::pair<std::size_t, Dish> finished_item;
	bool found_ingredient = false;
	std::map<std::string, std::map<Ingredient, unsigned>>::iterator it = recipes.begin();
	
	std::map<Ingredient, unsigned> temp_things;
	
	
	while(orders.empty() == false) {
		
		Order current_order = orders.top();
		orders.pop();
		order_list = current_order.get_items();
	
		for(unsigned int i = 0; i < order_list.size(); i++) {
			while(it != recipes.end() && found_ingredient == false) {
				if(it->first == order_list[i]) {
					
					finished_item.first = current_order.get_id();
					
					try {
						v_supplies_needed = runner.get_ingredients(it->second);
					}
					catch (char const* c) {
						std::cout << c << std::endl;
					}
					temp_things = it->second;
					finished_item.second = kitchen.prepare_dish(std::move(temp_things));
					finished_dishes.push(finished_item);
					
					found_ingredient = true;
				}
				it++;
			}
			found_ingredient = false;
			it = recipes.begin();
		}
	}
}

