#include <string>
#include <utility>
#include "game-utility.hpp"
#include "Unit.hpp"
#include "player.hpp"

using namespace std;

pair <string, string>  Player::get_player_eff() {
	std::pair <string, string> temp_player_eff;
	temp_player_eff.first = player_eff.first;
	temp_player_eff.second = player_eff.second;
	return temp_player_eff;
}
