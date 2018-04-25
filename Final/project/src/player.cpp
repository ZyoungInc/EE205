#include <string>
#include <utility>
#include "game-utility.hpp"
#include "unit.hpp"
#include "player.hpp"

using namespace std;

pair <string, string>  Enemy::get_enemy_eff() {
	std::pair <string, string> temp_enemy_eff;
	temp_player_eff.first = eff_player.first;
	temp_player_eff.second = eff_player.second;
	return temp_enemy_eff;
}
