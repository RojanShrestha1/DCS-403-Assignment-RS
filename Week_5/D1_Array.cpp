#include <iostream>
using namespace std;

void printArray(int arr[], int n, int i) {
    if (i == n) return;
    cout << arr[i] << " ";
    printArray(arr, n, i + 1);
}

int main() {
    int n;
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    printArray(arr, n, 0);
    cout << endl;
    return 0;
}
