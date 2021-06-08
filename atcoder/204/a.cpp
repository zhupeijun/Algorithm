#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a << endl;
    } else {
        cout << 3 - a - b << endl;
    }
    return 0;
}