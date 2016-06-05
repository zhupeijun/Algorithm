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

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    string s;
    cin >> s;
    ll l;
    cin >> l;
    map<string, ll> M;
    ll i = 0;
    vector<string> sta;
    sta.push_back(s);
    while (true) {
        char c = s[0];
        s.erase(s.begin());
        s.insert(s.begin() + c - '0' - 1, c);
        ++i;
        if (M.find(s) == M.end()) {
            M[s] = i;
        } else {
            ll cir = i - M[s];
            ll des = (l - M[s]) % cir + M[s];
            cout << sta.at(des) << endl;
            return 0;
        }
        sta.push_back(s);
        if (i == l) {
            cout << s << endl;
            return 0;
        }
    }
    return 0;
}

