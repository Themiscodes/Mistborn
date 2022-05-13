#include "grid.h"
#include "characters.h"

//LIVING MUTATORS ACCESSORS
const string &Living::getName() const {
    return name;
}
unsigned int Living::getLevel() const {
    return level;
}
const string &Living::getType() const {
    return type;
}
double Living::getHealthPower() const {
    return healthPower;
}
void Living::setHealthPower(double hP) {
    Living::healthPower = hP;
}
void Living::setMaxPower(double mP) {
    Living::maxPower = mP;
}

//HERO FUNCTIONS
void Hero::inventory(){
    if (!my_weapons.empty()) {
        cout << type << " " << name << ", you have the following Weapons: \n";
        for (int i = 0; i < my_weapons.size(); i++) my_weapons.at(i)->print();
    }
    else {
        cout << type << " " << name << ", you have no Weapons. \n";
    }
    if (!my_armours.empty()) {
        cout << "\nThe following Armours: \n";
        for (int i = 0; i < my_armours.size(); i++) my_armours.at(i)->print();
    }
    else {
        cout << "\nYou have no Armours. \n";
    }
    if (!my_potions.empty()) {
        cout << "\nThe following Potions: \n";
        for (int i = 0; i < my_potions.size(); i++) my_potions.at(i)->print();
    }
    else {
        cout << "\nYou have no Potions. \n";
    }
    if (!my_spells.empty()) {
        cout << "\nThe following Spells: \n";
        for (int i = 0; i < my_spells.size(); i++) my_spells.at(i)->print();
    }
    else {
        cout << "\nYou have no Spells. \n";
    }
}

