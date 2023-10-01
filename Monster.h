#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "GameCharacter.h"
#include "Player.h"
#include "Item.h"
#include <ctime>

using namespace std;

class Monster: public GameCharacter
{
private:
    vector<Item> equip;
public:
    Monster();
    Monster(string,int,int,int, vector<Item>);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object*);
    void setEquip(Item);
    vector<Item> getEquip();
};


#endif // ENEMY_H_INCLUDED
