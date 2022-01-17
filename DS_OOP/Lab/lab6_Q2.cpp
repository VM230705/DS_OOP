#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	vector<int> v;
  	v.reserve(50);
  	int query,num;
  	char option;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    cin >> query ;
    for (int i =0; i<query ;i++){
    	cin >> option;

    	switch(option){ 
    		
    		case'a':{
    			cin >> num;
    			v.push_back(num);
    			break;
    		}
    		
    		case'e':{
    			cin >> num;
    			for(int j=0;j<i;j++){
    				if(v[j]==num){
    					v.erase(v.begin()+j);
    				}
    			}
    			break;
    		}
    		
    		case'r':{
    			reverse(v.begin(),v.end());
    			break;
    		}

    		case'd':{
    			reverse(v.begin(),v.end());
    			v.erase(v.begin());
    			reverse(v.begin(),v.end());
    			break;
    		}

    		case's':{
    			cout << v.size() << " ";
    			break;
    		}

    		case'p':{
    			for(int k=0;k<v.size();k++){
    				cout << v[k] << " ";
    			}
    			break;
    		}
    	}
    } 
    return 0;
}