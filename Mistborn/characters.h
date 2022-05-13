
#ifndef MISTBORN_CHARACTERS_H
#define MISTBORN_CHARACTERS_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <ios>
#include <limits>
#include <iomanip>
#include "items.h"

using namespace std;

class Living{
    protected:
        string name;
        string type;
        unsigned int level;
        double healthPower;
        double maxPower;
    public:
        Living(const string &name="default", unsigned int level=1, double healthPower=10, const string &type="default", double maxPower=10) : name(name), level(level), healthPower(healthPower), type(type), maxPower(maxPower) {}
        const string &getType() const;
        unsigned int getLevel() const;
        const string &getName() const;
        double getHealthPower() const;
        void setHealthPower(double);
        void setMaxPower(double);
        virtual ~Living(){}
};

class Hero : public Living{
    protected:
        double magicPower;
        double magicMaxPower;
        double strength;
        double dexterity;
        double agility;
        double money;
        double experience;
        vector<Weapon* > my_weapons;
        vector<Armor* > my_armours;
        vector<Potion* > my_potions;
        vector<Spell*> my_spells;
    public:
        Hero(const string &name="default", unsigned int level=1, double healthPower=1, const string &type="default",double maxPower=1, double magicPower=1, double magicMaxPower=1, double strength=1, double dexterity=1, double agility=1, double money=1, double experience=0) : Living(name,level,healthPower, type, maxPower), magicPower(magicPower), magicMaxPower(magicMaxPower), strength(strength), dexterity(dexterity), agility(agility), money(money), experience(experience) {}
        void buy(Weapon*);
        void buy(Armor*);
        void buy(Potion*);
        void buy(Spell*);
        Spell* castSpell(int );
        bool have_summat_to_sell();
        void acquire(Weapon*);
        void acquire(Armor*);
        void acquire(Potion*);
        void acquire(Spell*);
        bool checkInventory();
        int healthPotionAvail();
        void selling_options();
        void reward(int );
        void LEVEL_UP();
        int spell_check();
        void setMoney(double);
        void setMagicPower(double mP) {
            Hero::magicPower = mP;
        }
        void setMagicMaxPower(double mP) {
            Hero::magicMaxPower = mP;
        }
        void setStrength(int str) {
            Hero::strength = str;
        }
        void setDexterity(double dxtr) {
            Hero::dexterity = dxtr;
        }
        void setAgility(double ag) {
            Hero::agility = ag;
        }
        double getExperience() const ;
        void setExperience(double );
        void inventory();
        double getMoney() const ;
        void displayStats();
        int attack();
        bool defend(int);
        void resurrect();
        void rejuvenate();
        virtual ~Hero();
};

class Warrior : public Hero{
    public:
        Warrior(const string &name="Warrior", unsigned int level=1, double healthPower=10, const string &type="Warrior", double maxPower=10,
                double magicPower=10, double magicMaxPower=10, double strength=6, double dexterity=0.5, double agility=0.15, double money=7,
                double experience=0): Hero(name, level, healthPower, type, maxPower, magicPower, magicMaxPower, strength, dexterity, agility, money, experience) {}
        ~Warrior(){}
};

class Sorcerer : public Hero{
    public:
        Sorcerer(const string &name="Sorcerer", unsigned int level=1, double healthPower=10, const string &type="Sorcerer", double maxPower=10,
                     double magicPower=16, double magicMaxPower=16, double strength=4, double dexterity=1, double agility=0.16, double money=11,
                     double experience=0): Hero(name, level, healthPower, type, maxPower, magicPower, magicMaxPower, strength, dexterity, agility, money, experience) {}
        ~Sorcerer(){}
};

class Paladin : public Hero{
    public:
        Paladin(const string &name="Paladin", unsigned int level=1, double healthPower=10, const string &type="Paladin", double maxPower=10,
                      double magicPower=12, double magicMaxPower=12, double strength=5, double dexterity=0.8, double agility=0.08, double money=8,
                      double experience=0): Hero(name, level, healthPower, type, maxPower, magicPower, magicMaxPower, strength, dexterity, agility, money, experience) {}
        ~Paladin(){}
};

class Monster : public Living{
    protected:
        double damage;
        double defence;
        double dodge_probability;
        vector<Spell*> under_a_spell;
    public:
        Monster(const string &name="default", unsigned int level=1, double healthPower=1, double damage=1, double defence=1,
            double dodgeProbability=1, const string &type="default") : Living(name, level, healthPower, type, healthPower),
            damage(damage), defence(defence), dodge_probability(dodgeProbability) {}

            void displayStats();
        int defendFrom(Spell* );
        void release_me_from_my_spell();
        void cleanup_spell_space();
        bool defendFrom(int );
        int attack();
        void rejuvenate();
        virtual ~Monster(){}
};

class Dragon : public Monster{
    public:
        Dragon(const string &name="Dragon", unsigned int level=1, double healthPower=1,
                        double damage=1, double defence=1, double dodgeProbability=0.1, const string &type="Dragon") :
               Monster(name, level, healthPower, damage, defence, dodgeProbability, type) {}

        ~Dragon(){}
};

class Exoskeleton : public Monster{
    public:
        Exoskeleton(const string &name="Exoskeleton", unsigned int level=1, double healthPower=1,
                             double damage=1, double defence=1, double dodgeProbability=0.1, const string &type="Exoskeleton") :
                    Monster(name, level, healthPower, damage, defence, dodgeProbability, type) {}
        ~Exoskeleton(){}
};

class Spirit : public Monster{
    public:
        Spirit(const string &name="Spirit", unsigned int level=1, double healthPower=1,
                        double damage=1, double defence=1, double dodgeProbability=0.1, const string &type="Spirit") :
               Monster(name, level, healthPower, damage, defence, dodgeProbability, type) {}
        ~Spirit(){}
};

#endif //MISTBORN_CHARACTERS_H
