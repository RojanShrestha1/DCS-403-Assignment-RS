#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {                // row from n down to 1
        // spaces increase
        for (int s = 1; s <= n - i; s++) {
            cout << " ";
        }
        // stars decrease
        for (int star = 1; star <= 2 * i - 1; star++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
