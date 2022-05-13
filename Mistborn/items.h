
#ifndef MISTBORN_ITEMS_H
#define MISTBORN_ITEMS_H
#include <iostream>
#include <cstring>

using namespace std;

class Item{
    protected:
        string name;
        string type;
        double price;
        unsigned int experience_level;
        bool in_use;
    public:
        Item(const string &name="default", double price=1, unsigned int experienceLevel=1, const string &type="item", bool in_use=false) : name(name), price(price), experience_level(experienceLevel), type(type), in_use(in_use) {}
        const string &getName() const {
            return name;
        }
        double getPrice() const {
            return price;
        }
        bool isInUse() const {
            return in_use;
        }
        void equip() {in_use=true;}
        void remove() {in_use=false;}
        unsigned int getExperienceLevel() const {
            return experience_level;
        }
        virtual void print();
        virtual ~Item(){}
};

class Weapon : public Item{
    private:
        int damage;
        bool two_handed_wield;
    public:
        Weapon(const string& name="default", double price=1, unsigned int experience_level=1, int damage=1, bool twoHandedWield=false, const string &type="Weapon") : Item(name, price, experience_level, type), damage(damage), two_handed_wield(twoHandedWield) {}
        void print();
        int getDamage() const {
            return damage;
        }
        bool isTwoHandedWield() const {
            return two_handed_wield;
        }
        ~Weapon(){}
};

class Armor : public Item{
    private:
        int protection;
public:
    Armor(const string &name="default", double price=1, unsigned int experienceLevel=1,  int protection=1, const string &type="Armour") : Item(name, price, experienceLevel, type),protection(protection) {}
    int getProtection() const {
        return protection;
    }
    void print();
    ~Armor(){}
};

class Potion : public Item {
    private:
        int increment;
        string attribute_improvement;
    public:
        Potion(const string &name="default", double price=1, unsigned int experienceLevel=1, const string &type="default", bool inUse=false, int increment=1, const string &attributeImprovement="Default") : Item(name, price, experienceLevel, type, inUse),increment(increment),attribute_improvement(attributeImprovement) {}
        const string &getAttributeImprovement() const{
            return attribute_improvement;
        }
        int getIncrement() const {
            return increment;
        }
        void print();
        ~Potion(){}
};

class Spell{
    protected:
        string name;
        double price;
        unsigned int experience_level;
        int damage;
        unsigned int magical_energy;
        const string type;
    public:
        Spell(const string &name="default", double price=1, unsigned int experienceLevel=1, int damage=1, unsigned int magicalEnergy=1, const string& type="default") : name(name), price(price), experience_level(experienceLevel), damage(damage), magical_energy(magicalEnergy), type(type) {}
        const string &getName() const {
            return name;
        }
        void print();
        double getPrice() const {
            return price;
        }
        void setDamage(int dmg) {
            damage = dmg;
        }

        unsigned int getExperienceLevel() const {
            return experience_level;
        }

        unsigned int getDamage() const {
            return damage;
        }

        unsigned int getMagicalEnergy() const {
            return magical_energy;
        }

        const string &getType() const {
            return type;
        }
        virtual ~Spell() {}
};

class IceSpell : public Spell{
    public:
        IceSpell(const string &name="default", double price=1, unsigned int experienceLevel=1, unsigned int damage=1, unsigned int magicalEnergy=1, const string &type="Ice Spell") : Spell(name, price, experienceLevel, damage, magicalEnergy, type) {}
        ~IceSpell(){}
};

class FireSpell : public Spell{
    public:
        FireSpell(const string &name="default", double price=1, unsigned int experienceLevel=1, unsigned int damage=1, unsigned int magicalEnergy=1, const string &type="Fire Spell") : Spell(name, price, experienceLevel, damage, magicalEnergy, type) {}
        ~FireSpell(){}
};

class LightningSpell : public Spell{
    public:
        LightningSpell(const string &name="default", double price=1, unsigned int experienceLevel=1, unsigned int damage=1, unsigned int magicalEnergy=1, const string &type="Lightning Spell") : Spell(name, price, experienceLevel, damage, magicalEnergy, type) {}
        ~LightningSpell(){}
};

#endif //MISTBORN_ITEMS_H
