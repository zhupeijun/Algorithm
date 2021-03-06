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

int a[1005];

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    while (M--) {
        int l, r;
        double ans = 0;
        scanf("%d %d", &l, &r);
        for (int j = l; j <= r; ++j) {
            ans += log(a[j]);
        }
        ans /= (r - l + 1);
        printf("%.9lf\n", exp(ans));
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}

