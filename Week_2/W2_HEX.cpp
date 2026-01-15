#include <iostream>
using namespace std;

int main() {
    char hex;
    int decimal;

    cout << "Enter a hexadecimal digit (0-9 or A-F): ";
    cin >> hex;

    if (hex >= '0' && hex <= '9') {
        decimal = hex - '0';
    }
    else if (hex >= 'A' && hex <= 'F') {
        decimal = hex - 'A' + 10;
    }
    else {
        cout << "Invalid hexadecimal digit";
        return 0;
    }

    cout << "Decimal equivalent: " << decimal;
    return 0;
}
