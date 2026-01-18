#include <iostream>
using namespace std;

int main() {
    double radius;
    cout << "Enter radius: ";
    cin >> radius;

    if (radius > 0) {
        double area = 3.14159 * radius * radius;  // π * r^2
        cout << "Area of the circle: " << area << endl;
    } else {
        cout << "Radius must be positive." << endl;
    }

    return 0;
}
