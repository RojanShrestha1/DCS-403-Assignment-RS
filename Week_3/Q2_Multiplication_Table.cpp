#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main (){


int num;

cout << "Enter a number to generate its multiplication table: ";
cin >> num;

for (int i = 1; i <= 10; i++) {
    cout << num << " x " << i << " = " << num * i << endl;
}



}