bool Hero::checkInventory() {
    unsigned int decision, decision2, decision3;
    cout <<endl;
    this->inventory();
    cout << "\nWould you like to: \n\n 1. Equip with a Weapon \t\t 2. Equip with an Armour \n\n 3. Use a Potion \t\t\t 4. Return Back \n\n";
    cout << "\n> ";
    cin >> decision;
    if (!cin) { // user didn't input an unsigned integer number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (decision==2) {
        if (my_armours.empty()){
            cout << "\n You have no armours currently! \n";
        }
        else {
            cout << "\n Which one would you like to equip? \n\n";
            for (int i = 0; i < my_armours.size(); i++) {
                cout << i + 1 << ".";
                my_armours.at(i)->print();
                cout << endl;
            }
            cout << "\n> ";
            cin >> decision;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision < my_armours.size() + 1) && (decision > 0)) {
                if (my_armours.at(decision - 1)->isInUse()) cout << "You're already wearing it!\n";
                else if (my_armours.at(decision-1)->getExperienceLevel()>this->getLevel()) cout << "You haven't reached the required Level yet to wear this Armour!\n";
                else {
                    my_armours.at(decision - 1)->equip();
                    for (int i = 0; i < my_armours.size(); i++) { //check if they were wearing another armor to take off
                        if (i != decision - 1) my_armours.at(i)->remove();
                    }
                    cout << my_armours.at(decision - 1)->getName() << " was equipped!\n\n";
                    return true;
                }
            }
        }
    }
    else if (decision==1){
        if (my_weapons.empty()){
            cout << "\n You have no weapons currently! \n";
        }
        else {
            cout << "\n Which one would you like to equip? \n\n";
            for (int i = 0; i < my_weapons.size(); i++) {
                cout << i + 1 << ".";
                my_weapons.at(i)->print();
                cout << endl;
            }
            cout << "\n> ";
            cin >> decision;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision < my_weapons.size()+1) && (decision > 0)) {
                if (my_weapons.at(decision - 1)->isInUse()) cout << "You're already holding this!\n";
                else if (my_weapons.at(decision-1)->getExperienceLevel()>this->getLevel()) cout << "You haven't reached the required Level yet to carry this Weapon!\n";
                else {
                    if (my_weapons.at(decision - 1)->isTwoHandedWield()) {
                        my_weapons.at(decision - 1)->equip();
                        for (int i = 0;
                             i < my_weapons.size(); i++) { //check if they were holding other weapons & remove them
                            if (i != decision - 1) my_weapons.at(i)->remove();
                        }
                        cout << my_weapons.at(decision - 1)->getName() << " was equipped!\n\n";
                        return true;
                    }
                    else {
                        int count=0;
                        for (int i = 0; i < my_weapons.size(); i++) { //check if they are holding other weapons
                            if ((i != decision - 1) && (my_weapons.at(i)->isInUse())) count++;
                        }
                        if (count == 2) {
                            int l = 1;
                            cout << "\n It seems you have two One-Handed Weapons already on each hand. \n Which one of them would you like to replace? \n\n";
                            for (int i = 0; i < my_weapons.size(); i++) { //check if they are holding other weapons
                                if ((i != decision - 1) && (my_weapons.at(i)->isInUse())) {
                                    cout <<" "<< l << ". " << my_weapons.at(i)->getName() << "\t\t";
                                    l++;
                                }
                            }
                            cout << "\n\n 3. None";
                            cout << "\n\n> ";
                            cin >> decision2;
                            cout << endl;
                            if (!cin) { // user didn't input a number
                                cin.clear(); // reset failbit
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            else if (decision2 == 1) {
                                for (int i = 0; i < my_weapons.size(); i++) { //find the first weapon to replace
                                    if (my_weapons.at(i)->isInUse()) {
                                        my_weapons.at(i)->remove();
                                        cout << endl << my_weapons.at(i)->getName() << " replaced with ";
                                        my_weapons.at(decision - 1)->equip();
                                        cout << my_weapons.at(decision - 1)->getName() << "!\n\n";
                                        return true;
                                    }
                                }
                            } else if (decision2 == 2) {
                                for (int i = 0; i < my_weapons.size(); i++) { //find the second weapon instead
                                    if (my_weapons.at(i)->isInUse()) {
                                        i++;
                                        while (!(my_weapons.at(i)->isInUse())) i++;
                                        my_weapons.at(i)->remove();
                                        cout << endl << my_weapons.at(i)->getName() << " replaced with ";
                                        my_weapons.at(decision - 1)->equip();
                                        cout << my_weapons.at(decision - 1)->getName() << "!\n\n";
                                        return true;
                                    }
                                }
                            } else {
                                cout << endl;
                                return false;
                            }
                        }
                        else if (count == 1) {
                            for (int i = 0; i < my_weapons.size(); i++) { //check if the other weapon they hold is one handed too
                                if ((i != decision - 1) && (my_weapons.at(i)->isInUse()) && (my_weapons.at(i)->isTwoHandedWield())) {
                                   my_weapons.at(i)->remove();
                                   cout << endl << my_weapons.at(i)->getName() << " replaced with ";
                                   my_weapons.at(decision - 1)->equip();
                                   cout << my_weapons.at(decision - 1)->getName() << "!\n\n";
                                   return true;
                                }
                            }
                            my_weapons.at(decision - 1)->equip();
                            cout << my_weapons.at(decision - 1)->getName() << " was equipped!\n\n";
                            return true;
                        }
                        else if (count == 0) {
                            my_weapons.at(decision - 1)->equip();
                            cout << my_weapons.at(decision - 1)->getName() << " was equipped!\n\n";
                            return true;
                        }
                    }
                }
            }
        }
    }
    else if(decision==3){
        if (my_potions.empty()){
            cout << "\n You have no Potions currently! \n";
        }
        else {
            for (int i = 0; i < my_potions.size(); i++) { //Check if they've already consumed another potion
                if (my_potions.at(i)->isInUse()) {
                    cout << "It seems you're already burning a Feruchemical Potion inside you!\n";
                    return false; //since they can't spit it out (they can't change a potion like an armour)
                }
            }
            cout << "\n Which one would you like to use? \n\n";
            for (int i = 0; i<my_potions.size(); i++) {
                cout << i + 1 << ".";
                my_potions.at(i)->print();
                cout << endl;
            }
            cout << "\n> ";
            cin >> decision;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision < my_potions.size() + 1) && (decision > 0)) {
                if (my_potions.at(decision-1)->getExperienceLevel()>this->getLevel()) cout << "You haven't reached the required Level yet to use this Potion!\n";
                else {
                    if (my_potions.at(decision-1)->getAttributeImprovement()=="Health"){
                        if (healthPower < maxPower) {
                            cout << " You ingested " << my_potions.at(decision-1)->getName() << "! \n\n";
                            int increment = int (healthPower+(maxPower*(my_potions.at(decision-1)->getIncrement())/100));
                            this->setHealthPower(increment);
                            if (healthPower> maxPower) healthPower =maxPower;
                            cout << " Your health has increased to " << healthPower<< "!\n\n";
                            vector<Potion*>::iterator it1; //and then removing it
                            it1=my_potions.begin();
                            it1+=(decision-1);
                            my_potions.erase(it1);
                            return true;
                        }
                        else {
                            cout << "\n You already have full Health!\n";
                            return false;
                        }
                    }
                    else {
                        my_potions.at(decision - 1)->equip();
                        cout << " You ingested " << my_potions.at(decision - 1)->getName() << "! \n\n";
                        cout << " On your next battle this metal will burn inside you \n";
                        cout << " to unleash it's Feruchemical properties \n and enhance your ";
                        cout << my_potions.at(decision - 1)->getAttributeImprovement() << " by ";
                        cout << my_potions.at(decision - 1)->getIncrement() << " times for one round!\n\n";
                        return true;
                    }
                }
            }
        }
    }
    cout<<endl;
    return false;// return true if he switches a weapon, armor or potion so their round is over in a battle
}

