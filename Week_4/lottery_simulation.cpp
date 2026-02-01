#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(0));

    int lotto[6];
    int count = 0;


    while (count < 6) {
        int randomNumber = (rand() % 49) + 1;

        bool alreadyExists = false;


        for (int i = 0; i < count; i++) {
            if (lotto[i] == randomNumber) {
                alreadyExists = true; 
                break; 
            }
        }

        if (!alreadyExists) {
            lotto[count] = randomNumber;
            count++;
        }
    }


    cout << "Lottery Draw Results: " << endl;
    for (int i = 0; i < 6; i++) {
        cout << "[" << lotto[i] << "] ";
    }

    return 0;
}