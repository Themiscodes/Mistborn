#include "messages.h"
#include "characters.h"
#include "grid.h"

void worldbuilding(){
    cout << "\n Welcome to the world of Mistborn!" << endl;
    int heroes=1;
    do {
        cout << "\n How many heroes would you like on your adventure 1, 2 or 3 ?" << endl;
        cout << "\n> ";
        cin >> heroes;
        if(!cin){
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input, next, request user reinput
        }
    }while (heroes!=1&&heroes!=2&&heroes!=3); //user didn't input 1,2 or 3
    grid.setHeroSize(heroes);
    for (int i=0;i<heroes;i++){
        if (heroes==1){
            cout << "\n What type of hero do you want to be?" <<endl;
        }
        else cout << "\n Your hero number " <<i+1<<" is a: " <<endl;
        do {
            cout << "\n 1. Sorcerer" <<endl;
            cout << "\n 2. Warrior" <<endl;
            cout << "\n 3. Paladin" <<endl;
            cout << "\n> ";
            cin >> choice;
            if(!cin){
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }while (choice!=1&&choice!=2&&choice!=3); //user didn't input 1,2 or 3
        string input;
        cout << "\n What is their name?"<<endl;
        cout << "\n> ";
        cin >> input;
        if (choice == 1)  grid.place_on_the_board(new Sorcerer(input));
        else if (choice == 2)  grid.place_on_the_board(new Warrior(input));
        else if (choice == 3)  grid.place_on_the_board(new Paladin(input));
    }
    if (heroes==1) cout << "\n Hero Created! Let's begin! " <<endl;
    else cout << "\n Team Assembled! Let's begin! "<<endl;
    grid.displayMap();
}

int options(){
    do{
        cout << "\nWhat would you like to do?" << endl<<endl;
        grid.my_options();
        cout << "\n> ";
        cin >> choice;
        if(!cin){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (!grid.check_option(choice)); //user didn't choose one of the options given to him.
    return choice;
}

void action(int choice2){
    if (choice2 == 1) move(1);
    else if(choice2 == 2) move(2);
    else if(choice2 == 3) move(3);
    else if(choice2 == 4) move(4);
    else if(choice2 == 5) grid.checkInventory();
    else if(choice2 == 6) grid.displayStats();
    else if(choice2 == 7) grid.displayMap();
}

void move(int choice2){
    grid.move(choice2);
    if (grid.inside_a_market()){
        grid.shopping_time();
    }
    else {
        srand(time(NULL));
        if (rand()%5 == 1) {
            grid.battle();
        }
        else {
            cout << "\n You tread carefully, no monster is in sight.\n";
        }
    }
}

void supply_the_markets(){
    grid.restock();
}

void end() {
    cout << "\n Thank you for playing Mistborn!" << endl;
    cout << "\n ";
}

