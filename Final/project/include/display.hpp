#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <ncurses.h>

class Display {
private:
    Unit& Unit;
    int yshift;

public:
  

    void drawGame();
    int updateDialogue(std::vector<std::string> Dialogue, int yshift);
    int updateCombat(int name, int damage, int yshift);
    int updateDeath(int name, int yshift);
    void updateAvatarHUD(std::string name, int health, int mana, int attack, int defense);
    void updateEnemyHUD(std::string name, int health, int mana, int attack, int defense);
    void updateOptions();
    void drawMenu();
    //Getters
    int get_yshift();

    //Setters
    void set_yshift(int yshift_);
};



#endif /* DISPLAY_HPP */
