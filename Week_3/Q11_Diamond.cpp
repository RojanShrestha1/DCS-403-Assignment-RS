#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

 
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    
    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }
        for (int star = 1; star <= 2 * i - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
