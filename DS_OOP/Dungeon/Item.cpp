#include "Item.h"
#include "Player.h"

Item::Item(){

}

Item::Item(string name,int health,int physicAttack,int magicAttack,int physicDefense, int magicDefense){
    Object::setName(name);
    this->health = health;
    this->physicAttack = physicAttack;
    this->magicAttack = magicAttack;
    this->physicDefense = physicDefense;
    this->magicDefense = magicDefense;
}

Item::Item(string name ,int price,int health,int physicAttack,int magicAttack,int physicDefense, int magicDefense){
    Object::setName(name);
    this->price = price;
    this->health = health;
    this->physicAttack = physicAttack;
    this->magicAttack = magicAttack;
    this->physicDefense = physicDefense;
    this->magicDefense = magicDefense;
}

bool Item::triggerEvent(Object* character) {
    Player *player;
    int health;
    if(character->getTag() == "Player"){
        player = dynamic_cast<Player*>(character);
        player->increaseStates(this->health,this->health,this->physicAttack,this->magicAttack,this->physicDefense,this->magicDefense);

    }
    return 0;
};


void Item::setPrice(int price){
    this->price =price;
}

int Item::getPrice(){
    return this->price;
}


void Item::setHealth(int health){
    this->health = health;
}

void Item::setPhysicAttack(int physicAttack){
    this->physicAttack = physicAttack;
}

void Item::setMagicAttack(int magicAttack){
    this->magicAttack = magicAttack;
}

void Item::setPhysicDefense(int physicDefense){
    this->physicDefense = physicDefense;
}

void Item::setMagicDefense(int magicDefense){
    this->magicDefense = magicDefense;
}

int Item::getHealth(){
    return this->health;
}

int Item::getPhysicAttack(){
    return this->physicAttack;
}

int Item::getMagicAttack(){
    return this->magicAttack;
}

int Item::getPhysicDefense(){
    return this->physicDefense;
}

int Item::getMagicDefense(){
    return this->magicDefense;
}
