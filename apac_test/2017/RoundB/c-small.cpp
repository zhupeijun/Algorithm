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
#include <list>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

struct Interval {
    ll x, y;

    bool operator < (const Interval& other) const {
        if (x == other.x) return y < other.y;
        else return x < other.x;
    }
};

Interval intv[1005];

void solve() {
    ll n, l1, r1, a, b, c1, c2, M;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &l1, &r1, &a, &b, &c1, &c2, &M);
    ll x = l1, y = r1;
    for (int i = 0; i < n; ++i) {
        intv[i].x = min(x, y);
        intv[i].y = max(x, y);
        ll tx = (a * x + b * y + c1) % M;
        ll ty = (a * y + b * x + c2) % M;
        x = tx;
        y = ty;
    }

    sort(intv, intv + n);

    ll ans = -1;
    bool e = false;
    for (int i = 0; i < n; ++i) {
        ll total = 0, tail = -1;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (intv[j].x > tail) {
                total += intv[j].y - intv[j].x + 1;
                tail = intv[j].y;
            } else {
                if (intv[j].y > tail) {
                    total += intv[j].y - tail;
                    tail = intv[j].y;
                }
            }
        }
        if (ans == -1) ans = total;
        else ans = min(ans, total);
    }
    printf("%lld", ans);
}

int main() {
    int cn;
    scanf("%d", &cn);
    for (int ci = 1; ci <= cn; ++ci) {
        printf("Case #%d: ", ci);
        solve();
        printf("\n");
    }
    return 0;
}

