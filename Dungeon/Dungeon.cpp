#include "Dungeon.h"

Dungeon::Dungeon(){

}

void Dungeon::createPlayer(){
    string name;
    Room* firstroom = &this->rooms[0];

   /* if(rooms[0].getRightRoom()==nullptr){
        cout<<"yes"<<endl;
    }else{
        cout<<"not"<<endl;
    }*/


    cout << "What's your name?" <<endl;
    cin >> name ;
    Player player(name,150,150,80,0,50,50);
    this->player = player;
    this->player.setTag("Player");
    this->player.setMoney(0);
    this->player.setCurrentRoom(firstroom);

}

void Dungeon::createMap(){
    //Monster
    Monster *zombieptr  = new Monster("Zombie",120,120,70,0,30,30);
    zombieptr->setTag("Monster");

    Monster *ghostptr = new Monster("Ghost",200,200,85,0,50,20);
    ghostptr->setTag("Monster");

    Monster *wolfptr = new Monster("Warewolf",500,500,90,0,20,70);
    wolfptr->setTag("Monster");

    //NPC
    vector<Item> commodities1,commodities2;
    Item hp_potion("HP Potion",90,0,0,0,0), skill("Rasengan!!!!",0,0,150,0,0),skill2("Chidori!!!!",0,200,0,0,0);
    hp_potion.setPrice(20);
    hp_potion.setTag("Potion");
    skill.setTag("Skill");
    skill.setPrice(100);
    commodities1.push_back(hp_potion);
    commodities1.push_back(skill);
    NPC *merchant1ptr = new NPC("Naruto","Sasuke!!!!",commodities1);
    merchant1ptr->setTag("NPC");

    skill2.setTag("Skill");
    skill2.setPrice(200);
    commodities2.push_back(hp_potion);
    commodities2.push_back(skill2);
    NPC *merchant2ptr = new NPC("Sasuke","Naruto!!!!",commodities2);
    merchant2ptr->setTag("NPC");

    //Treasure and Weapon
    Item *treasureptr = new Item("Treasure",150,0,0,0,0,0);
    treasureptr->setTag("Treasure");

    Item *weaponptr = new Item("Sword",0,0,30,0,0,0);
    weaponptr->setTag("Weapon");

    Item *one_pieceptr = new Item("One_Piece",9999999,0,0,0,0,0);
    one_pieceptr->setTag("Treasure");

    //Room
    int roomnum = 8;
    Room *first,*one,*two,*three,*four,*five,*six,*seven;
    this->rooms.reserve(roomnum);
    vector<Object*> roomobject;

    //construct the room and add object
    first = new Room(0,0);
    one = new Room(0,1,roomobject);
    one->addObject(zombieptr);
    two = new Room(0,2,roomobject);
    two->addObject(merchant1ptr);
    three = new Room(0,3,roomobject);
    three->addObject(ghostptr);
    four = new Room(0,4,roomobject);
    four->addObject(treasureptr);
    four->addObject(weaponptr);
    five = new Room(0,5,roomobject);
    five->addObject(merchant2ptr);
    six = new Room(0,6,roomobject);
    six->addObject(wolfptr);
    seven = new Room(1,7,roomobject);
    seven->addObject(one_pieceptr);

    //link the room
    first->setRightRoom(one);
    one->setLeftRoom(first);

    one->setRightRoom(two);
    two->setLeftRoom(one);
    one->setDownRoom(four);
    four->setUpRoom(one);

    two->setDownRoom(three);
    three->setUpRoom(two);

    three->setLeftRoom(four);
    four->setRightRoom(three);
    three->setDownRoom(six);
    six->setUpRoom(three);

    four->setDownRoom(five);
    five->setUpRoom(four);

    five->setRightRoom(six);
    six->setLeftRoom(five);

    six->setRightRoom(seven);
    seven->setLeftRoom(six);

    //push into vector
    rooms.push_back(*first);
    rooms.push_back(*one);
    rooms.push_back(*two);
    rooms.push_back(*three);
    rooms.push_back(*four);
    rooms.push_back(*five);
    rooms.push_back(*six);
    rooms.push_back(*seven);
}

