
#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

void increment (int num) {

    num++;
    cout << "Inside increment function: " << num << endl;


}

int main (){

int x = 5;
increment(x);
cout << "Inside main function: " << x << endl;

}