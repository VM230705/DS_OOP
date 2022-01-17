#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Player.h"
using namespace std;

class Player;

class Item: public Object
{
private:
    int health,physicAttack,magicAttack,physicDefense,magicDefense;
    int price;
public:
    Item();
    Item(string, int, int, int, int, int);
    Item(string ,int ,int, int, int, int, int);


    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */

    virtual bool triggerEvent(Object*) override;

    /* Set & Get function*/
    int getHealth();
    int getPhysicAttack();
    int getMagicAttack();
    int getPhysicDefense();
    int getMagicDefense();
    int getPrice();
    void setHealth(int);
    void setPhysicAttack(int);
    void setMagicAttack(int);
    void setPhysicDefense(int);
    void setMagicDefense(int);
    void setPrice(int);
};

#endif // ITEM_H_INCLUDED