void Dungeon::handleMovement(){
    cout << "Enter the corresponding number to choose where you want to go." << endl;
    //handle input
    char direction;
    while(true){
            //avoid display nullptr direction
        if(this->player.getCurrentRoom()->getUpRoom() != nullptr){
            cout << "(1) : go up" << endl;
        }
        if(this->player.getCurrentRoom()->getDownRoom() != nullptr){
            cout << "(2) : go down" <<endl;
        }
        if(this->player.getCurrentRoom()->getLeftRoom() != nullptr){
            cout << "(3) : go left" <<endl;
        }
        if(this->player.getCurrentRoom()->getRightRoom() != nullptr){
            cout << "(4) : go right" <<endl;
        }
        cin >> direction;
        switch(direction){
            case '1':{
                if(this->player.getCurrentRoom()->getUpRoom() != nullptr){
                    this->player.changeRoom(this->player.getCurrentRoom()->getUpRoom());
                    cout << "\nYou entered the up room.\n" <<endl;
                    break;
                }
                else{
                    cout << "Invalid input.Please enter qualified number!" <<endl;
                    continue;
                }
            }
            case '2':{
                if(this->player.getCurrentRoom()->getDownRoom() != nullptr){
                    this->player.changeRoom(this->player.getCurrentRoom()->getDownRoom());
                    cout << "\nYou entered the down room.\n" <<endl;
                    break;
                }
                else{
                    cout << "Invalid input.Please enter qualified number!" <<endl;
                    continue;
                }
            }
            case '3':{
                if(this->player.getCurrentRoom()->getLeftRoom() != nullptr){
                    this->player.changeRoom(this->player.getCurrentRoom()->getLeftRoom());
                    cout << "\nYou entered the left room.\n" <<endl;
                    break;
                }
                else{
                    cout << "Invalid input.Please enter qualified number!" <<endl;
                    continue;
                }
            }
            case '4':{
                if(this->player.getCurrentRoom()->getRightRoom() != nullptr){
                    this->player.changeRoom(this->player.getCurrentRoom()->getRightRoom());
                    cout << "\nYou entered the right room.\n" <<endl;
                    break;
                }
                else{
                    cout << "Invalid input.Please enter qualified number!" <<endl;
                    continue;
                }
            }
            default:{
                cout <<"Invalid input.Please enter qualified number!" <<endl;
                continue;
            }
        }
        break;
    }
}

void Dungeon::handleEvent(Object* object){
    string movement;
    Player *player = &this->player;
    if(object == this->player.getCurrentRoom()->getObjects()[0]){
            //monster
        if(object->getTag()=="Monster"){
            Monster *monster = dynamic_cast<Monster*>(object);
            monster->triggerEvent(player);

            //處理遇到怪物撤退沒觸發NPC的情況
            if(player->getCurrentRoom()->getIndex()==2||player->getCurrentRoom()->getIndex()==5){
                handleEvent(player->getCurrentRoom()->getObjects()[0]);
            }
            //處理遇到怪物撤退寶箱沒開的狀況
            else if(player->getCurrentRoom()->getIndex()==4 && player->getCurrentRoom()->getObjects().size()!=0){
                handleEvent(player->getCurrentRoom()->getObjects()[0]);
                if(player->getCurrentRoom()->getObjects().size()==1){
                    handleEvent(player->getCurrentRoom()->getObjects()[1]);
                }
            }
            if(monster->getCurrentHealth()<=0 && player->getCurrentHealth()>=0){
                if(monster->getName()=="Zombie"){
                    cout << "You got $100!"<<endl;
                    player->addmoney(100);
                }
                else if(monster->getName()=="Ghost"){
                    player->addmoney(300);
                    cout <<"You got $300" <<endl;
                }
                player->getCurrentRoom()->popObject(monster);
            }
        }
        else if(object->getTag()=="NPC"){                       //NPC
            NPC *merchant = dynamic_cast<NPC*>(object);
            merchant->triggerEvent(player);
        }
        else if(object->getTag()=="Treasure"){                  //handle open chest
            Item *treasure = dynamic_cast<Item*>(object);
            cout << "There is a chest!!!!" <<endl;

            while(true){
                cout << "Enter 1 to open or -1 to leave" <<endl;
                cin >> movement;
                if(movement == "1"){
                    cout << "You get $" <<treasure->getPrice() <<endl;
                    player->addmoney(treasure->getPrice());
                    treasure->setPrice(0);
                    player->getCurrentRoom()->popObject(treasure);
                    break;
                }
                else if(movement=="-1"){
                    handleMovement();
                    break;
                }
                else{
                    cout << "Invalid input!" <<endl;
                    continue;
                }
            }
        }
        else if(object->getTag()=="Weapon"){
            Item *weapon = dynamic_cast<Item*>(object);
            weapon->triggerEvent(player);
            player->addItem(*weapon);
            cout << "You get a sword!  Physic Attack +30" << endl;
            weapon->setPhysicAttack(0);
            player->getCurrentRoom()->popObject(weapon);
        }
        else{
            cout << "maybe didnt set tag" <<endl;
        }
    }
    else{
        //避免不開寶相遇怪撤退不開寶相回到怪物房間
        handleEvent(player->getCurrentRoom()->getObjects()[0]);
    }
}


