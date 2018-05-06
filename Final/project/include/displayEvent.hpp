#include "Player.hpp"

//This function ask if player chooses a random event
bool drawRandomEvent(int yMax_, int xMax_);

int drawHealEvent(int yMax_, int xMax_, Player *p);

int drawBeggerEvent(int yMax_, int xMax_, Player *p); 

int drawLootEvent(int yMax_, int xMax_, Player *p);

int drawRestingEvent(int yMax_, int xMax_, Player *p);

int drawTrapEvent(int yMax_, int xMax_, Player *p);

int drawEnemyEvent(int yMax_, int xMax_, Player *p);