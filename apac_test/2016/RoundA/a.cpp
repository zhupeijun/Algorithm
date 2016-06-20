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

void solve() {
    ll cur;
    scanf("%lld", &cur);
    ll bit = 0;
    while (cur > 1) {
        ll r = 1;
        while (r * 2 + 1 < cur) r = r * 2 + 1;
        r = r * 2 + 1;
        if (cur == r / 2 + 1) {
            printf("%lld\n", 0 ^ bit);
            return;
        }
        cur = r - cur + 1;
        bit ^= 1;
    }
    printf("%lld\n", 0 ^ bit);
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

