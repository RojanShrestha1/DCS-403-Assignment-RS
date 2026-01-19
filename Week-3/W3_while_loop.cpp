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
while (true){
    sum += number;
    number--;
    if (number < 0){
        break;
    }
}
cout << "The sum is: " << sum << endl;
return 0;

}
