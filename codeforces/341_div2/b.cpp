#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define CL(a, b) memset(a, b, sizeof(a))

const int M = 1000;
bool g[1005][1005];

int main() {
    int n;
    scanf("%d", &n);
    CL(g, false);
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x][y] = true;
    }
    ll ans = 0;
    for (int i = 1; i <= M; ++i) {
        int x = i, y = 1;
        int cnt = 0;
        while (x <= M && y <= M) {
            if (g[x][y]) ++cnt;
            ++x; ++y;
        }
        if (cnt > 1) ans += (1LL * cnt * (cnt - 1)) / 2;
    }
    for (int i = 2; i <= M; ++i) {
        int x = 1, y = i;
        int cnt = 0;
        while (x <= M && y <= M) {
            if (g[x][y]) ++cnt;
            ++x; ++y;
        }
        if (cnt > 1) ans += (1LL * cnt * (cnt - 1)) / 2;
    }
    for (int i = 1; i <= M; ++i) {
        int x = i, y = 1;
        int cnt = 0;
        while (x > 0 && y <= M) {
            if (g[x][y]) ++cnt;
            --x; ++y;
        }
        if (cnt > 1) ans += (1LL * cnt * (cnt - 1)) / 2;
    }
    for (int i = 2; i <= M; ++i) {
        int x = M, y = i;
        int cnt = 0;
        while (x > 0 && y <= M) {
            if (g[x][y]) ++cnt;
            --x; ++y;
        }
        if (cnt > 1) ans += (1LL * cnt * (cnt - 1)) / 2;
    }
    printf("%I64d\n", ans);
    return 0;
}
