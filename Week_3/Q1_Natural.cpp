#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;


int main(){

int N;
int sum = 0;

cout << "Enter a natural number: ";
cin >> N;

for (int i = 1; i <= N; i++) {
    sum += i;
}

cout << "Sum of natural numbers from 1 to " << N << " is: " << sum << endl; 


}