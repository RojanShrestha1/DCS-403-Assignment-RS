#include <iostream>
using namespace std;
using std::cout;
using std::endl;


int recursiveSum(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n + recursiveSum(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer greater than 0." << endl;
    } else {
        cout << "The sum of integers from 1 to " << n << " is " << recursiveSum(n) << endl;
    }

    return 0;
}