int Hero::healthPotionAvail() {
    int count=0;
    for (int l=0;l<my_potions.size();l++){
        if (my_potions.at(l)->getAttributeImprovement()=="Health") {
            count++;
        }
    }
    return count;
}

void Monster::displayStats(){
    cout <<"\n " << name << "\n Level: " << level << " " << type ;
    cout << "\n Current HP: " << healthPower << "\n Maximum HP: " << maxPower;
    cout << "\n Damage: " << damage << " \n Defence: " <<defence << " \n Dodge Probability: " <<dodge_probability*100 << "%\n";
}

void Hero::displayStats(){
    cout <<"\n " << name << "\n Level: " << level << " " << type ;
    cout << "\n XP: " << experience << " (+" << (10*level*level-experience)<<" to LVL up)";
    cout << "\n HP: " << healthPower << "  maxHP: " << maxPower;
    cout << "\n MP: " << magicPower << "  maxMP: " << magicMaxPower;
    cout << "\n Strength: " << strength << " \n Dexterity: " <<dexterity << " \n Agility: " <<agility;
    cout  << "\n Money: " << money << "$ \n";
}

void Hero::buy(Weapon* weapon) {
    int decision;
    this->money=money-weapon->getPrice();
    cout << endl<< weapon->getName();
    this->acquire(weapon);
    cout << " acquired!\n\n Would you like to Check your Inventory to Equip it?\n\n";
    cout << " 1. Yes \t\t\t\t\t 2. No\n";
    cout << "\n> ";
    cin >> decision;
    if (!cin) { // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (decision==1) checkInventory();
}

void Hero::buy(Armor* armour) {
    int decision;
    this->money=money-armour->getPrice();
    cout << endl<< armour->getName();
    this->acquire(armour);
    cout << " acquired!\n\n Would you like to Check your Inventory to Equip it?\n\n";
    cout << " 1. Yes \t\t\t\t\t 2. No\n";
    cout << "\n> ";
    cin >> decision;
    if (!cin) { // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (decision==1) checkInventory();
}
void Hero::buy(Potion* potion) {
    int decision;
    this->money= money - potion->getPrice();
    cout << endl << potion->getName();
    this->acquire(potion);
    cout << " acquired!\n\n Would you like to Check your Inventory to Use it?\n\n";
    cout << " 1. Yes \t\t\t\t\t 2. No\n";
    cout << "\n> ";
    cin >> decision;
    if (!cin) { // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (decision==1) checkInventory();
}

void Hero::buy(Spell* spell) {
    this->money = money - spell->getPrice();
    cout << endl << spell->getName();
    this->acquire(spell);
    cout << " acquired!\n\n";
}

void Hero::acquire(Weapon* weapon) {
    my_weapons.push_back(weapon);
}

void Hero::acquire(Armor* armour) {
    my_armours.push_back(armour);
}

void Hero::acquire(Potion* potion) {
    my_potions.push_back(potion);
}

void Hero::acquire(Spell* spell) {
    my_spells.push_back(spell);
}

double Hero::getMoney() const {
    return money;
}

bool Hero::have_summat_to_sell() {
    if ((this->my_armours.empty())&&this->my_potions.empty()&&this->my_spells.empty()&&this->my_weapons.empty()) return false;
    else {
        if (!this->my_potions.empty()){
            int counter=0;
            for (int i=0; i<this->my_potions.size();i++){
                if (this->my_potions.at(i)->isInUse()) counter++;
            }
            if (counter>1) return true;
            else {
                if (this->my_armours.empty()&&this->my_spells.empty()&&this->my_weapons.empty()) return false;
                else return true;
            }
        }
    }
    return true;
}

void Hero::selling_options(){
    int decision, decision2;
    inventory();
    cout << "\nWould you like to: \n\n 1. Sell one of your Weapons \t\t 2. Sell one of your Armours \n\n 3. Sell one of your Potions \t\t 4. Sell One of your Spells \n\n";
    cout << " 5. Type anything else if you finally don't want to sell \n\n";
    cout << "\n> ";
    cin >> decision;
    if (!cin) { // user didn't input an unsigned integer number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (decision==1) {
        if (my_weapons.empty()) cout << "\n You don't have any Weapons for sale! \n\n";
        else {
            cout << "\n Which one would you like to sell? \n\n";
            for (int i = 0; i < my_weapons.size(); i++) {
                cout << i + 1 << ".";
                my_weapons.at(i)->print();
                cout << " Can be sold at a price of: " << (my_weapons.at(i)->getPrice()/2) << "$.\n";
                cout << endl;
            }
            cout << my_weapons.size()+1 <<". Type anything else if you finally don't want to sell \n\n";
            cout << "\n> ";
            cin >> decision2;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision2<my_weapons.size()+1)&&decision2>0){
                cout << "\n " << my_weapons.at(decision2-1)->getName();
                double cashmoney = 0;
                cashmoney = money + ((my_weapons.at(decision2-1)->getPrice())/2);
                if (cashmoney>money) money =cashmoney;
                vector<Weapon*>::iterator it1;
                it1= my_weapons.begin();
                it1=it1+decision2-1;
                delete my_weapons.at(decision2-1);
                my_weapons.erase(it1);
                cout << " has been succesfuly sold! \n\n";
                cout << " Your new balance is: " << money << "$\n\n";
            }
        }
    }
    else if (decision==2) {
        if (my_armours.empty()) cout << "\n You don't have any Armours for sale! \n\n";
        else {
            cout << "\n Which one would you like to sell? \n\n";
            for (int i = 0; i < my_armours.size(); i++) {
                cout << i + 1 << ".";
                my_armours.at(i)->print();
                cout << " Can be sold at a price of: " << (my_armours.at(i)->getPrice()/2) << "$.\n";
                cout << endl;
            }
            cout << my_armours.size()+1 <<". Type anything else if you finally don't want to sell \n\n";
            cout << "\n> ";
            cin >> decision2;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision2<my_armours.size()+1)&&decision2>0){
                cout << "\n " << my_armours.at(decision2-1)->getName();
                double cashmoney = 0;
                cashmoney = money + ((my_armours.at(decision2-1)->getPrice())/2);
                if (cashmoney>money) money =cashmoney;
                vector<Armor*>::iterator it1;
                it1= my_armours.begin();
                it1=it1+decision2-1;
                delete my_armours.at(decision2-1);
                my_armours.erase(it1);
                cout << " has been succesfuly sold! \n\n";
                cout << " Your new balance is: " << money << "$\n\n";
            }
        }
    }
    else if (decision==3) {
        if (my_potions.empty()) cout << "\n You don't have any Potions for sale! \n\n";
        else {
            cout << "\n Which one would you like to sell? \n\n";
            for (int i = 0; i < my_potions.size(); i++) {
                cout << i + 1 << ".";
                my_potions.at(i)->print();
                cout << " Can be sold at a price of: " << (my_potions.at(i)->getPrice()/2) << "$.\n";
                cout << endl;
            }
            cout << my_potions.size()+1 <<". Type anything else if you finally don't want to sell \n\n";
            cout << "\n> ";
            cin >> decision2;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision2<my_potions.size()+1)&&decision2>0){
                cout << "\n " << my_potions.at(decision2-1)->getName();
                double cashmoney = 0;
                cashmoney = money + ((my_potions.at(decision2-1)->getPrice())/2);
                if (cashmoney>money) money =cashmoney;
                vector<Potion*>::iterator it1;
                it1= my_potions.begin();
                it1=it1+decision2-1;
                delete my_potions.at(decision2-1);
                my_potions.erase(it1);
                cout << " has been succesfuly sold! \n\n";
                cout << " Your new balance is: " << money << "$\n\n";
            }
        }
    }
    else if (decision==4) {
        if (my_spells.empty()) cout << "\n You don't have any Potions for sale! \n\n";
        else {
            cout << "\n Which one would you like to sell? \n\n";
            for (int i = 0; i < my_spells.size(); i++) {
                cout << i + 1 << ".";
                my_spells.at(i)->print();
                cout << " Can be sold at a price of: " << (my_spells.at(i)->getPrice()/2) << "$.\n";
                cout << endl;
            }
            cout << my_spells.size()+1 <<". Type anything else if you finally don't want to sell \n\n";
            cout << "\n> ";
            cin >> decision2;
            cout << endl;
            if (!cin) { // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if ((decision2<my_spells.size()+1)&&decision2>0){
                cout << "\n " << my_spells.at(decision2-1)->getName();
                double cashmoney = 0;
                cashmoney = money + ((my_spells.at(decision2-1)->getPrice())/2);
                if (cashmoney>money) money =cashmoney;
                vector<Spell*>::iterator it1;
                it1= my_spells.begin();
                it1=it1+decision2-1;
                delete my_spells.at(decision2-1);
                my_spells.erase(it1);
                cout << " has been succesfuly sold! \n\n";
                cout << " Your new balance is: " << money << "$\n\n";
            }
        }
    }
    cout <<endl;
}

