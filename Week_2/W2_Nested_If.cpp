#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num > 0) {
        if (num % 2 == 0) {
            cout << "Positive and Even";
        } else {
            cout << "Positive and Odd";
        }
    } else if (num < 0) {
        cout << "Negative";
    } else {
        cout << "Zero";
    }

    return 0;
}
