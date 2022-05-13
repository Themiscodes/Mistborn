
#ifndef MISTBORN_MESSAGES_H
#define MISTBORN_MESSAGES_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "grid.h"

using namespace std;
static int choice;
static Grid grid;
void worldbuilding();
int options();
void action(int);
void supply_the_markets();
void move(int);
void end();

#endif //MISTBORN_MESSAGES_H
