#include <iostream>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    queue<int> q;
    int count,num;
    std::vector<int> countvec;
    std::vector<int> numvec;
    cin >>count;
    for(int i =0; i<count ; i++){
    	cin >> num;
    	numvec.push_back(num);
    	if(num>5000){
			for(int j=5001;j<=num;j++){
				q.pop();
				q.push(j);
			}
		}
		else{
			for(int j=0; j<=num ; j++){
				if(q.empty()){
	    			q.push(j);
	    		}
	    		else{
	    			for(int k=1;k<=numvec[i]-numvec[i-1];k++){
	    				q.push(numvec[i-1]+k);
	    			}
	    			break;
	    		}
	    	}
		}
		int cal = numvec.size();
		if(num<5000){
			countvec.push_back(numvec.size());
		}
		else{
			for(int i=0;i<numvec.size();i++){
				if(numvec[i]<num-5000){
					cal =cal-1;
				}
			}
			countvec.push_back(cal);
		}
    }

    for(int i=0;i<countvec.size();i++){
    	cout <<countvec[i]<<" ";
    }

    return 0;
}