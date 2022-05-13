#include "items.h"

//PRINT FUNCTIONS
void Item::print() {
    cout << "I am the virtual item::print and Im not used.\n";
}
void Weapon::print() {
    cout << "\n " << name << "\n Level: "<< experience_level << " " << type <<endl;
    if (isTwoHandedWield()) cout << " Wield: Two-Handed";
    else cout << " Wield: One-Handed";
    cout << "\n Deals: " << damage << " Damage\n Cost: " << price << "$\n ";
    if (in_use) cout << " (Equipped)\n";
}
void Armor::print() {
    cout << "\n " << name << "\n Level: "<< experience_level<< " " << type<< endl;
    cout << " Deflects: " << protection << " Damage\n Cost: " << price << "$\n ";
    if (in_use) cout << " (Equipped)\n";
}
void Potion::print() {
    cout << "\n " << name << "\n Level: "<< experience_level<< " " << type <<endl;
    if (attribute_improvement=="Health") cout << " Restores: " << attribute_improvement << "\n by: " << increment << "%";
    else cout << " Increases: " << attribute_improvement << "\n Increment: " << increment << "X times";
    cout<< "\n Cost: " << price << "$\n ";
    if (in_use) cout << " (In Use)\n";
}
void Spell::print() {
    cout << "\n " << name << "\n Level: "<< experience_level<< " " << type;
    if (type=="Ice Spell") cout << "\n Reduces opponent's Damage \n for a few rounds";
    else if (type=="Fire Spell") cout << "\n Reduces opponent's Defence \n for a few rounds";
    else if (type=="Lightning Spell") cout << "\n Reduces opponent's Dodge Probability \n (For a few rounds)";
    cout << "\n Deals around: " << damage << " Damage";
    cout << "\n (Accentuated by Hero's Dexterity)";
    cout << "\n Requires: " << magical_energy << "MP";
    cout<< "\n Cost: " << price << "$\n ";
}