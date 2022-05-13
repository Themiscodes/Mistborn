
#ifndef MISTBORN_GRID_H
#define MISTBORN_GRID_H

#include <iostream>
#include <ostream>
#include <iomanip>
#include <limits>
#include <ios>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "characters.h"
#include "items.h"
#include "customlist.h"

class Square{
    protected:
        int type;
        vector<Hero*> heroes_here;
        bool heroes_present;
    public:
        Square(int type=0);
        int getType() const {return type;}
        void place(Hero* );
        bool isHeroesPresent() const;
        int average_level();
        void setHeroesPresent(bool heroesPresent);
        void checkInventory();
        void displayStats();
        int battle_options();
        void shopping_time();
        void battle(monsterList&);
        bool monstersWin();
        bool heroesWin(int, int);
        Hero* exit();
        virtual string getMarketName();
        virtual void display_stock(int , Hero* );
        virtual int market_options();
        virtual void restock(Weapon*[], Armor*[], Potion*[], Spell*[]);
};

class common : public Square{
    public:
        explicit common(int type=1) : Square(type){}
};

class nonAccessible : public Square{
    public:
        explicit nonAccessible( int type=2): Square(type){};
};

class market : public Square{
    private:
        string market_name;
        Weapon* weapons_storage[6][7];
        Armor* armours_storage[4][4];
        Potion* potions_storage[12][20];
        Spell* spells_storage[9][16];
    public:
        explicit market(Weapon*[], Armor*[], Potion*[], Spell*[], int type=3, const string& name="Market Inn");
        string getMarketName();
        void restock(Weapon*[], Armor*[], Potion*[], Spell*[]);
        int market_options();
        void display_stock(int , Hero* );
};

class Grid{
    private:
        int heroes;
        int positionX;
        int positionY;
        static const int gridRows=19;
        static const int gridColumns=19;
        Square* board[gridRows][gridColumns];
        Monster* monsters[25];
        Weapon* weapons[6];
        Armor* armours[4];
        Potion* potions[12];
        Spell* spells[9];
    public:
        Grid();
        void displayMap();
        void setHeroSize(int);
        void place_on_the_board(Hero*);
        void my_options();
        bool check_option(int );
        void checkInventory();
        void shopping_time();
        void displayStats();
        void restock();
        void battle();
        bool inside_a_market();
        void move(int);
        ~Grid(){ }
};

#endif //MISTBORN_GRID_H
