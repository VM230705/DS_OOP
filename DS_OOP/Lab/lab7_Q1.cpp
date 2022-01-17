#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

class LinkedList {
public:
    Node *root;
    int len;
    LinkedList() : root(nullptr), len(0) {}
    void push(int);
    void insert(int, int);
    int find(int);
    void remove(int);
    void print();
};

void LinkedList::push(int x){
	// your implementation
    Node*push = new Node(x);
    Node*cur =this->root;
    if(this->root ==nullptr){
        this->root = push;
    }
    else{
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next =  push;
    }
    this->len++;
}

void LinkedList::insert(int pos, int x){
	// your implementation
    Node*cur = new Node(x);
    Node*before = this->root; 
    if(pos>this->len){
        cout <<"insert fail"<<endl;
    }
    else if(pos==0){
        cur->next = this->root;
        this->root = cur;
        this->len++;
    }
    else{
        for(int i=0;i<pos-1;i++){
            before = before->next;
        }
        cur->next = before->next;
        before->next= cur;
        this->len++;
    }
}

int LinkedList::find(int x){
	// your implementation
    Node *cur = this->root;
    for(int i=0;i<this->len;i++){
        if(cur->val==x){
            return i;
        }
        cur = cur->next;
    }
    return -1;
}

void LinkedList::remove(int pos){
	// your implementation
    Node* discard;
    Node* before = this->root ;
    if(this->len-1<pos){
        cout <<"remove fail"<<endl;
    }
    else{
        for(int i=0;i<pos-1;i++){
            before = before->next;
        }
        if(pos==0){
            discard= this->root;
            this->root = this->root->next;
        }
        else{
            discard=before->next;
            before->next = discard->next;
        }
        delete discard;
        this->len--;
    }
}

void LinkedList::print(){
    if(root == nullptr){
        return;
    }

    Node *cur = root;
    while(cur->next != nullptr){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << cur->val << endl;
}

int main(){
    LinkedList mylist;
    
    int n, a, b;
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'p'){
            cin >> a;
            mylist.push(a);
        }else if(c == 'i'){
            cin >> a >> b;
            mylist.insert(a, b);
        }else if(c == 'r'){
            cin >> a;
            mylist.remove(a);
        }else if(c == 'f'){
            cin >> a;
            cout << mylist.find(a) << endl;
        }else if(c == '?'){
            mylist.print();
        }
    }
    return 0;
}