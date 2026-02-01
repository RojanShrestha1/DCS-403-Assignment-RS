#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter how many elements: ";
    cin >> n;

    int arr[100]; // Assuming a max size of 100
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0]; // Assume first is max
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if current element is bigger
        }
    }

    cout << "Maximum element is: " << max << endl;
    return 0;
}