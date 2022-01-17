#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void trim(string &str){
    int i =0,count1 = 0, count2 = 0;  
    while(str[i]== ' '){
        count1 ++;
        i++;
    }
   
    i = str.length()-1;
    while(str[i]== ' '){
        count2 ++;
        i--;
    }
    
    
    if(count1!=0){
        str.erase(str.begin(),str.begin()+count1);
    }  
    if(count2!=0){
            str.erase(str.end()-count2,str.end());
    }
}


void reverse(string &str){
	//TODO 
    std::reverse(str.begin(),str.end());
}

int main()
{
    string input_line;
  	//TODO 
    getline(cin,input_line);
    trim(input_line);
    reverse(input_line);
    cout << input_line << endl;
    return 0;
}