#include <iostream>
using namespace std;

int main() {
    int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += mat[i][j];
        }
        cout << "Row " << i + 1 << " Sum: " << rowSum << endl;
    }


    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += mat[i][j];
        }
        cout << "Column " << j + 1 << " Sum: " << colSum << endl;
    }

    return 0;
}