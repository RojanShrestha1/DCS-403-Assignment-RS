#include <iostream>
using namespace std;

// Function to calculate sum
int getSum(int myArr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += myArr[i];
    }
    return sum;
}

int main() {
    int data[] = {10, 20, 30, 40, 50};
    int total = getSum(data, 5);
    
    cout << "The total sum is: " << total << endl;
    return 0;
}