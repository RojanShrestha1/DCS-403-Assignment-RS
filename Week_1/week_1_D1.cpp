#include <iostream>
using namespace std;

int main() {
    float celsius = 25;        

    const float nine = 9.0;    
    const float five = 5.0;
    const float thirtyTwo = 32.0;

  
    float fahrenheit = (celsius * nine / five) + thirtyTwo;

    cout << "Fahrenheit: " << fahrenheit << endl;

    return 0;
}