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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int step = s.size();
    for (int i = 0; i < step; ++i) {
        s[i] = s[i] == 'S' ? 'E' : 'S';
    }
    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}


