#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    int rev = 0;

    cout << "Enter a number: ";
    cin >> n;

    while (n != 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }

    cout << "Reversed number = " << rev << endl;

    return 0;
}
