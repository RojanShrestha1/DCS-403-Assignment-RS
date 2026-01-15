#include <iostream>
using namespace std;

int main() {

    int marks;
    char grade;

    cout << "Enter marks: ";
    cin >> marks;

    if (marks >= 90)
        grade = 'A';
    else if (marks >= 80)
        grade = 'B';
    else if (marks >= 70)
        grade = 'C';
    else if (marks >= 60)
        grade = 'D';
    else
        grade = 'F';

    switch (grade) {
        case 'A':
            cout << "Grade A";
            break;
        case 'B':
            cout << "Grade B";
            break;
        case 'C':
            cout << "Grade C";
            break;
        case 'D':
            cout << "Grade D";
            break;
        default:
            cout << "Fail";
    }

    return 0;
}
