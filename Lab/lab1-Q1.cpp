#include <iostream>

using namespace std;

int add(int n1,int n2){
	return n1+n2;
}

void sub(int *n1,int *n2,int *value){
	*value = *n1-*n2;
}

void mul(int n1,int n2,int &value){
	value = n1*n2;
}

void div(int *n1,int n2 ,int &value){
	value = *n1/n2;
}

int main() {
  int num1;
  int num2;
  
  cin >> num1 >> num2;
  
  int value = 0;
  value = add(num1, num2);
  cout << value << " ";
  sub(&num1, &num2, &value);
  cout << value << " ";
  mul(num1, num2, value);
  cout << value << " ";
  div(&num1, num2, value);
  cout << value << endl;
  return 0;
}