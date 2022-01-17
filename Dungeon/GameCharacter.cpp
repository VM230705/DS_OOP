#include "GameCharacter.h"

GameCharacter::GameCharacter(){

}


// should have current health < maximum health
GameCharacter::GameCharacter(string name,int maxHealth ,int currentHealth ,int physicAttack, int magicAttack,int physicDefense, int magicDefense){
    Object::setName(name);
    this->setTag("GameCharacter");
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->physicAttack = physicAttack;
    this->magicAttack = magicAttack;
    this->physicDefense = physicDefense;
    this->magicDefense = magicDefense;
}

bool GameCharacter::checkIsDead(){
    if (currentHealth<=0){
        return true;            //dead
    }
    else{
        return false;           //alive
    }
}

int GameCharacter::takeDamage(int damage){
    if(damage<=0){
        cout << "damage == 0" <<endl;
        return this->currentHealth;
    }
    else{
        return this->currentHealth = this->currentHealth - damage;
    }
}

void GameCharacter::setMaxHealth(int maxHealth){
    this->maxHealth = maxHealth;
}

void GameCharacter::setCurrentHealth(int currentHealth){
    this->currentHealth = currentHealth;
}

void GameCharacter::setPhysicAttack(int physicAttack){
    this->physicAttack = physicAttack;
}

void GameCharacter::setMagicAttack(int magicAttack){
    this->magicAttack = magicAttack;
}

void GameCharacter::setPhysicDefense(int physicDefense){
    this->physicDefense = physicDefense;
}

void GameCharacter::setMagicDefense(int magicDefense){
    this->magicDefense = magicDefense;
}

int GameCharacter::getMaxHealth(){
    return this->maxHealth;
}

int GameCharacter::getCurrentHealth(){
    return this->currentHealth;
}

int GameCharacter::getPhysicAttack(){
    return this->physicAttack;
}

int GameCharacter::getMagicAttack(){
    return this->magicAttack;
}

int GameCharacter::getPhysicDefense(){
    return this->physicDefense;
}

int GameCharacter::getMagicDefense(){
    return this->magicDefense;
}