// MAGIC

int Hero::spell_check() {
    int count=0;
    if (my_spells.empty()) return count;
    else {
        for (int i=0;i<my_spells.size();i++){
            if (((my_spells.at(i)->getExperienceLevel())<=(this->getLevel()))&&((my_spells.at(i)->getMagicalEnergy())<=(this->magicPower))){
                count++;
            }
        }
    }
    return count;
}

Spell* Hero::castSpell(int how_many_spells) {
    int decision;
    Spell* temp;
    do {
        int k=1;
        cout << "Which of your spells would you like to cast? \n\n";
        for (int i = 0; i < my_spells.size(); i++) {
            if (((my_spells.at(i)->getExperienceLevel())<=(this->getLevel()))&&((my_spells.at(i)->getMagicalEnergy())<=(this->magicPower))){
                cout << " " << k << ". ";
                my_spells.at(i)->print();
                cout<<endl;
                k++;
            }
        }
        cout << "\n> ";
        cin >> decision;
        cout << endl;
        if (!cin) { // user didn't input a number
            cin.clear(); // reset failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }while (decision>how_many_spells||decision<1);
    int lcount=1; //To count the possible spells out of all the ones the hero has
    for (int i=0; i<my_spells.size();i++) {
        if ((my_spells.at(i)->getExperienceLevel()<=this->getLevel())&&(my_spells.at(i)->getMagicalEnergy()<=this->magicPower)){
            if (decision==lcount){
                cout << endl<< endl << name << " casted " << my_spells.at(i)->getName() << "!\n";
                temp = my_spells.at(i);
                int finaldamage = int((my_spells.at(i)->getDamage())*dexterity); //Damage adjusted to the dexterity of the hero
                for (int jjj=0;jjj<my_potions.size();jjj++) {
                    if ((my_potions.at(jjj)->isInUse()) && (my_potions.at(jjj)->getAttributeImprovement() =="Dexterity")) { //And to an active dexterity potion
                        finaldamage*=my_potions.at(jjj)->getIncrement();
                        vector<Potion *>::iterator it6; //and then removing it
                        it6 = my_potions.begin();
                        it6 =it6+jjj;
                        delete my_potions.at(jjj);
                        my_potions.erase(it6);
                    }
                }
                temp->setDamage(finaldamage);
                magicPower-=my_spells.at(i)->getMagicalEnergy();
                vector<Spell*>::iterator it1;
                it1= my_spells.begin();
                it1=it1+i;
                my_spells.erase(it1);
            
            }
            lcount++; //not inside an else statement so you dont go again in the above condition when decision is 1
        }
    }
    return temp;
}

int Monster::defendFrom(Spell* evilSpell) {
    int spellPower=0;
    int dodging =int(dodge_probability*100);
    if (under_a_spell.empty()==false&&under_a_spell.front()->getType()=="Lightning Spell") {
        dodging=dodging-(dodging*((under_a_spell.front())->getExperienceLevel()/10)); //reducing the chances of dodging the attack
    }
    srand(time(NULL));
    if (rand()%100<dodging){
        cout << endl << name << " dodged the spell's damage, but\n";
    }
    else {
        int defensive = int(defence);
        if (under_a_spell.empty()==false&&under_a_spell.front()->getType()=="Fire Spell"){
            defensive=defensive-(defensive*((under_a_spell.front()->getExperienceLevel())/10)); //reducing monster's defence. (amount depends on the level of the spell)
        }
        int force= (evilSpell->getDamage())*(evilSpell->getDamage())/((evilSpell->getDamage())+defensive);
        if (force>0) {
            cout << endl << name << " received " << force << " of the spell's damage!\n";
            healthPower = healthPower - force;
            if (healthPower<1) healthPower=0;
        }
        else cout << endl << name << " managed to block the spell's damage, but\n";
    }
    if (under_a_spell.empty()) {
        cout << endl << evilSpell->getName() << " has spellbound " << name << "!\n\n";
        spellPower=int((evilSpell->getExperienceLevel())/3+1);
        under_a_spell.push_back(evilSpell);
    }
    else cout << endl << evilSpell->getName() << " didn't spellbind " << name << ", \nthat is already under the effect of " << under_a_spell.front()->getName() <<"!\n\n";
    return spellPower;
}

bool Monster::defendFrom(int attack_power) { //Defending from an attack
    int defensive = int(defence);
    int dodging =int(dodge_probability*100);
    if (under_a_spell.empty()==false&&under_a_spell.front()->getType()=="Lightning Spell") {
        dodging-=int(dodging*((under_a_spell.front())->getExperienceLevel()/10)); //reducing the chances of dodging the attack
    }
    srand(time(NULL));
    if (rand()%100<dodging){
        cout << endl << name << " dodged the attack! \n\n";
    }
    else {
        if (under_a_spell.empty() == false && under_a_spell.front()->getType() == "Fire Spell") {
            defensive -= int(defence * ((under_a_spell.front()->getExperienceLevel())/10)); //reducing monster's defence. (amount depends on the level of the spell)
        }
        int force= attack_power*attack_power/(attack_power+defensive);
        if (force>0) {
            cout << endl << name << " received " << force << " damage!\n\n";
            healthPower -= force;
        }
        else cout << endl << name << " blocked the attack!\n\n";
    }
    if (healthPower<1) {
        healthPower=0;
        return false; //Monster was defeated
    }
    else return true; //Monster still lives
}

void Monster::release_me_from_my_spell() {
    if(!under_a_spell.empty()) {
        cout << endl << name << " has been released from the " << under_a_spell.front()->getName() << " spell!\n\n";
        delete under_a_spell.front();
        under_a_spell.pop_back();
    }
}

void Monster::cleanup_spell_space() {
    if(!under_a_spell.empty()) {
        delete under_a_spell.front();
        under_a_spell.pop_back();
    }
}

//BATTLE

int Hero::attack(){
    int damage=int(strength);
    for (int i=0;i<my_potions.size();i++){
        if (my_potions.at(i)->isInUse()&&my_potions.at(i)->getAttributeImprovement()=="Strength"){ //Using the active potion
            damage*=(my_potions.at(i)->getIncrement());
            vector<Potion*>::iterator it1; //and then removing it
            it1=my_potions.begin();
            it1+=i;
            delete my_potions.at(i);
            my_potions.erase(it1);
        }
    }
    for (int i=0;i<my_weapons.size();i++){
        if (my_weapons.at(i)->isInUse()) damage=int(damage+((my_weapons.at(i)->getDamage())));
    }
    for (int jjj=0;jjj<my_potions.size();jjj++) { //Removing a potion from their system in case they used dexterity potion, but didn't cast a spell
        if ((my_potions.at(jjj)->isInUse()) && (my_potions.at(jjj)->getAttributeImprovement() =="Dexterity")) {
            vector<Potion *>::iterator it6;
            it6 = my_potions.begin();
            it6 =it6+jjj;
            delete my_potions.at(jjj);
            my_potions.erase(it6);
        }
    }
    return damage;
}

bool Hero::defend(int damage) {
    cout << name << "!\n";
    double cur_agility=agility;
    for (int i=0;i<my_potions.size();i++){
        if (my_potions.at(i)->isInUse()&&my_potions.at(i)->getAttributeImprovement()=="Agility"){ //Using the active agility potion
            cur_agility*=double(my_potions.at(i)->getIncrement());
            vector<Potion*>::iterator it1; //and then removing it
            it1=my_potions.begin();
            it1+=i;
            delete my_potions.at(i);
            my_potions.erase(it1);
        }
    }
    int probability =int(agility*100);
    srand(time(NULL));
    if(rand()%100<probability){
        cout << endl << name << " avoided the monster's attack!\n\n";
    }
    else {
        int defensive = 0;
        for (int i=0; i<my_armours.size();i++){
            if (my_armours.at(i)->isInUse()){
                defensive=my_armours.at(i)->getProtection();
            }
        }
        int force=damage*damage/(damage+defensive);
        if (force>0){
            healthPower-=force;
            cout << endl << name << " received " << force << " damage!" << endl<< endl;
        }
        else cout << endl << name << " managed to block the monster's attack!\n\n";
    }
    if(healthPower<0){
        healthPower=0;
        return false; //is defeated
    }
    return true; //still lives
}

void Hero::resurrect(){
    if (healthPower==0) healthPower=maxPower/2;
}

void Hero::rejuvenate() {
    if (healthPower!=0) {
        if (healthPower<maxPower-1) healthPower += level/3+1;
        if (healthPower>maxPower) healthPower=maxPower;
        magicPower += level/3+1;
        if (magicPower > magicMaxPower) magicPower=magicMaxPower;
    }
}

void Hero::setMoney(double money) {
    Hero::money = money;
}

void Hero::reward(int size) {
    this->setMoney(this->getMoney()+(level*size));
    cout <<endl << name << " gained +" << (level*size) << "$\n\n";
    this->setExperience(this->getExperience()+ (level*size));
    cout << name << " gained +" << (level*size) << "XP\n\n";
    if (experience>=(level*level*10)) this->LEVEL_UP();
}

void Hero::LEVEL_UP() {
    this->level=level+1;
    this->setAgility(agility+0.03);
    this->setDexterity(dexterity+0.08);
    this->setStrength(strength+level);
    this->setMagicMaxPower(magicMaxPower+10);
    this->setMagicPower(magicMaxPower);
    this->setMaxPower(maxPower+10);
    this->setHealthPower(maxPower);
    cout << name << " has Leveled Up!\n";
}

void Hero::setExperience(double xp) {
    Hero::experience = xp;
}

double Hero::getExperience() const {
    return experience;
}

void Monster::rejuvenate() {
    if (healthPower<maxPower-1) healthPower += level/3+1;
    if (healthPower > maxPower) healthPower=maxPower;
}

int Monster::attack(){
    int attacking_force=int(damage);
    if ((!under_a_spell.empty())&&(under_a_spell.front()->getType()=="Ice Spell")){
        attacking_force-=int(attacking_force*(under_a_spell.front()->getExperienceLevel()/9));
    }
    cout << name << " is attacking ";
    return attacking_force;
}

Hero::~Hero(){}