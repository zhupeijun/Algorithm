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

int a[15];

void solve() {
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    for (int q = 0; q < M; ++q) {
        int al, ar;
        scanf("%d %d", &al, &ar);
        double l = 1, r = 1000000005;
        while (fabs(l - r) >= 1e-6) {
            double mid = (l + r) / 2.0;
            double tmp = 1;
            for (int j = al; j <= ar; ++j) {
                tmp = tmp * a[j] / mid;
            }
            if (tmp > 1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%.9lf\n", l);
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

