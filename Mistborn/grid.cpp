
#include <iostream>
#include "grid.h"

using namespace std;

namespace Color {
    enum Code {
        FG_BLACK    = 30,
        FG_DEFAULT  = 39,
        BG_YELLOW   = 103,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
        public:
            explicit Modifier(Code pCode) : code(pCode) {}
            friend ostream&operator<<(ostream& os, const Modifier& mod) {
                return os << "\033[" << mod.code << "m";
            }
    };
    Modifier red(BG_RED);
    Modifier black(FG_BLACK);
    Modifier giallo(BG_YELLOW);
    Modifier water(BG_BLUE);
    Modifier grass(BG_GREEN);
    Modifier def(FG_DEFAULT);
    Modifier def2(BG_DEFAULT);
}

Grid::Grid() {
    this->heroes=1;
    this->positionX=18;
    this->positionY=9;
    //Dragons
    monsters[24]= new Dragon("Yolen", 9, 125, 36, 800, 0.5);
    monsters[23]= new Dragon("Threnody", 8, 90, 32, 650, 0.4);
    monsters[22]= new Dragon("Catacendre",7, 85,  23, 420, 0.3);
    monsters[21]= new Dragon("Sleepless",5, 75,  16, 60, 0.2);
    //Exoskeletons
    monsters[20]= new Exoskeleton("Ruin",9, 120, 33, 900, 0.3);
    monsters[19]=new  Exoskeleton("Inquisitor", 8, 100, 31, 700, 0.24);
    monsters[18]= new Exoskeleton("Marsh",7, 90, 20, 550, 0.2);
    monsters[17]= new Exoskeleton("Quellion",6, 80, 18, 200, 0.18);
    monsters[16]= new Exoskeleton("Roshar",5, 70, 13, 70, 0.15);
    monsters[15]=new  Exoskeleton("Scadrial",4, 60, 12, 38, 0.12);
    monsters[14]= new Exoskeleton("Harms",3, 40, 8, 20, 0.1);
    monsters[13]= new Exoskeleton("Seran",2, 25, 5, 8, 0.08);
    monsters[12]= new Exoskeleton("Gin",1, 10,  2, 2, 0.05);
    //Spirits
    monsters[11]= new Spirit("Adonalsium", 10, 140, 38, 1000, 0.72);
    monsters[10]= new Spirit("TenSoon", 9, 120, 34, 750, 0.65);
    monsters[9]= new Spirit("MeLaan", 8, 100, 30, 600, 0.6);
    monsters[8]= new Spirit("Waxillium", 7, 95, 21, 360, 0.55);
    monsters[7]= new Spirit("Renarin", 6, 85, 18, 140, 0.50);
    monsters[6]= new Spirit("Haddek", 5, 75, 14, 52, 0.45);
    monsters[5]= new Spirit("VarSel", 4, 65, 13, 30, 0.35);
    monsters[4]= new Spirit("Ladrian", 3, 50, 9, 16, 0.33);
    monsters[3]= new Spirit("KanPaar", 3, 40, 8, 14, 0.3);
    monsters[2]= new Spirit("RaShek", 2, 30, 7, 6, 0.28);
    monsters[1]= new Spirit("OreSeur", 2, 25, 6, 5, 0.26);
    monsters[0]= new Spirit("Kandra", 1, 10, 2, 1, 0.2);
    //Weapons
    weapons[0]= new Weapon("Dagger", 1.2, 1, 2, false);
    weapons[1]= new Weapon("Sword", 2.6, 2, 4, false);
    weapons[2]= new Weapon("Metal Spike", 9.8, 4, 10, true);
    weapons[3]= new Weapon("Iron Club", 16.8, 5, 15, true);
    weapons[4]= new Weapon("Scimitar", 24.4, 6, 17, false);
    weapons[5]= new Weapon("Longsword", 32.8, 8, 40, true);
    //Armors
    armours[0]=new  Armor("Dark Cloak", 2, 2, 10);
    armours[1]= new Armor("Leather Armour", 4, 4, 34);
    armours[2]= new Armor("Obsidian Plate Armour", 10, 6, 60);
    armours[3]= new Armor("Mist Cloak", 18, 8, 100);
    //Potions
    potions[0]= new Potion("Pewter", 0.8, 1, "Potion", false, 2, "Agility");
    potions[1]=new  Potion("Brass", 0.8, 1, "Potion", false, 2, "Strength");
    potions[2]=new  Potion("Zinc", 0.8, 1, "Potion", false, 2, "Dexterity");
    potions[3]= new Potion("Copper", 2.8, 3, "Potion", false, 4, "Agility");
    potions[4]= new Potion("Chromium", 2.8, 3, "Potion", false, 4, "Strength");
    potions[5]= new Potion("Duralumin", 2.8, 3, "Potion", false, 4, "Dexterity");
    potions[6]= new Potion("Nicrosil", 4.8, 5, "Potion", false, 6, "Agility");
    potions[7]= new Potion("Steel", 4.8, 5, "Potion", false, 6, "Strength");
    potions[8]= new Potion("Cadmium", 4.8, 5, "Potion", false, 6, "Dexterity");
    potions[9]= new Potion("Malatium", 0.4, 1, "Potion", false, 30, "Health");
    potions[10]= new Potion("Lerasium", 0.8, 1, "Potion", false, 60, "Health");
    potions[11]= new Potion("Atium", 1.2, 1, "Potion", false, 100, "Health");
    //Spells
    spells[0]= new IceSpell("Soothing", 2.8, 2, 30, 3);
    spells[1]= new IceSpell("Snapping", 5.8, 3, 40, 6);
    spells[2]= new IceSpell("Pulsing", 9.8, 5, 70, 10);
    spells[3]= new FireSpell("Inflaming", 2.8, 1, 10, 2);
    spells[4]= new FireSpell("Flaring", 6.8, 3, 35, 10);
    spells[5]= new FireSpell("Burning", 11.2, 4, 60, 15);
    spells[6]= new LightningSpell("Allomancing", 2.8, 1, 10, 2);
    spells[7]= new LightningSpell("Storming", 7.8, 2, 40, 10);
    spells[8]= new LightningSpell("Misting", 14.2, 6, 80, 18);
    //Grass (common) Squares
    for(int i=0;i<gridColumns;i++){
        for(int j=0;j<gridRows;j++) {
            board[j][i] = new common(1);
        }
    }
    //Lakes (nonAccesible) Squares
    for(int i=0;i<5;i++) {
        for(int j=0;j<9-i;j++){
            board[i][j] = new nonAccessible(2);
        }
    }
    for(int j=0;j<5;j++){
        board[5][j] =new  nonAccessible(2);
    }
    for(int j=12;j<16;j++) {
        for(int i=j-2;i<17;i++){
            board[j][i] =new  nonAccessible(2);
        }
    }
    for(int i=18;i>15;i--) {
        for (int j=18;j>i-1;j--) {
            board[18 - i][j] =  new nonAccessible(2);
        }
    }
    for(int i=7;i<12;i++) {
        board[i][i+3] = new nonAccessible(2);
    }
    for(int i=7;i<12;i++) {
        board[i][i+2] = new  nonAccessible(2);
    }
    for(int i=10;i<15;i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = new  nonAccessible(2);
        }
    }
    board[15][0] = new nonAccessible(2);
    board[11][12] =  new nonAccessible(2);
    board[15][12] =  new nonAccessible(2);
    board[16][0] =  new nonAccessible(2);
    //Market Squares
    board[0][10] =new  market(weapons, armours, potions, spells, 3, "Luthadel's Market");
    board[6][16] = new market(weapons, armours, potions, spells, 3, "Aspen Row's Market");
    board[9][9] = new market(weapons, armours, potions, spells, 3, "Grainfield's Market");
    board[15][3] = new market(weapons,armours, potions, spells, 3, "Kelsier's Market");
    board[17][18] = new market(weapons, armours, potions, spells,  3, "Brassgate's Market");
}

