#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Student {
public:
    Student(){
        
    }
	Student(string fname,string lname,string dorm,string id) { 
        first_name = fname;
        last_name = lname;
        dormitory = dorm;
        ID = id;
    }
	string generate_address(){
        string sentence;
        sentence ="1001 University Road, Hsinchu, Taiwan 300, ROC, dorm "+this->dormitory+", ("+this->ID+") "+this->first_name+" "+this->last_name;
        return sentence;
    }
	//Please implement the remain class
private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    Student mStudent(a, b, c, d);
  	cout << mStudent.generate_address() << endl;
    return 0;
}
