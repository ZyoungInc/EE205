#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"
#include "Color.hpp"
#include "Combat.hpp"
#include "Spells.hpp"
#include "displayMenu.hpp"
#include "displayChar.hpp"
#include "displayDialogue.hpp"
#include "displayOptions.hpp"
#include "displayEnemyHUD.hpp"
#include "displayPlayerHUD.hpp"
#include "displayEvent.hpp"

using namespace std;

int main() {
	//NCURSES START
    initscr();
    noecho();
    cbreak();

	srand(time(NULL));//seeds rng
	//get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
	int randNum = 0;
	bool rand_event_trigger = false;

	//Run game menu to get user's choice
	int state = 0; //use to track game's state
	pair<int, string> chInput;

	state = drawMenuDisplay(yMax, xMax);//displays title screen and ask if you want to play

	while (state == 1) {//while playing the game
		int stage = 1; //use to track player's tier level
		int souls = 0; //use to track how many kills player has
		chInput = drawCharDisplay(yMax, xMax);//displays character creation and returns that info
		Weapon weap;//create default starting weapon
		Weapon dropWeap;//creates default weapon drop

		displayOpeningDiag(yMax, xMax);//displays opening dialogue
		//Construct player
		Player p(chInput.second, chInput.first, souls, &weap);

		while(stage < 7) {//while in the game
			state = 3;//keeps you in correct state
			p.set_souls(souls);
			drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);//Displayes playerHUD
			Enemy e(stage);//Creates random enemy according to stage level
			drawEnemyDisplay(yMax, xMax, e);//displays enemyHUD
			Combat battle(&p, &e, yMax, xMax);//Commences combat constructor

			while(state != 1) {//while in combat
				state = drawOptionDisplay(yMax, xMax, chInput.first);//displays and waits for your battling displayOptions
				if(state == 1) {//if quit command is selecte
					stage = 7;//gets you out of game by bypassing endgame
					break;
				}
				else if(state == 7 && RandNum(1,5) == 2) {//if Flee command is selected
					//Flees only 25% of the time
					break;
				}
				else {
					state = battle.combat_phase(state, chInput.first, &p, &e);//takes in combat action and returns if someone dies
					drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);//updates playerHUD
					drawEnemyDisplay(yMax, xMax, e);//updates enemyHUD
				}
				if(state == 1)//if Enemy died
				{
					if(stage == 6)//if killed final boss
					{
						displayEndingDiag(yMax, xMax);//display ending dialogue
						stage++;//pushes you out of game
						break;
					}
					else//non-boss enemy died
					{
						if(chInput.first == 1)//if you are a warrior
						{
							if(RandNum(1,4) == 3)//randomly drop a weapon and asks if you want to equip
							{
								dropWeap = Warrior_Weap(stage);
								if(displayWeaponDrop(yMax, xMax, dropWeap) == true){
									weap = dropWeap;
									p.swap_weapon(&weap);
								}
							}
						}
						else//if you are a mage
						{
							if(RandNum(1,4) == 3)//randomly drop a weapon and asks if you want to equip
							{
								dropWeap = Mage_Weap(stage);
								if(displayWeaponDrop(yMax, xMax, dropWeap) == true){
									weap = dropWeap;
									p.swap_weapon(&weap);
								}
							}
						}
						souls++;//get the enemy that you killed soul
						if(souls > 4)//if you have 5 or more souls, asks if you want to move onto next stage
						{
							if(displayStageDiag(yMax, xMax, stage) == true)
							{
								stage++;
								souls = 0;//takes your souls to move onto next stage
							}
						}
						break;
					}
				}
				else if(state == 2)//Player died
				{
					displayDeathDiag(yMax, xMax);//display player death
					stage = 7;//get you out of game
					break;
				}
				
			}
			
			randNum = RandNum(1, 101);
			if(randNum >= 70) {
				rand_event_trigger = drawRandomEvent(yMax, xMax);
			}
			
			if(rand_event_trigger == true) {
				randNum = RandNum(1, 7);
				switch(randNum) {
					case 1: drawHealEvent(yMax, xMax, &p);
							break;
					case 2: drawBeggerEvent(yMax, xMax, &p);
							break;
					case 3: drawLootEvent(yMax, xMax, &p);
							break;
					case 4: drawRestingEvent(yMax, xMax, &p);
							break;
					case 5: drawTrapEvent(yMax, xMax, &p);
							break;
					default: // ambush event
							break;
				}
			}

			if(stage == 7) {//gets you out of game
				break;
			}
		}
		state = drawMenuDisplay(yMax, xMax);//displays title screen asks if you want to play again
	}

	endwin();//deallocates window memory
	return 0;//clean exit
}
