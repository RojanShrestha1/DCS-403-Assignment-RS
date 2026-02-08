#include <iostream>
#include <cstdlib> // for abs()
using namespace std;

int sumDigits(int n) {
    n = abs(n);                 // make it positive
    if (n == 0) return 0;
    return (n % 10) + sumDigits(n / 10);
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << sumDigits(n) << endl;
    return 0;
}
