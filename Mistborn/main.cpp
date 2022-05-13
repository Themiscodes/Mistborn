
#include "messages.h"

int main() {
    worldbuilding(); //build the world
    int choose=9, rounds=0;
    choose=options();
    while (choose!=8){ //player options with 8 being quitting the game
        action(choose);
        rounds++;
        if (rounds%200==0) supply_the_markets(); //after every 200 rounds restock the markets
        choose=options();
    }
    end();
    return 0;
}
