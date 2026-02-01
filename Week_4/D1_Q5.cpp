#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int target = 10;
    int low = 0, high = 4, foundAt = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            foundAt = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1; 
        } else {
            high = mid - 1;
        }
    }

    cout << "Binary Search result: Index " << foundAt << endl;
    return 0;
}