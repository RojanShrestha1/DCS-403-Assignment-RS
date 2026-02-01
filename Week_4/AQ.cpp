

#include <iostream>
using namespace std;


double min(double array[], int size);

int main() {
    double numbers[10];

  
    cout << "Enter ten numbers: ";
    for (int i = 0; i < 10; i++) {
        cin >> numbers[i];
    }

   
    double minValue = min(numbers, 10);
    
    cout << "The minimum value is: " << minValue << endl;

    return 0;
}


double min(double array[], int size) {
    double currentMin = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < currentMin) {
            currentMin = array[i];
        }
    }
    return currentMin;
}