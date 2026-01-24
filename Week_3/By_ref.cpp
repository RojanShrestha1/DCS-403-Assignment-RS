#include <iostream>
using namespace std;


void increment (int &num) {
    num++;
    cout << "Inside increment function: " << num << endl;
}

int main () {
    int x = 5;
    increment(x); 
    cout << "Inside main function: " << x << endl;
    return 0;
}