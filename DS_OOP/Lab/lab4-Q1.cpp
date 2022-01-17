#include <iostream>
using namespace std;

class Room{
public:
    Room *left_room ;
    Room *right_room ;
    int index;
    Room(int n){
        this->index = n;
    }
    //add constructor or functions if you need
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num , i , index;
    cin >>  num;
    
    Room *first, *back, *cur ,*path;
    
    for (i = 0; i < num; i++)
   
    {
        cin >>  index;
        cur = new Room(index);
        if(i==0){
            first = cur;
            back = cur;
            first->left_room = nullptr;
        }
        else{
            cur->left_room = back;
            back->right_room = cur;
            back = cur;
        }
    }

    int step;
    cin >> step;

    path = first;
    cout << path->index << " ";

    for (int i = 0; i < step; i++){
        char dir;
        cin >> dir;
        if(dir == 'l'  &&  path->left_room != nullptr){
            path = path->left_room;
            cout << path->index<<" ";
        }
        else if (dir == 'r' &&  path->right_room != nullptr){
            path = path->right_room;
            cout << path->index<<" ";
        }
        else{
            cout << -1 <<" ";
        }

    }

        return 0;
}