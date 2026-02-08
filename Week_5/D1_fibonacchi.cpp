// fibonacchi series using recursion
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the number of terms in the Fibonacci series: ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer greater than 0." << endl;
    } else {
        cout << "Fibonacci series up to " << n << " terms: ";
        for (int i = 0; i < n; i++) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }

    return 0;
}