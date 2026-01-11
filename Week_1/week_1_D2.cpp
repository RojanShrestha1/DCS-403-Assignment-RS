#include <iostream>
using namespace std;

int main() {
    int baseSalary = 50000;         
    const float bonusPercent = 15;   


    float bonusAmount = baseSalary * (bonusPercent / 100);


    float totalSalary = baseSalary + bonusAmount;

    cout << "Total Salary: " << totalSalary << endl;

    return 0;
}

