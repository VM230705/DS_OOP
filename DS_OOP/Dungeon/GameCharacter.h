#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
protected:
    //string name;
    int maxHealth;
    int currentHealth;
    int physicAttack;
    int magicAttack;
    int physicDefense;
    int magicDefense;
public:
    GameCharacter();
    GameCharacter(string,int,int,int,int,int,int);
    bool checkIsDead();
    int takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setPhysicAttack(int);
    void setMagicAttack(int);
    void setPhysicDefense(int);
    void setMagicDefense(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getPhysicAttack();
    int getMagicAttack();
    int getPhysicDefense();
    int getMagicDefense();
};
#endif // GAMECHARACTER_H_INCLUDED
