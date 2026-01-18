#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float weight, height, bmi;

    cout << "Enter your weight (kg): ";
    cin >> weight;

    cout << "Enter your height (m): ";
    cin >> height;

    bmi = weight / (height * height);

    cout << fixed << setprecision(2);
    cout << "Your BMI is: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "Category: Underweight";
    } else if (bmi < 25.0) {
        cout << "Category: Normal weight";
    } else if (bmi < 30.0) {
        cout << "Category: Overweight";
    } else {
        cout << "Category: Obesity";
    }

    return 0;
}
