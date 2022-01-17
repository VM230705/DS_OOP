#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    string str;
    stack<char> bracket;
    char last;
    cin >>num;
    bool flag[num-1];
    for(int i=0; i<num; i++){
    	cin >> str;
    	for(int j=0; j<str.length();j++){
    		if(str[j] == '{' || str[j] == '[' || str[j] =='('){
    			bracket.push(str[j]);
    			last = bracket.top();
    			continue;
    		}
    		else{
    			if(bracket.empty()==true){
    				bracket.push(str[j]);
    				break;
    			}
                else{
        			last = bracket.top();
        			switch(str[j]){
        				case '}':{
        					if(last!='{'){
        						break;
        					}
        					bracket.pop();
        					break;
        				}
        				case ']':{
        					if(last!='['){
        						break;
        					}
        					bracket.pop();
        					break;
        				}	
        				case ')':{
        					if(last!='('){
        						break;
        					}
        					bracket.pop();
        					break;
        				}
                    }
                }
    		}
    	}
    	if(bracket.empty()==true){
			flag[i]=1;
		}
		else{
			flag[i]=0;
		}
    }
    for(int k=0 ; k<num ; k++){
    	if(flag[k]==1){
    		cout <<"yes"<<endl;
    	}
    	else{
    		cout <<"no"<<endl;
    	}
    }
    
    
    
    return 0;
}