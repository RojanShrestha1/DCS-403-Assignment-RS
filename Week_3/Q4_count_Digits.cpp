#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int main() {
    int n;
    int count = 0;

    cout << "Enter a number: ";
    cin >> n;


    if (n == 0) {
        count = 1;
    } else {
        int temp = n;
        do {
            count++;
            temp = temp / 10;
        } while (temp != 0);
    }

    cout << "Number of digits = " << count << endl;

    return 0;
}