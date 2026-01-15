#include <iostream>
using namespace std; 
#include <cstdlib>  
#include <ctime>    

using std::cout;
using std::cin;
using std::endl;

int main() {

    srand(time(0)); 

    for (int i = 0; i < 5; i++) {
        int number = rand() % 10; 
        cout << "Random number between 0 and 9: " << number << endl;
    }

    return 0;
}