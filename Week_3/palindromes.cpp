#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;


int main(){

int number;
cout << "Enter a number to check if it's a palindrome: ";
cin >> number;

int originalNumber = number;
int reversedNumber = 0;

while (number != 0) {
    reversedNumber = reversedNumber * 10 + number % 10;
    number /= 10;
}

if (originalNumber == reversedNumber) {
    cout << "The number is a palindrome." << endl;
} else {
    cout << "The number is not a palindrome." << endl;
}


}