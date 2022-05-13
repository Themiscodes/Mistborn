
#include "characters.h"

#ifndef MISTBORN_CUSTOMLIST_H
#define MISTBORN_CUSTOMLIST_H

class monsterList {
    public:
        monsterList();
        ~monsterList();
        Monster* at(int );
        void add(Monster* );
        void vanish(int );
        void checkEnchantments();
        void subdue(int , int);
        int size() const {return list_size;}
    private:
        typedef struct Node{
            Monster* monster;
            int round;
            Node* next;
        }* NodePtr;
        NodePtr head;
        NodePtr curr;
        NodePtr temp;
        int list_size;
};

#endif //MISTBORN_CUSTOMLIST_H