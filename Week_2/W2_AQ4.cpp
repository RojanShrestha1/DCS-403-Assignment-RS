#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int score, maxScore = 0;

    for (int i = 1; i <= n; i++) {
        cout << "Enter score for student " << i << ": ";
        cin >> score;
        if (score > maxScore)
            maxScore = score;
    }

    cout << "Highest score is: " << maxScore << endl;
    return 0;
}