void Dungeon::startGame(){
    createMap();
    createPlayer();
    cout << "Welcome to Dungeon!" <<endl;
    cout << "Now start your adventure" <<endl;
    Player*player = &this->player;
}

void Dungeon::chooseAction(vector<Object*> object){
    string act;
    Player *player = &this->player;
    if(object.size()!=0){
        for(int i = 0; i<object.size() ; i++){
            int index = player->getCurrentRoom()->getIndex();
            handleEvent(object[i]);

            //處理寶箱沒開到別的房間的狀況
            if(player->getCurrentRoom()->getIndex()!=index&&player->getCurrentRoom()->getObjects().size()!=0){
               handleEvent(player->getCurrentRoom()->getObjects()[0]);
               break;
            }
            else if(player->getCurrentRoom()->getIndex()!=index&&player->getCurrentRoom()->getObjects().size()==0){
                break;
            }
        }
    }

    if(player->getCurrentHealth()>0){
        if(player->getCurrentRoom()->getIsExit()!=1||player->getCurrentRoom()->getObjects().size()==1){
            while(true){
                cout << "\n\nEnter the corresponding number to choose what you want to do." <<endl;
                cout << "(1) Move" <<endl;
                cout << "(2) Check your status" << endl;
                cout << "(3) Check your item" << endl;
                cout << "(4) Save File" <<endl;
                cin >> act;
                if(act == "1"){
                    handleMovement();
                    break;
                }
                else if(act == "2"){
                    this->player.triggerEvent(player);
                    continue;
                }
                else if(act == "3"){
                    this->player.listItem();
                    continue;
                }

                else if(act=="4"){                                //Record
                    Record record;
                    record.saveToFile(player,this->rooms);
                    cout <<"(1):Exit (2):Continue "<<endl;
                    string play;
                    while(true){
                        cin >> play;
                        if(play=="1"){
                            exit(0);
                        }
                        else if(play=="2"){
                            break;
                        }
                        else{
                            cout <<"Please enter qualified number!" <<endl;
                        }
                    }
                    break;
                }

                else{
                    cout <<"Invalid input.Please enter qualified number!" <<endl;
                    continue;
                }
            }
        }

    }
}


bool Dungeon::checkGameLogic(){
    if(player.getCurrentRoom()->getIsExit()==1){
        if(player.getMoney()>10000){
            cout << "Congratulation! Thanks for playing!" <<endl;
            return 1;
        }
    }
    else if(player.getCurrentHealth()<=0){
        cout << "HP = 0" <<endl;
        return 1;
    }
    else{
        //cout << "keep going" <<endl;
        return 0;
    }
}


void Dungeon::runDungeon(){

    Record record;
    Player*playerptr = &(this->player);
    ifstream infile;
    infile.open("dungeon_saved.txt");
    if(infile.is_open()){
        cout <<"Do you want to load previous game?"<<endl;
        cout <<"Enter \"y\" or \"n\" to choose."<<endl;
        while(true){
            char choose;
            cin >>choose;
            if(choose=='y'){
                record.loadFromFile(playerptr,this->rooms);
                break;
            }
            else if(choose=='n'){
                startGame();
                break;
            }
            else{
                cout<<"Please enter qualified word!"<<endl;
                continue;
            }
        }
    }
    else{
        startGame();
    }


    //startGame();
    chooseAction(this->player.getCurrentRoom()->getObjects());

    while(true){
        if(checkGameLogic()==1){    //player die
            cout <<"88"<<endl;
            break;
        }
        else{
            chooseAction(this->player.getCurrentRoom()->getObjects());
        }
    }
    infile.close();
}
