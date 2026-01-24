#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

int main(){

cout <<"enter a numer to find summ up to number: ";
int number;
cin >> number;
int sum = 0; 
int i;

for(i =1; i<=number; i++){
    sum = sum + i;
}

cout << "The sum is: " << sum << endl;
return 0;


}