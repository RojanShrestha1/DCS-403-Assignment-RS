#include <iostream>
using std::cout;
using std::cin;
int main() {
    int FirstNumber, SecondNumber;
    cout << "Enter two numbers: ";
    cin >> FirstNumber >> SecondNumber;
    if (FirstNumber > SecondNumber) {
        cout << FirstNumber << " is greater than " << SecondNumber << std::endl;
    } else if (SecondNumber > FirstNumber) {
        cout << SecondNumber << " is greater than " << FirstNumber << std::endl;
    } else {
        cout << "Both numbers are equal." << std::endl;
    }
    return 0;
}