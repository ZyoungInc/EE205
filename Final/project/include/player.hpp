#include <iostream>
#include <string>
#include <vector>
#include "Unit.hpp"

using namespace std;

class Player : public Unit{
	private:
		pair <string, string> player_eff;
	public:
		pair <string, string>  get_player_eff(void);
};
