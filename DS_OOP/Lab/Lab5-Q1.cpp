#include <vector>
#include <iostream>
using namespace std;

class Object{
public:
    virtual void response() = 0;
    
    virtual ~Object() = default;
};

class IceMonster : public Object{
    //add constructor or functions if you need
public:
    IceMonster(){ this->exist = 1; };
    void response(){
        if (this->exist == 1){
          cout << "fire attack";
          this->exist = 0;
        }
    }
    int exist;
};

class FireMonster : public Object{
    //add constructor or functions if you need
public:
    FireMonster(){ this->exist = 1; };
    void response(){
        if (this->exist == 1){
          cout << "ice attack";
          this->exist = 0;
        }
    }
    int exist;
};

class Treasure : public Object{
    //add constructor or functions if you need
public:
    Treasure(){ this->exist = 1; };
    void response(){
        if (this->exist == 1){
          cout << "ya";
          this->exist = 0;
        }
    }
    int exist;
};


class Room{
public:
    Room *up_room;
    Room *down_room;
    Room *left_room;
    Room *right_room;
    int index;
    int u, r, d, l;
    Object *o;
    //add constructor or functions if you need
    Room(int u, int r, int d, int l, int i){
        this->u = u;
        this->r = r;
        this->d = d;
        this->l = l;
        this->index = i;
        this->up_room = nullptr;
        this->down_room = nullptr;
        this->left_room = nullptr;
        this->right_room = nullptr;
        this->o = nullptr;
    }

   
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int roomnum, steps, u, r, d, l;
    char type;
    vector<Room> rooms;
    rooms.reserve(100);
    Room* pos = nullptr;


    cin >> roomnum >> steps;

    /*Construct the Rooms*/
    for(int i=0; i<roomnum; i++){
        cin >> type >> u >> d >> l >> r;

        Room t(u, r, d, l, i);
        rooms.push_back(t);

        switch(type){
        case 'e':{
            rooms.back().o = nullptr;
            break;
        }
        case 'f':{
            rooms.back().o = new FireMonster();
            break;
        }
        case 'i':{
            rooms.back().o = new IceMonster();
            break;
        }
        case 't':{
            rooms.back().o = new Treasure();
            break;
        }
        }

    }

    /*Link the room*/
    for (int i=0; i<roomnum; i++){
        if (rooms[i].u == -1){
            rooms[i].up_room = nullptr;
        }
        else{
            rooms[i].up_room = &(rooms[rooms[i].u]);
            rooms[rooms[i].u].down_room = &(rooms[i]);
        }

        if (rooms[i].r == -1){
            rooms[i].right_room = nullptr;
        }
        else{
            rooms[i].right_room = &(rooms[rooms[i].r]);
            rooms[rooms[i].r].left_room = &(rooms[i]);
        }

        if (rooms[i].d == -1){
            rooms[i].down_room = nullptr;
        }
        else{
            rooms[i].down_room = &(rooms[rooms[i].d]);
            rooms[rooms[i].d].up_room = &(rooms[i]);
        }

        if (rooms[i].l == -1){
            rooms[i].left_room = nullptr;
        }
        else{
            rooms[i].left_room = &(rooms[rooms[i].l]);
            rooms[rooms[i].l].right_room = &(rooms[i]);
        }
    }


    /*Walk through the rooms*/
    pos = &(rooms[0]);
    cout << pos->index << endl;

    for (int i=0; i<steps; i++){
        char act;
        cin >> act;
        //cout << act << endl;
        switch(act){
        case 'u':{
            if (pos->u != -1){
                pos = pos->up_room;
                cout << pos->index << ' ';
                if (pos->o != nullptr){
                    pos->o->response();
                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
            break;
        }
    
        case 'r':{
            if (pos->r != -1){
                pos = pos->right_room;
                cout << pos->index << ' ';
                if (pos->o != nullptr){
                    pos->o->response();
                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
            break;
        }
        case 'd':{
            if (pos->d != -1){
                pos = pos->down_room;
                cout << pos->index << ' ';
                if (pos->o != nullptr){
                    pos->o->response();
                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
            break;
        }
        case 'l':{
            if (pos->l != -1){
                pos = pos->left_room;
                cout << pos->index << ' ';
                if (pos->o != nullptr){
                    pos->o->response();
                }
                cout << endl;
            }
            else{
                cout << "-1" << endl;
            }
            break;
        }
        }
    }

    return 0;
}