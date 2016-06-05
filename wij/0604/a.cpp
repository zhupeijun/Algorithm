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
    set<string> S;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            string tmp = s;
            tmp[i] = 'a' + j;
            sort(tmp.begin(), tmp.end());
            do {
                S.insert(tmp);
            } while(next_permutation(tmp.begin(), tmp.end()));
        }
    }
    for (auto e : S) {
        cout << e << endl;
    }
    return 0;
}

