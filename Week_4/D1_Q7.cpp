#include <iostream>
using namespace std;

int main() {
    int arr[5] = {5, 1, 4, 2, 8};
    int n = 5;

    cout << "Original array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;


    for (int i = 0; i < n - 1; i++) {

        bool swapped = false; 
        
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = true; 
            }
        }


        if (swapped == false) {
            break;
        }
    }

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}