void Grid::setHeroSize(int her=1){
    this->heroes=her;
}

void Grid::displayMap(){
    cout<<endl;
    cout<<" ";
    int i=1, j=0;
    for(j = 0; j <= 4*gridColumns; j++){
        if(i<10){
            if(j%4==2)
                cout<<i++;
            else
                cout<<" ";
        }
        else if (i<20){
            if(j%3==1)
                cout<<i++;
            else
                cout<<" ";
        }
    }
    cout<<endl;
    for(i = 0; i <= 2 * gridRows; i++){
        if(i%2!=0)
            cout<<(char)(i/2 +'A');
        for(j = 0; j <= 2 * gridColumns; j++){
            if(i%2==0)
            {
                if(j==0)
                    cout<<" ";
                if(j%2==0)
                    cout << Color::grass << " " << Color::def2;
                else cout << Color::grass << "---" << Color::def2;
            }
            else{
                if(j%2==0)
                    cout << Color::grass << "|" << Color::def2;
                else {
                        switch (board[(i-1)/2][(j-1)/2]->getType()) {
                            case 1:
                                if(board[(i-1)/2][(j-1)/2]->isHeroesPresent())
                                    cout << Color::giallo << Color::black << "^_^" << Color::def << Color::def2;
                                else
                                    cout << Color::grass << "   " << Color::def2;
                                break;
                            case 2:
                                cout << Color::water << "   " << Color::def2;
                                break;
                            case 3:
                                if ((positionX==(i-1)/2)&&(positionY==(j-1)/2)) cout << Color::giallo << Color::black << "^_^" << Color::def << Color::def2;
                                else cout << Color::red << " M " << Color::def2;
                                break;
                        }
                }
            }
        }
        if(i%2!=0)
            cout<<(char)(i/2 +'A');
        cout<<endl;
    }
    cout<<" ";
    for(j = 0, i=1; j <= 4*gridColumns; j++){
        if(i<10){
            if(j%4==2)
                cout<<i++;
            else
                cout<<" ";
        }
        else if (i<20){
            if(j%3==1)
                cout<<i++;
            else
                cout<<" ";
        }
    }
    cout<<endl<<endl;
    cout << "You: "<< Color::giallo << Color::black << "^_^" << Color::def << Color::def2 << "     ";
    cout << "Market: " << Color::red << " M " << Color::def2 << "     ";
    cout << "Grass (walkable): " << Color::grass << "   " << Color::def2<< "     ";
    cout << "Lake (inaccesible): " << Color::water << "   " << Color::def2;
    cout<<endl;
}

