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

char s[50005];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    int bf_num = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ++bf_num;
        }
    }
    int min_leap = bf_num + 1;
    int max_leap = bf_num * 2;

    if (n - 1 >= min_leap && n - 1 <= max_leap) {
        printf("Y\n");
    } else {
        printf("N\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

