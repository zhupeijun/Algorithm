#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    string num;
    cin >> num;
    int size = num.size();
    string a, b;
    for (int i = 0; i < size; ++i) {
        if (num[i] == '4') {
            a += '3';
            b += '1';
        } else {
            a += num[i];
            if (!b.empty()) b += '0';
        }
    }
    cout << a << " " << b << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

