#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct Node{
    int data;
    Node* leftnode;
    Node* rightnode;
};

Node* create(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->leftnode = temp->rightnode = nullptr;
    return temp;
}

void insert(Node* &root,int data){
    if(root == nullptr){
        root = create(data);
    }
    else if(root->data > data){
        insert(root->leftnode,data);
    }
    else{
        insert(root->rightnode,data);
    }
}
void display(Node*root){
    if(root!=nullptr){
        display(root->leftnode);
        display(root->rightnode);
        cout << root->data << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    Node* root = nullptr;
    int n = 1000,num,last;
    for(int i =0 ; i<n ; i++){
        cin >> num;
        if(i!=0 && last ==num){
            continue;
        }
        insert(root,num);
        last = num;
    }
    display(root);
    return 0;
}
