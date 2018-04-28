#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <ncurses.h>

class Display {
private:
    Unit unit;
    int yshift = 1;
    int selecter = 1;

public:
  //Constructor
  Display(int yshift_, int selecter_);

    void drawGame();
    int updateDialogue(std::vector<std::string> Dialogue);
    int updateCombat(int name, int damage);
    int updateDeath(int name);
    void updateAvatarHUD(Unit player);
    void updateEnemyHUD(Unit enemy);
    void updateOptions();
    void drawMenu();
    //Getters
    int get_yshift();

    //Setters
    void set_yshift(int y);
};



#endif /* DISPLAY_HPP */
