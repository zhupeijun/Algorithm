#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 0; i+2 < n;++i) {
        if (s.substr(i, 3) == "ABC") {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
