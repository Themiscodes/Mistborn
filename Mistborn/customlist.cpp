
#include "customlist.h"

monsterList::monsterList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
    list_size = 0;
}

void monsterList::add(Monster* monster){
    NodePtr n = new Node;
    n->next = NULL;
    n->monster = monster;
    n->round=0;
    if (head!=NULL){
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next=n;
    }
    else{
        head = n;
    }
    list_size++;
}

Monster* monsterList::at(int index){
    curr = head;
    for (int i=0;i<index;i++) {
        curr = curr->next;
    }
    return curr->monster;
}

void monsterList::subdue(int index, int effective_for){
    curr = head;
    for (int i=0;i<index;i++) {
        curr = curr->next;
    }
    if ((curr->round==0)&&(effective_for!=0)) curr->round=effective_for; //how many rounds the effectiveness of the spell will last
}

void monsterList::checkEnchantments() {
    curr=head;
    while(curr!=NULL){
        if (curr->round==0) curr->monster->release_me_from_my_spell();
        else curr->round--;
        curr=curr->next;
    }
}

void monsterList::vanish(int index) {
    NodePtr delPtr = NULL;
    temp = head;
    for (int i=0;i<index;i++) {
        delPtr=temp;
        temp=curr;
        curr=curr->next;
    }
    if (temp==head){
        head=head->next;
        temp->monster->cleanup_spell_space();
        delete temp->monster;
        temp=NULL;
        delete temp;
    }
    else {
        delPtr->next=curr;
        temp->monster->cleanup_spell_space();
        delete temp->monster;
        temp=NULL;
        delete temp;
    }
    list_size--;
}

monsterList::~monsterList(){
    while (head!=NULL){
        curr = head;
        head = head ->next;
        curr->monster->cleanup_spell_space();
        delete curr->monster;
        delete curr;
        list_size--;
    }
}
