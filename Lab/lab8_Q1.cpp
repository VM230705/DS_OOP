#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
    int r = 0;
    string str;
    cin >>r;

    for (int t=0; t<r; t++){
        cin >> str;
        stack<char> bracket;
        for (int i=0; i<(int)str.length() ;i++){
            if (str[i] == '{'){
                bracket.push(str[i]);
            }
            else if(str[i] == '('){
                bracket.push(str[i]);
            }
            else if(str[i] == '['){
                bracket.push(str[i]);
            }
            else if (str[i] == '}'){
                if (bracket.size() != 0 && bracket.top() == '{')
                    bracket.pop();
            }
            else if(str[i] == ')'){
                if (bracket.size() != 0 && bracket.top() == '(')
                    bracket.pop();
            }
            else if(str[i] == ']'){
                if (bracket.size() != 0 && bracket.top() == '[')
                    bracket.pop();
            }
        }


        if (bracket.empty() == false){
            cout << "no" << endl;
        }
        else{
            cout << "yes" <<endl;
        }
    }

    return 0;
}