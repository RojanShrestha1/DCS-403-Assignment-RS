#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int main (){

      srand(time(0)); 

    for (int i = 0; i < 5; i++) {
        char letter = 'A' + (rand() % 26);
        cout << "Random letter: '" << letter << "' with ASCII value: " << (int)letter << endl;
    }

} 