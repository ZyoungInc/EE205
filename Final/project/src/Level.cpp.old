#include "Level.hpp"
#include "combat.hpp"

//Constructor
Level::Level(int level_) :
  level(level_) {}

int enemy_level(int enemies_killed)
{
  int enemyLevel = 1;
  if(enemies_killed <= 5) enemyLevel = 1;
  else if(enemies_killed > 5 && enemies_killed <= 10) enemyLevel = 2;
  else if(enemies_killed > 10 && enemies_killed <= 15) enemyLevel = 3;
  else if(enemies_killed > 15 && enemies_killed <= 20) enemyLevel = 4;
  else if(enemies_killed > 20 && enemies_killed <= 25) enemyLevel = 5;
  else if(enemies_killed > 25 && enemies_killed <= 10) enemyLevel = 6;
  return enemyLevel;
}

int levelUp(int enemies_killed)
{
  int skillpoint = 0;
  if(enemies_killed <= 5) skillpoint = 0;
  else if(enemies_killed > 5 && enemies_killed <= 10) skillpoint = 1;
  else if(enemies_killed > 10 && enemies_killed <= 15) skillpoint = 2;
  else if(enemies_killed > 15 && enemies_killed <= 20) skillpoint = 3;
  else if(enemies_killed > 20 && enemies_killed <= 25) skillpoint = 4;
  else if(enemies_killed > 25 && enemies_killed <= 10) skillpoint = 5;
  return skillpoint;
}