void Grid::place_on_the_board(Hero* hero){
    board[18][9]->place(hero);
    board[18][9]->setHeroesPresent(true);
    positionX=18;
    positionY=9;
}

void Grid::my_options(){
    if(positionX-1>=0&&board[positionX-1][positionY]->getType()!=2){
        cout << " 1. Move Up \t\t\t\t\t";
    }
    else cout << " Up Inaccessible \t\t\t\t";
    if(positionX+1<gridColumns&&board[positionX+1][positionY]->getType()!=2){
        cout << " 2. Move Down \n\n";
    }
    else cout << " Down Inaccessible \n\n";
    if(positionY-1>=0&&board[positionX][positionY-1]->getType()!=2){
        cout << " 3. Move Left \t\t\t\t\t";
    }
    else cout << " Left Inaccessible \t\t\t\t";
    if(positionY+1<gridRows&&board[positionX][positionY+1]->getType()!=2){
        cout << " 4. Move Right \n\n";
    }
    else cout << " Right Inaccessible \n\n";
    cout << " 5. Check Inventory \t\t\t\t";
    cout << " 6. Display Stats \n\n";
    cout << " 7. Display Map \t\t\t\t";
    cout << " 8. Quit Game \n\n";
}

bool Grid::check_option(int option){
    if (option==5||option==6||option==7||option==8) return true;
    else if(option==1){
        if(positionX-1>=0&&board[positionX-1][positionY]->getType()!=2) return true;
    }
    else if(option==2){
        if (positionX+1<gridColumns&&board[positionX+1][positionY]->getType()!=2) return true;
    }
    else if(option==3){
        if (positionY-1>=0&&board[positionX][positionY-1]->getType()!=2) return true;
    }
    else if(option==4){
        if(positionY+1<gridRows&&board[positionX][positionY+1]->getType()!=2) return true;
    }
    return false;
}

void Grid::checkInventory() {
    board[positionX][positionY]->checkInventory();
}

void Grid::displayStats() {
    board[positionX][positionY]->displayStats();
}

//  HERO MOVEMENTS

