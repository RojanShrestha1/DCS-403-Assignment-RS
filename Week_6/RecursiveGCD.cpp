#include <iostream>
using namespace std;


int gcd(int m, int n) {
    if (n == 0) return m;         
    if (m % n == 0) return n;
    return gcd(n, m % n);
}

int main() {
    cout << "gcd(24, 16) = " << gcd(24, 16) << endl;
    cout << "gcd(255, 25) = " << gcd(255, 25) << endl;
    return 0;
}
