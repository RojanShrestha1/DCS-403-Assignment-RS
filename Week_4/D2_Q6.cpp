#include <iostream>
using namespace std;

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int Result[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            Result[i][j] = A[i][j] + B[i][j];
            cout << Result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}