#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;   // long long for bigger values

    cout << "Enter a non-negative integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }
        cout << "Factorial of " << n << " = " << fact << endl;
    }

    return 0;
}
