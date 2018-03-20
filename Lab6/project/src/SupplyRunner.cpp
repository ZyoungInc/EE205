#include "SupplyRunner.hpp"
#include "Storeroom.hpp"
#include "Ingredient.hpp"

#include <string>
#include <vector>
#include <map>

//construct
SupplyRunner::SupplyRunner(Storeroom& storeroom_) :
	storeroom(storeroom_) {}
	
//Getter
std::vector<Ingredient> SupplyRunner::get_ingredients(IngredientMap ingredients) {
	
	//variables
	bool foundIngredient = false;
	
	//Setup mapping names
    std::map<Ingredient, unsigned>::iterator it = ingredients.begin();
	std::map<Ingredient, unsigned>::iterator it1 = storeroom.begin();
	
	//go through ingredients
	while(it != ingredients.end()){
		//check through the storeroom and quit if ingredent is found
		while(it1 != storeroom.end() && foundIngredient == false) {
			if(it->first == it1->first) {
				if(it->second <= it1->second) {
					foundIngredient = true;
				}
			}
			it1++;
		}
		
		if(foundIngredient == true) {
			//if ingredent were found reset 
			foundIngredient = false;
			it1 = storeroom.begin();
		}
		else {
			//if not, throw an error.
			throw "Not enough ingredent or ingredent not found";
		}
		it++;
	}
	
	//reset iterator
	it1 = storeroom.begin();
	it = ingredients.begin();
	
	//Go through again and remove ingredients, we don't have to check
	//if there not enough ingredients because we check it previously
	while(it != ingredients.end()){
		while(it1 != storeroom.end()) {
			if(it1->first == it->first) {
				it1->second -=  it->second;
			}
			it1++;
		}
		it++;
		it1 = storeroom.begin();
	}
	
	//reset iterator
	it = ingredients.begin();
	std::vector<Ingredient> returnIngredient;
	
	while(it != ingredients.end()) {
		for(unsigned  cnt = 0; cnt < it->second; cnt ++){	
			returnIngredient.push_back(it->first);
		}
		it++;
	}
	
	return returnIngredient;
}

std::map<std::string, std::map<Ingredient, unsigned>> recipes;
	