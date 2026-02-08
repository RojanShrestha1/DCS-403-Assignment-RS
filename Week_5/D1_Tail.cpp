#include <iostream>
using namespace std;

long long powerTail(int a, int b, long long result) {
    if (b == 0) return result;
    return powerTail(a, b - 1, result * a);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << powerTail(a, b, 1) << endl;  // newline added
    return 0;
}
