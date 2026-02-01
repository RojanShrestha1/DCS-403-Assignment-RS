#include <iostream>
using namespace std;

// Linear Search

int main() {
    int arr[] = {12, 45, 7, 19, 23};
    int target, foundAt = -1;

    cout << "Enter number to search: ";
    cin >> target;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == target) {
            foundAt = i;
            break; // Stop looking once found
        }
    }

    if (foundAt != -1)
        cout << "Found at index: " << foundAt << endl;
    else
        cout << "Not found." << endl;

    return 0;
}