void Grid::move(int where_i_go){
    if(where_i_go == 1) { //Move Up
        for (int i=0;i<heroes;i++) board[positionX-1][positionY]->place(board[positionX][positionY]->exit());
        board[positionX-1][positionY]->setHeroesPresent(true);
        board[positionX][positionY]->setHeroesPresent(false);
        positionX=positionX-1;
    }
    else if(where_i_go == 2) { //Move Down
        for (int i=0;i<heroes;i++) board[positionX+1][positionY]->place(board[positionX][positionY]->exit());
        board[positionX+1][positionY]->setHeroesPresent(true);
        board[positionX][positionY]->setHeroesPresent(false);
        positionX=positionX+1;
    }
    else if(where_i_go == 3) { //Move Left
        for (int i=0;i<heroes;i++) board[positionX][positionY-1]->place(board[positionX][positionY]->exit());
        board[positionX][positionY-1]->setHeroesPresent(true);
        board[positionX][positionY]->setHeroesPresent(false);
        positionY=positionY-1;
    }
    else if(where_i_go == 4) { //Move Right
        for (int i=0;i<heroes;i++) board[positionX][positionY+1]->place(board[positionX][positionY]->exit());
        board[positionX][positionY+1]->setHeroesPresent(true);
        board[positionX][positionY]->setHeroesPresent(false);
        positionY=positionY+1;
    }
}

bool Grid::inside_a_market(){
    if (board[positionX][positionY]->getType()==3) return true;
    return false;
}

void Square::place(Hero* hero){
    heroes_here.push_back(hero);
}

int Square::average_level() {
    int sum=0;
    for (int i=0;i<heroes_here.size();i++) {
        sum=sum+heroes_here.at(i)->getLevel();
    }
    sum=sum/heroes_here.size();
    if (sum>10) sum=10; //to pick the maximum level of monster 9 or 10
    return sum;
}

Hero* Square::exit(){
    Hero* temp=heroes_here.back();
    heroes_here.pop_back();
    return temp;
}

Square::Square(int type) {
    this->type=type;
    this->heroes_present=false;
}

void Square::setHeroesPresent(bool heroesPresent) {
    heroes_present = heroesPresent;
}

void Square::checkInventory() {
    cout<<endl;
    for(int i=0; i< heroes_here.size();i++){
        heroes_here.at(i)->checkInventory();
    }
}

void Square::displayStats() {
    cout << "\nHero Stats: \n";
    for(int i=0; i< heroes_here.size();i++){
        heroes_here.at(i)->displayStats();
    }
    string press;
    cout<< "\nType anything to go back.\n\n> ";
    cin>>press;
}

bool Square::isHeroesPresent() const {
    return heroes_present;
}

// BATTLE - functions

void Grid::battle(){
    srand(time(NULL));
    int monster_count = rand()%heroes+1;
    monsterList monster_team;
    for (int i=0; i<monster_count;i++){
        int pick_a_monster;
        do {
            pick_a_monster = rand()%25;
        }while (monsters[pick_a_monster]->getLevel()!=board[positionX][positionY]->average_level()&&(monsters[pick_a_monster]->getLevel()+1)!=board[positionX][positionY]->average_level());
        monster_team.add(new Monster(*monsters[pick_a_monster]));
    }
    board[positionX][positionY]->battle(monster_team);
}

