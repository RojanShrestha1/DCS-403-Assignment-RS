
#include <iostream>

using namespace std;

using std::cout;
using std::endl;



long long fact(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}


int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Factorial is not defined for negative numbers.\n";
    } else {
        cout << "Factorial is " << fact(n)  << endl;
    }

    return 0;
}



