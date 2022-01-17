#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    Student(string n);
    string name;
    int exam_scores[4];  
    int get_minimum_final_score();
    void print_name_and_score();
};

int main() {
    
    string student_name;
    cin >> student_name;
    Student student(student_name);
    for(int i = 0; i < 3; i++){
        cin >> student.exam_scores[i];
    }
    student.get_minimum_final_score();
    student.print_name_and_score();
    return 0;
}

Student::Student(string n){
    name = n;
}

int Student::get_minimum_final_score(){
    return 240-exam_scores[0]-exam_scores[1]-exam_scores[2];
}

void Student::print_name_and_score(){
    int score;
    score = get_minimum_final_score();
    if (score <= 0)
        score = 0;
    cout << name <<" "<<score <<endl;
}