void Square::battle(monsterList& teamMonster) {
    int initial_monster_size=teamMonster.size();
    if (teamMonster.size()==1) cout << "\nA Monster Appeared! \n\n";
    else cout << "\n"<< teamMonster.size() <<" Monsters Appeared! \n\n";
    for (int i=0;i<teamMonster.size();i++) {
      cout<< " " << teamMonster.at(i)->getName() << "\n Level: " << teamMonster.at(i)->getLevel() << "\n Type: " << teamMonster.at(i)->getType() <<endl<<endl;
    }
    int round=1;
    bool winner=false;
    while (!winner) {
        teamMonster.checkEnchantments();
        cout << "Round " << round << "! \n";
        for (int i = 0; i < heroes_here.size(); i++) { //Heroes' turn
            if (heroes_here.at(i)->getHealthPower() != 0) {
                GoBack:
                cout << endl << heroes_here.at(i)->getName() << ", ";
                int course_of_action = this->battle_options();
                if (course_of_action == 4) {
                    cout << "\nMonster Stats: \n";
                    for (int j = 0; j < teamMonster.size(); j++) {
                        teamMonster.at(j)->displayStats();
                    }
                    this->displayStats(); //Hero stats
                    goto GoBack; //Initial menu
                } else if (course_of_action == 3) {
                    if (!heroes_here.at(i)->checkInventory())
                        goto GoBack; //The hero didn't use this turn to change gear or use a potion
                } 
                else if (course_of_action == 2) {
                    int how_many_spells = heroes_here.at(i)->spell_check();
                    if (how_many_spells == 0) {
                        cout << " You don't have any spells that you can use currently! \n\n";
                        goto GoBack; //Initial menu
                    }
                    else {
                        int decision4;
                        if (teamMonster.size() > 1) {
                            do {
                                cout << "Cast a spell on which monster? \n ";
                                for (int jj = 0; jj < teamMonster.size(); jj++) {
                                    cout << "\n "<< jj+1<<". ";
                                    teamMonster.at(jj)->displayStats();
                                }
                                cout << "\n\n> ";
                                cin >> decision4;
                                cout << endl;
                                if (!cin) { // user didn't input a number
                                    cin.clear(); // reset failbit
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                }
                            } while (decision4 > teamMonster.size() || decision4 < 1);
                        }
                        else decision4 = 1;
                        teamMonster.subdue(decision4 - 1, teamMonster.at(decision4 - 1)->defendFrom(heroes_here.at(i)->castSpell(how_many_spells)));
                        if (teamMonster.at(decision4 - 1)->getHealthPower() <= 0) {
                            cout << teamMonster.at(decision4 - 1)->getName() << " has been defeated!\n\n";
                            teamMonster.vanish(decision4 - 1);
                            if (heroesWin(teamMonster.size(),initial_monster_size)) goto endgame;
                        }
                    }
                } 
                else if (course_of_action == 1) {
                    int decision6;
                    if (teamMonster.size() > 1) {
                        do {
                            cout << "Attack which monster? \n ";
                            for (int jj = 0; jj < teamMonster.size(); jj++) {
                                cout << "\n "<< jj+1 <<". ";
                                teamMonster.at(jj)->displayStats();
                            }
                            cout << "\n\n> ";
                            cin >> decision6;
                            cout << endl;
                            if (!cin) { // user didn't input a number
                                cin.clear(); // reset failbit
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                        } while (decision6 > teamMonster.size() || decision6 < 1);
                    }
                    else decision6 = 1;
                    if (!teamMonster.at(decision6 - 1)->defendFrom(heroes_here.at(i)->attack())) {
                        cout << teamMonster.at(decision6 - 1)->getName() << " has been defeated!\n\n";
                        teamMonster.vanish(decision6 - 1);
                        if (heroesWin(teamMonster.size(), initial_monster_size)) goto endgame;
                    }
                }
            }
        }
        for (int i = 0; i < teamMonster.size(); i++) { // Monsters' turn
            srand(time(NULL));
            int pick;
            do{
                pick=rand()%heroes_here.size();
            }while(heroes_here.at(pick)->getHealthPower()==0);
            if (!(heroes_here.at(pick)->defend(teamMonster.at(i)->attack()))){
                cout << endl << heroes_here.at(pick)->getName() << " has been defeated! \n";
            }
            if (this->monstersWin()) goto endgame;
        }
        winner = heroesWin(teamMonster.size(), initial_monster_size);
        for (int i = 0; i < heroes_here.size(); i++) {
            if (heroes_here.at(i)->getHealthPower() != 0) { //If this hero is not unconscious
                heroes_here.at(i)->rejuvenate(); // Rejuvenate's a part of the health & magic power
            }
        }
        for (int i = 0; i < teamMonster.size(); i++) teamMonster.at(i)->rejuvenate(); // Rejuvenate a part of the monsters health
        round++;
    }
    endgame:
    for (int i=0;i<heroes_here.size();i++) heroes_here.at(i)->resurrect(); // Revive the dead's health to half
}

bool Square::heroesWin(int size,int initial_monster_size){
    if (size == 0) {
        cout << "\nYou have won the battle! \n";
        for (int i=0;i<heroes_here.size();i++) {
            heroes_here.at(i)->reward(initial_monster_size);
        }
        return true;
    }
    return false;
}

bool Square::monstersWin(){
    int muertos=0;
    for (int i=0; i< heroes_here.size();i++){
        if (heroes_here.at(i)->getHealthPower() == 0) muertos++;
    }
    if (heroes_here.size()==muertos) {
        cout << "\nYou have been defeated! \n";
        for (int i=0;i<heroes_here.size();i++) {
            cout<< endl << heroes_here.at(i)->getName() << " you lost half of your money!\n";
            double split = int(heroes_here.at(i)->getMoney()/2)+0.5;
            heroes_here.at(i)->setMoney(split);
        }
        return true;
    }
    return false;
}

int Square::battle_options() {
    int course_of_action;
    do{
        cout << "What would you like to do?" << endl<<endl;
        cout << " 1. Attack \t\t\t";
        cout << " 2. Cast a Spell \n\n";
        cout << " 3. Check Inventory \t\t";
        cout << " 4. Display Stats \n\n";
        cout << "\n> ";
        cin >> course_of_action;
        if(!cin){ // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (course_of_action!=1&&course_of_action!=2&&course_of_action!=3&&course_of_action!=4); //user didn't input 1,2, 3 or 4
    return course_of_action;
}


//GAME ECONOMY - MARKET functions

string Square::getMarketName() {
    return "virtual "; //using the market one
}

int Square::market_options() {
    cout <<"virtual function, just passing through\n"; //using the market one
    return 0;
}

void Grid::shopping_time(){
    board[positionX][positionY]->shopping_time();
}

void Square::shopping_time(){
    cout<< "\n\nWelcome to "<< getMarketName() <<"!\n\n";
    for(int i=0; i<heroes_here.size();i++) {
        cout << heroes_here.at(i)->getName() << ", ";
        int decide;
        do {
            beginning:
            cout << "Would you be interested in?\n\n";
            cout << " 1. Buying \t\t\t\t\t 2. Selling \n\n";
            cout << " 3. Exit the Market \n\n";
            cout << "\n> ";
            cin >> decide;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (decide != 1 && decide != 2 && decide != 3); //user didn't input 1,2 or 3
        if (decide == 1) {
            cout << "What would you like to buy "<<heroes_here.at(i)->getName()<< "?" << endl << endl;
            this->display_stock(this->market_options(), heroes_here.at(i));
            goto beginning;
        }
        else if (decide == 2) {
            if(heroes_here.at(i)->have_summat_to_sell()) {
                cout << "What would you like to sell "<<heroes_here.at(i)->getName()<< "?" << endl << endl;
                heroes_here.at(i)->selling_options();
                goto beginning;
            }
            else {
                cout << "\nIt seems you have nothing to sell!\n\n";
                goto beginning;
            }
        }
        else {
            cout << "We hope to see you again!"<<endl<<endl;
        }
    }
}

void market::display_stock(int option, Hero* customer) { //Display the available items of the selected kind
    int decide=1, decide2=1;
    if (option==1) {
        bool options[6]={false, false, false, false, false, false};
            int countnull=0;
            cout << "\nLet me check the warehouse...\n\n Here's our wonderful selection of weapons: \n\n";
            for (int i=0;i<6;i++){
                if (this->weapons_storage[i][0]!=NULL) {
                    cout << i+1 <<".";
                    weapons_storage[i][0]->print();
                    cout <<endl;
                    options[i]=true;
                }
                else countnull++;
            }
            if (countnull==6) {
                cout << " I'm afraid we're out of weapons!\n";
            }
            else {
                cout << "Which of these beauties would you like to purchase? (or type anything else to go back)\n";
                cout << "\n> ";
                cin >> decide;
                if (!cin) { // user didn't input a number
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else if (decide < 7 && options[decide - 1] == true) {
                    if (customer->getMoney() > weapons_storage[decide - 1][0]->getPrice()) {
                        cout << "\nAre you sure you want to purchase: " << weapons_storage[decide - 1][0]->getName()
                             << "?\n";
                        cout << "\n 1. Yes \t\t\t\t\t 2. No\n";
                        cout << "\n> ";
                        cin >> decide2;
                        if (!cin) { // user didn't input a number
                            cin.clear(); // reset failbit
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        } 
                        else if (decide2 == 1) {
                            int finder = 1;
                            while ((weapons_storage[decide - 1][finder] != NULL)&&(finder<7)) {
                                finder++;
                            }
                            customer->buy(weapons_storage[decide - 1][finder - 1]);
                            weapons_storage[decide - 1][finder - 1] = NULL;
                        }
                    } else cout << "\n It seems you don't have enough funds to purchase this!\n";
                }
            }
    }
    else if (option==2) {
        bool options[4]={false, false, false, false};
        int countnull=0;
        cout << "\nLet me check the warehouse...\n\n Here's our wonderful selection of armours: \n\n";
        for (int i=0;i<4;i++){
            if (this->armours_storage[i][0]!=NULL) {
                cout << i+1 <<".";
                armours_storage[i][0]->print();
                cout <<endl;
                options[i]=true;
            }
            else countnull++;
        }
        if (countnull==4) {
            cout << " I'm afraid we're out of armours!\n";
        }
        else {
            cout << "Which one of these lovely armours would you like to purchase? (or type anything else to go back)\n";
            cout << "\n> ";
            cin >> decide;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } 
            else if (decide < 5 && options[decide - 1] == true) {
                if (customer->getMoney() > armours_storage[decide - 1][0]->getPrice()) {
                    cout << "\nAre you sure you want to purchase: " << armours_storage[decide - 1][0]->getName()
                         << "?\n";
                    cout << "\n 1. Yes \t\t\t\t\t 2. No\n";
                    cout << "\n> ";
                    cin >> decide2;
                    if (!cin) { // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if (decide2 == 1) {
                        int finder = 1;
                        while ((armours_storage[decide - 1][finder] != NULL) && (finder<4)) {
                            finder++;
                        }
                        customer->buy(armours_storage[decide - 1][finder - 1]);
                        armours_storage[decide - 1][finder - 1] = NULL;
                    }
                } else cout << "\n It seems you don't have enough funds to purchase this!\n";
            }
        }
    }
    else if (option==3) {
        bool options[12]={false, false, false, false, false, false, false, false, false, false, false, false};
        int countnull=0;
        cout << "\nLet me check the warehouse...\n\n Here's our wonderful selection of potions: \n\n";
        for (int i=0;i<12;i++){
            if (this->potions_storage[i][0]!=NULL) {
                cout << i+1 <<".";
                potions_storage[i][0]->print();
                cout <<endl;
                options[i]=true;
            }
            else countnull++;
        }
        if (countnull==12) {
            cout << " I'm afraid we're out of potions!\n";
        }
        else {
            cout<< "Which one of these Feruchemical Potions would you like to purchase? (or type anything else to go back)\n";
            cout << "\n> ";
            cin >> decide;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (decide < 13 && options[decide - 1] == true) {
                if (customer->getMoney() > potions_storage[decide - 1][0]->getPrice()) {
                    cout << "\nAre you sure you want to purchase: " << potions_storage[decide - 1][0]->getName()
                         << "?\n";
                    cout << "\n 1. Yes \t\t\t\t\t 2. No\n";
                    cout << "\n> ";
                    cin >> decide2;
                    if (!cin) { // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else if (decide2 == 1) {
                        int finder = 1;
                        while ((potions_storage[decide - 1][finder] != NULL)&&(finder<20)) {
                            finder++;
                        }
                        customer->buy(potions_storage[decide - 1][finder - 1]);
                        potions_storage[decide - 1][finder - 1] = NULL;
                    }
                }
                else cout << "\n It seems you don't have enough funds to purchase this!\n";
            }
        }
    }
    else if (option==4) {
        bool options[9]={false, false, false, false, false, false, false, false, false};
        int countnull=0;
        cout << "\nLet me check the warehouse...\n\n Here's our wonderful selection of spells: \n\n";
        for (int i=0;i<9;i++){
            if (this->spells_storage[i][0]!=NULL) {
                cout << i+1 <<".";
                spells_storage[i][0]->print();
                cout <<endl;
                options[i]=true;
            }
            else countnull++;
        }
        if (countnull==9) {
            cout << " I'm afraid we're out of spells!\n";
        }
        else {
            cout << "Which of these Allomantic Spells would you like to purchase? (or type anything else to go back)\n";
            cout << "\n> ";
            cin >> decide;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (decide < 10 && options[decide - 1] == true) {
                if (customer->getMoney() > spells_storage[decide - 1][0]->getPrice()) {
                    cout << "\nAre you sure you want to purchase: " << spells_storage[decide - 1][0]->getName()
                         << "?\n";
                    cout << "\n 1. Yes \t\t\t\t\t 2. No\n";
                    cout << "\n> ";
                    cin >> decide2;
                    if (!cin) { // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else if (decide2 == 1) {
                        int finder = 1;
                        while ((spells_storage[decide - 1][finder] != NULL)&&(finder<16)) {
                            finder++;
                        }
                        customer->buy(spells_storage[decide - 1][finder - 1]);
                        spells_storage[decide - 1][finder - 1] = NULL;
                    }
                } else cout << "\n It seems you don't have enough funds to purchase this!\n";
            }
        }
    }
    cout<<endl;
}

int market::market_options() {
    int course_of_action;
    do{
        cout << " 1. Weapons \t\t\t\t";
        cout << " 2. Armours \n\n";
        cout << " 3. Feruchemical Potions \t\t";
        cout << " 4. Allomantic Spells \n\n";
        cout << "\n> ";
        cin >> course_of_action;
        if(!cin){ // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (course_of_action!=1&&course_of_action!=2&&course_of_action!=3&&course_of_action!=4); //user didn't input 1,2 or 3
    return course_of_action;
}

string market::getMarketName() {
    return market_name;
}

market::market(Weapon* weapons[], Armor* armours[], Potion* potions[], Spell* spells[], int type, const string& name){
    this->type=type;
    this->heroes_present=false;
    this->market_name=name;
    for (int i=0; i<6;i++){
        for (int j=0;j<7;j++) { //The initial stock will have 7 of each weapon
            weapons_storage[i][j] = new Weapon(*weapons[i]);
        }
    }
    for (int i=0; i<4;i++){
        for (int j=0;j<4;j++) { //The initial stock will have 4 of each armour
            armours_storage[i][j] = new Armor(*armours[i]);
        }
    }
    for (int i=0; i<12;i++){
        for (int j=0;j<20;j++) { //The initial stock will have 20 of each potion
            potions_storage[i][j]=new Potion(*potions[i]);
        }
    }
    for (int i=0; i<9;i++){
        for (int j=0;j<16;j++) { //The initial stock will have 16 of each spell
            spells_storage[i][j]=new Spell(*spells[i]);
        }
    }
}

void market::restock(Weapon* weapons[], Armor* armours[], Potion* potions[], Spell* spells[]){
    for (int i=0; i<6;i++) { //The market will be supplied till the warehouse is full of each item
        for (int j = 0; j < 7; j++) {
            if (weapons_storage[i][j]==NULL) {
                weapons_storage[i][j] = new Weapon(*weapons[i]);
            }
        }
    }
    for (int i=0; i<4;i++){
        for (int j=0;j<4;j++) {
            if (armours_storage[i][j]==NULL) {
                armours_storage[i][j] = new Armor(*armours[i]);
            }
        }
    }
    for (int i=0; i<12;i++){
        for (int j=0;j<20;j++) {
            if (potions_storage[i][j]==NULL) {
                potions_storage[i][j] = new Potion(*potions[i]);
            }
        }
    }
    for (int i=0; i<9;i++){
        for (int j=0;j<16;j++) {
            if (spells_storage[i][j]==NULL) {
                spells_storage[i][j] = new Spell(*spells[i]);
            }
        }
    }
}

void Square::restock(Weapon* w[], Armor* a[], Potion* p[], Spell* s[]) {
    cout<< "I'm a virtual function that isn't used\n";
}

void Square::display_stock(int jj, Hero* heroas) {
    cout<< "I'm a virtual function that isn't used\n";
}

void Grid::restock() { //RESTOCKING THE MARKETS
    board[0][10]->restock(weapons, armours, potions, spells);
    board[6][16]->restock(weapons, armours, potions, spells);
    board[9][9]->restock(weapons, armours, potions, spells);
    board[15][3]->restock(weapons, armours, potions, spells);
    board[17][18]->restock(weapons, armours, potions, spells);
}